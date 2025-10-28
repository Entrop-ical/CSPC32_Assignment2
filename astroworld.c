#include <stdio.h>
#include <stdlib.h>

typedef struct node {
 int val;
 struct node *left;
 struct node *right;
} node;

node* newnode(){
 node *x=(node*)malloc(sizeof(node));
 x->val=1;
 x->left=NULL;
 x->right=NULL;
 return x;
}

node* maketree(int *arr,int n){
 if(n==0||arr[0]==0)return NULL;
 node *root=newnode();
 node **q=(node**)malloc(n*sizeof(node*));
 int f=0,r=0,i=1;
 q[r++]=root;
 while(f<r&&i<n){
  node *t=q[f++];
  if(i<n&&arr[i]==1){
   t->left=newnode();
   q[r++]=t->left;
  }
  i++;
  if(i<n&&arr[i]==1){
   t->right=newnode();
   q[r++]=t->right;
  }
  i++;
 }
 free(q);
 return root;
}

int dfs(node *t,int *phones){
 if(!t)return 1;
 int l=dfs(t->left,phones);
 int r=dfs(t->right,phones);
 if(l==0||r==0){
  (*phones)++;
  return 2;
 }
 if(l==2||r==2)return 1;
 return 0;
}

int dominatingset(node *root){
 int c=0;
 if(dfs(root,&c)==0)c++;
 return c;
}

int isprime(int x){
 if(x<2)return 0;
 for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
 return 1;
}

void makeprimes(int n,int *p){
 int k=0,num=2;
 while(k<n){
  if(isprime(num)){
   p[k++]=num;
  }
  num++;
 }
}

int main(){
 int n;
 if(scanf("%d",&n)!=1)return 0;

 int *a=(int*)malloc(n*sizeof(int));
 for(int i=0;i<n;i++)scanf("%d",&a[i]);

 node *root=maketree(a,n);
 int m=dominatingset(root);

 int l,r;
 if(scanf("%d %d",&l,&r)==2){
  int *p=(int*)malloc(m*sizeof(int));
  makeprimes(m,p);
  int out=0;
  for(int i=0;i<m;i++){
   for(int j=i+1;j<m;j++){
    int x=p[i]^p[j];
    if(x<l||x>r)out++;
   }
  }
  printf("%d\n%d\n",m,out);
  free(p);
 }else{
  printf("%d\n",m);
 }

 free(a);
 return 0;
}
