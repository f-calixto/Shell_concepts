#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
char *parser(char *str)
{
        size_t len, i = 0, j = 0;
        char **res;
        char *word;

        len = strlen(str);
        res = malloc(sizeof(char *) * len);
        word = strtok(str, " \n");
        while (word)
        {
                res[j] = word;
                word = strtok(NULL, " \n");
                j++;
        }
	return (res[0]);
}
int main(void)
{
	pid_t child;
	int status;
	size_t len = 0, pichu = 0; 
	char *argv[2];
	char *line = NULL;
	

	while(1 == 1)
	{
		printf("#cisNOTfun$ ");
		pichu = getline(&line, &len, stdin);
		/*printf("%lu\n",pichu);*/
		argv[0] = parser(line);
		argv[1] = NULL;
		child = fork();
		if (child == -1)
			return (1);
		if (child == 0)
		{
			/*printf("Hijo PA\n");*/
			execve(argv[0], argv, NULL);
			sleep(1);
		}
		else
		{
			/*printf("PadrePA\n");*/
			wait(&status);
			sleep(1);
		}
	}
	return (0);
}
