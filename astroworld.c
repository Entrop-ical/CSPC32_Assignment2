#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} node;

node* createnode() {
    node *n = (node*) malloc(sizeof(node));
    n->value = 1;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node* buildtree(int *arr, int n) {
    if (n == 0 || arr[0] == 0)
        return NULL;

    node *root = createnode();
    node **queue = (node**) malloc(n * sizeof(node*));
    int front = 0, rear = 0, index = 1;

    queue[rear++] = root;

    while (front < rear && index < n) {
        node *current = queue[front++];

        if (index < n && arr[index] == 1) {
            current->left = createnode();
            queue[rear++] = current->left;
        }
        index++;

        if (index < n && arr[index] == 1) {
            current->right = createnode();
            queue[rear++] = current->right;
        }
        index++;
    }

    free(queue);
    return root;
}

int dfs(node *root, int *phones) {
    if (!root) return 1;

    int leftState = dfs(root->left, phones);
    int rightState = dfs(root->right, phones);

    if (leftState == 0 || rightState == 0) {
        (*phones)++;
        return 2;
    }

    if (leftState == 2 || rightState == 2)
        return 1;

    return 0;
}

int solution(node *root) {
    int total = 0;
    if (dfs(root, &total) == 0)
        total++;
    return total;
}

int isprime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return 0;
    return 1;
}

void primenumbers(int count, int *primes) {
    int number = 2, found = 0;
    while (found < count) {
        if (isprime(number)) {
            primes[found++] = number;
        }
        number++;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    int *levelorder = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &levelorder[i]);

    node *root = buildtree(levelorder, n);
    int m = solution(root);

    int l, r;
    if (scanf("%d %d", &l, &r) == 2) {
        int *primes = (int*) malloc(m * sizeof(int));
        primenumbers(m, primes);

        int out = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int xorValue = primes[i] ^ primes[j];
                if (xorValue < l || xorValue > r)
                    out++;
            }
        }

        printf("%d\n%d\n", m, out);
        free(primes);
    } else {
        printf("%d\n", m);
    }

    free(levelorder);
    return 0;
}
