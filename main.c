#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "platform.h"

int main(){
 platform *pf=createplatform();
 char cmd[50];
 while(1){
  if(scanf("%s",cmd)==EOF)break;

  if(strcmp(cmd,"create")==0){
   scanf("%s",cmd);
   if(strcmp(cmd,"platform")==0)pf=createplatform();
  }

  else if(strcmp(cmd,"add")==0){
   scanf("%s",cmd);
   if(strcmp(cmd,"post")==0){
    char u[50],cap[200];
    scanf("%s",u); getchar();
    scanf("%[^\n]",cap);
    addpost(u,cap);
   }
   else if(strcmp(cmd,"comment")==0){
    char u[50],text[200];
    scanf("%s",u); getchar();
    scanf("%[^\n]",text);
    addcomment(u,text);
   }
   else if(strcmp(cmd,"reply")==0){
    char u[50],text[200]; int n;
    scanf("%s",u); getchar();
    scanf("%[^\n]",text);
    scanf("%d",&n);
    addreply(u,text,n);
   }
  }

  else if(strcmp(cmd,"view")==0){
   scanf("%s",cmd);
   if(strcmp(cmd,"post")==0){
    int n; scanf("%d",&n);
    post *x=viewpost(n);
    if(x)printf("%s %s\n",x->username,x->caption);
    else printf("post not found\n");
   }
   else if(strcmp(cmd,"comments")==0){
    comment *c=viewcomments();
    while(c){
     printf("%s %s\n",c->username,c->content);
     reply *r=c->replies;
     while(r){
      printf("%s %s\n",r->username,r->content);
      r=r->next;
     }
     c=c->next;
    }
   }
  }

  else if(strcmp(cmd,"delete")==0){
   scanf("%s",cmd);
   if(strcmp(cmd,"post")==0){
    int n; scanf("%d",&n);
    deletepost(n);
   }
   else if(strcmp(cmd,"comment")==0){
    int n; scanf("%d",&n);
    deletecomment(n);
   }
   else if(strcmp(cmd,"reply")==0){
    int n,m; scanf("%d %d",&n,&m);
    deletereply(n,m);
   }
  }

  else if(strcmp(cmd,"exit")==0)break;
 }

 return 0;
}
