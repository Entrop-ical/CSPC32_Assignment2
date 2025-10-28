#ifndef PLATFORM_H
#define PLATFORM_H
#include "post.h"

typedef struct platform {
 post *posts;
 post *last;
} platform;

platform* createplatform();
void addpost(char *user,char *cap);
void viewposts();
void addcomment(char *user,char *text,int n);
void addreply(char *user,char *text,int pn,int cn);
void viewcomments(int n);
void deletepost(int n);

#endif
