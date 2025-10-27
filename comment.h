#ifndef COMMENT_H
#define COMMENT_H
#include "reply.h"

typedef struct comment {
 char username[50];
 char content[200];
 struct reply *replies;
 struct comment *next;
} comment;

comment* createcomment(char *user,char *text);

#endif
