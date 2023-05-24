#ifndef MAIN_H
#define MAIN_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define CLEAR_SCREEN "\033[1;1H\033[2J\0"

/*extern char prev_dir[1025];*/


int read_lin2(char *tks[]);
int cd_handler(char *tks[], char cwdd[]);
void s_u_env_handler(char *tks[]);
void exit_handler(char *tks[]);
int _strncmp(const char *str1, const char *str2, size_t n);
int _atoi(char *s);
char * fgett(char *buffer, int buffersize, FILE *stream);
extern char **environ;
int _putchar(char c);
ssize_t _get_line(char **lineptr, size_t *n, FILE *stream);
int read_lin(char *tks[]);
void lsss_handler(char *pts[], char *tks[], int k, int state);
void _slit_str(char *s, char *part1, char *part2, char delim);
int _strcom(const char *str1, const char *str2);
char *_getenv(const char *name);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strchr(char *str, int n);
int ls_handler(int argc, char **argv);
void prompt(void);
int slas_bin_handler(int argc, char **argv);
void env_handler(char * const* tks);
char *_strtok(char *str, const char *delim);
char *_strdup(char *str);


#endif
