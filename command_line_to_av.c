#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int ac, char **av)
{
	char *line;
	size_t len, i = 0, j = 0;
	char **res;
	char *word;

	line = av[1];
	len = strlen(line);
	res = malloc(sizeof(char *) * len);
	word = strtok(line, " ");
	while (word)
	{
		res[j] = word;
		word = strtok(NULL, " ");
		j++;
	}
	for (i = 0; i<j; i++)
	{
		printf("%s\n", res[i]);
	}
	return (0);
}
