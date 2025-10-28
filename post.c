#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "post.h"

post* createpost(char *user,char *cap){
 post *x=(post*)malloc(sizeof(post));
 if(!x)return NULL;
 strcpy(x->username,user);
 strcpy(x->caption,cap);
 x->comments=NULL;
 x->next=NULL;
 return x;
}
