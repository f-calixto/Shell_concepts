#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/**
 * main - stat example
 *
 * Return: Always 0.
 */

int main(int ac, char *av[])
{
	int i, j;
	char *paths[4] = {"/usr/bin", "/usr", "/bin", NULL};
	struct stat st;
	char p[1024];

	if (ac < 2)
		return (-1);
	//paths[] = separate_paths();
	for (j = 0; j < (ac - 1); j++)
	{
		for (i = 0; paths[i]; i++)
		{
			strcpy(p, paths[i]);
			strcat(p, "/");
			strcat(p, av[j + 1]);
			if (stat(p, &st) == 0)
			{
				printf("%s\n", p);
			}
		}
	}
	return (0);
}
