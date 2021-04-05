#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "_getenv.c"

int count_dirs(char *path)
{
	int count = 3, i = 0; /* Count es 3 por PATH , la primer carpeta, y nulo*/
	for(i = 0 ; path[i] != '\0' ; i++)
	{
		if (path[i] == ':')
			count++;
	}
	return (count);
}


char **findpath(void)
{
	int j = 0, i, size = 0;
	char *path;
	char **res;
	char *word;

	path = _getenv("PATH");
	/*printf("%s\n", path);*/
	size = count_dirs(path);
	printf("%i\n",size);
	res = malloc(sizeof(char *) * (size));
	if (!res)
	{
		return;
	}
	word = strtok(path, ":="); 
        while (word)
        {
                res[j] = word;
                word = strtok(NULL, ":=");
                j++;
        }
	res[j] = NULL;
	
	return (res);
}




/**
 * main - stat example
 *
 * Return: Always 0.
 */

int main(void)
{
	int pichu = 0;
	char **test;

	//paths[] = separate_paths();
	test = findpath();
	for (pichu = 0;test[pichu] != '\0';pichu++)
	{
		printf("%s\n",test[pichu]);
	}
	free(test);
	return (0);
}

