#ifndef REPLY_H
#define REPLY_H

typedef struct reply {
 char username[50];
 char content[200];
 struct reply *next;
} reply;

reply* createreply(char *user,char *text);

#endif
