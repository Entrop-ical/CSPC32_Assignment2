#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "platform.h"

static platform p;

platform* createplatform(){
 p.posts=NULL;
 p.last=NULL;
 return &p;
}

void addpost(char *user,char *cap){
 post *x=createpost(user,cap);
 if(!x)return;
 if(p.posts==NULL)p.posts=x;
 else{
  post *t=p.posts;
  while(t->next)t=t->next;
  t->next=x;
 }
}

void viewposts(){
 post *t=p.posts; int i=1;
 while(t){
  printf("%d. %s : %s\n",i++,t->username,t->caption);
  t=t->next;
 }
}

void addcomment(char *user,char *text,int n){
 post *t=p.posts; int k=1;
 while(t&&k<n){t=t->next;k++;}
 if(!t)return;
 comment *c=createcomment(user,text);
 if(!t->comments)t->comments=c;
 else{
  comment *y=t->comments;
  while(y->next)y=y->next;
  y->next=c;
 }
}

void viewcomments(int n){
 post *t=p.posts; int k=1;
 while(t&&k<n){t=t->next;k++;}
 if(!t){printf("no such post\n");return;}
 comment *c=t->comments; int i=1;
 while(c){
  printf("   %d. %s : %s\n",i++,c->username,c->content);
  reply *r=c->replies; int j=1;
  while(r){
   printf("       (%d.%d) %s : %s\n",i-1,j++,r->username,r->content);
   r=r->next;
  }
  c=c->next;
 }
}

void addreply(char *user,char *text,int pn,int cn){
 post *t=p.posts; int k=1;
 while(t&&k<pn){t=t->next;k++;}
 if(!t)return;
 comment *c=t->comments; int i=1;
 while(c&&i<cn){c=c->next;i++;}
 if(!c)return;
 reply *r=createreply(user,text);
 if(!c->replies)c->replies=r;
 else{
  reply *x=c->replies;
  while(x->next)x=x->next;
  x->next=r;
 }
}

void deletepost(int n){
 post *t=p.posts,*prev=NULL; int k=1;
 while(t&&k<n){prev=t;t=t->next;k++;}
 if(!t)return;
 if(prev==NULL)p.posts=t->next;
 else prev->next=t->next;
 free(t);
}
