#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char *const argv[] = {"/bin/ls", NULL};
	int t;
	int g;
	pid_t pid;

	for (g = 0; g < 5; g++)
	{
		pid = fork();	
		if (pid == -1)
		{
			perror("error");
			return (-1);
		}
		else if (pid == 0)
		{
			t = execve(argv[0], argv, NULL);
			perror("erorr with execv");
			return (-1);
		}
		else
		{
			wait(NULL);
		}
	}
	printf("parent waiting");
	return (0);
}
