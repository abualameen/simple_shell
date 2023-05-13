#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>



int main(int ac, char **av)
{
	int i;
	char **aav;
	pid_t pid;
	aav = av;

	while(1)
	{
		printf("$ ");
		fflush(stdout);
		pid = fork();
		if (pid == 0)
		{
			while (*aav)
			{
				printf("%s\n", *aav);
				aav++;
			}
		}
		wait(NULL);
	}
	return (0);
}
