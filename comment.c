#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comment.h"

comment* createcomment(char *user,char *text){
 comment *c=(comment*)malloc(sizeof(comment));
 strcpy(c->username,user);
 strcpy(c->content,text);
 c->replies=NULL;
 c->next=NULL;
 return c;
}
