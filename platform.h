#ifndef PLATFORM_H
#define PLATFORM_H
#include "post.h"

typedef struct platform {
 post *posts;
 post *last;
} platform;

platform* createplatform();
int addpost(char *user,char *cap);
int deletepost(int n);
post* viewpost(int n);
post* currpost();
int addcomment(char *user,char *text);
int deletecomment(int n);
comment* viewcomments();
int addreply(char *user,char *text,int n);
int deletereply(int n,int m);

#endif
