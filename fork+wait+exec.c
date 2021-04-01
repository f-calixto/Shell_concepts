#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
int main(void)
{
	pid_t child;
	int status, i;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5 ; i++)
	{
		child = fork();
		if (child == -1)
		{
			printf("Error manito");
			return (1);
		}
		if (child == 0)
		{
			printf("NÂ de ejecucion: %i\n"  ,i + 1);
			execve(argv[0], argv, NULL);
			sleep(1);
		}
		else
		{
			wait(&status);
			sleep(2);
		}
	}

	return (0);
}
