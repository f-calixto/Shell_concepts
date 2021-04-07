#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (void)
{
	char origen[45] = ".:hola:hello:xd";
	char *dest = malloc(sizeof(char *));
	char *ja = NULL;

	dest = strtok(origen, ":");
	while (dest)
	{
		printf("%s\n", "");
		printf("%p\n", dest);
		dest = strtok(NULL, ":");
	}
	return 0;
}
