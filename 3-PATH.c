#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "_getenv.c"

char **findpath(int *len)
{
	int j = 0, i;
	char *path;
	char **res;
	char *word;
	
	path = _getenv("PATH");
	/*printf("%s\n", path);*/
	res = malloc(sizeof(char *) * 20);
	word = strtok(path, ":="); 
        while (word)
        {
                res[j] = word;
                word = strtok(NULL, ":=");
                j++;
        }
	*len = j;
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
	test = findpath(&pichu);
	for (pichu = 1;test[pichu] != '\0';pichu++)
	{
		printf("%s\n",test[pichu]);
	}	

	return (0);
}

