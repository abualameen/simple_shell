#ifndef _FILE_NAME_H_
#define _FILE_NAME_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *_strcat(char *dest, char *src, char *newstr);
char *pathfinder(char **ptr, char *storage, char *command);
int checkstat(char *command);
char *_strcpy(char *dest, char *src);
int execution(char *cpy, int arguments);
char *_getenv(const char *name);
void forknow(char *argument, char **arguments, int index);

extern char **environ;

#endif
