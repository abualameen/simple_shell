#ifndef MAIN_H
#define MAIN_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>




void _slit_str(char *s, char *part1, char *part2, char delim);
char *_getenv(const char *name);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);



#endif
