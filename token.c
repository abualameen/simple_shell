#include <stddef.h>
#include <stdio.h>
#include <string.h>



int main(void)
{
	char str[] = "ALLAH IS THE GREATEST!!!";
	const char *delim;
	char *t_ken;

	delim = " ";
	t_ken = strtok(str, delim);
	while (t_ken != NULL)
	{
		printf("%s\n", t_ken);
		t_ken = strtok(NULL, delim);
	}
	return (0);
}
