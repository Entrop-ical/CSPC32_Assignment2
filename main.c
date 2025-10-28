#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "platform.h"

int main(){
 platform *pf=NULL;
 int choice=0;

 while(1){
  printf("\n1 create platform\n2 add post\n3 view posts\n4 add comment\n5 add reply\n6 view comments\n7 delete post\n8 exit\nchoice: ");
  if(scanf("%d",&choice)!=1)break;
  if(choice==1){
   pf=createplatform();
   printf("platform created\n");
  }
  else if(choice==2){
   char u[50],c[200];
   printf("username: "); scanf("%s",u);
   printf("caption: "); getchar(); scanf("%[^\n]",c);
   addpost(u,c);
  }
  else if(choice==3){
   viewposts();
  }
  else if(choice==4){
   int n; char u[50],t[200];
   printf("post number: "); scanf("%d",&n);
   printf("username: "); scanf("%s",u);
   printf("comment: "); getchar(); scanf("%[^\n]",t);
   addcomment(u,t,n);
  }
  else if(choice==5){
   int pn,cn; char u[50],t[200];
   printf("post number: "); scanf("%d",&pn);
   printf("comment number: "); scanf("%d",&cn);
   printf("username: "); scanf("%s",u);
   printf("reply: "); getchar(); scanf("%[^\n]",t);
   addreply(u,t,pn,cn);
  }
  else if(choice==6){
   int n; printf("post number: "); scanf("%d",&n);
   viewcomments(n);
  }
  else if(choice==7){
   int n; printf("post number: "); scanf("%d",&n);
   deletepost(n);
  }
  else if(choice==8)break;
 }
 return 0;
}
