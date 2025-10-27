#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reply.h"

reply* createreply(char *user,char *text){
 reply *r=(reply*)malloc(sizeof(reply));
 strcpy(r->username,user);
 strcpy(r->content,text);
 r->next=NULL;
 return r;
}
