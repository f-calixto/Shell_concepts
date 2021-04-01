#include <stdio.h>
int main(int ac, char **av)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	int i;

	printf("$ ");
	getline(&line, &len, stdin);
	printf("%s",line);
	return (0);
}
