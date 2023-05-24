#ifndef _FILE_NAME_H_
#define _FILE_NAME_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *_strcpy(char *dest, char *src);
int execution(char *cpy);
int _putchar(char c);
int checkstat(char *command);
void forknow(char *argument, char **arguments);
char *pathfinder(char **ptr, char *storage, char *command);
char *_getenv(const char *name);
char *_strcat(char *dest, char *src, char *newstr);

extern char **environ;

#endif
