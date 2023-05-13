#include <stdio.h>
#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	ssize_t num_read;
	char *line = NULL;
	size_t len = 0;


	
	printf("$ ");
	num_read = getline(&line, &len, stdin);
	printf("I entered: %sthe buffer size is %zd and the number of read is %zd\n",line, len, num_read);
	free(line);
	return (0);
	
}
