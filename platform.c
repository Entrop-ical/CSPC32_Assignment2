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

int addpost(char *user,char *cap){
 post *x=createpost(user,cap);
 if(!x)return 0;
 if(p.posts==NULL)p.posts=x;
 else{
  post *t=p.posts;
  while(t->next)t=t->next;
  t->next=x;
 }
 p.last=x;
 return 1;
}

int deletepost(int n){
 if(!p.posts)return 0;
 post *t=p.posts,*prev=NULL;
 int k=1;
 while(t&&k<n){prev=t;t=t->next;k++;}
 if(!t)return 0;
 if(prev==NULL)p.posts=t->next;
 else prev->next=t->next;
 free(t);
 return 1;
}

post* viewpost(int n){
 post *t=p.posts; int k=1;
 while(t&&k<n){t=t->next;k++;}
 if(!t)return NULL;
 p.last=t;
 return t;
}

post* currpost(){ return p.last; }

int addcomment(char *user,char *text){
 if(!p.last)return 0;
 comment *c=createcomment(user,text);
 if(!c)return 0;
 if(p.last->comments==NULL)p.last->comments=c;
 else{
  comment *t=p.last->comments;
  while(t->next)t=t->next;
  t->next=c;
 }
 return 1;
}

int deletecomment(int n){
 if(!p.last||!p.last->comments)return 0;
 comment *t=p.last->comments,*prev=NULL;
 int k=1;
 while(t&&k<n){prev=t;t=t->next;k++;}
 if(!t)return 0;
 if(prev==NULL)p.last->comments=t->next;
 else prev->next=t->next;
 free(t);
 return 1;
}

comment* viewcomments(){
 if(!p.last)return NULL;
 return p.last->comments;
}

int addreply(char *user,char *text,int n){
 if(!p.last||!p.last->comments)return 0;
 comment *t=p.last->comments; int k=1;
 while(t&&k<n){t=t->next;k++;}
 if(!t)return 0;
 reply *r=createreply(user,text);
 if(!t->replies)t->replies=r;
 else{
  reply *x=t->replies;
  while(x->next)x=x->next;
  x->next=r;
 }
 return 1;
}

int deletereply(int n,int m){
 if(!p.last||!p.last->comments)return 0;
 comment *t=p.last->comments; int k=1;
 while(t&&k<n){t=t->next;k++;}
 if(!t||!t->replies)return 0;
 reply *r=t->replies,*prev=NULL;
 int c=1;
 while(r&&c<m){prev=r;r=r->next;c++;}
 if(!r)return 0;
 if(prev==NULL)t->replies=r->next;
 else prev->next=r->next;
 free(r);
 return 1;
}
