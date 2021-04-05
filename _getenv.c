#include <stdio.h>
#include <unistd.h>
#include <string.h>

char *_getenv(const char *name)
{
	int i = 0, j = 0;
	extern char **environ;
	char *word;

	for (i = 0; environ[i] != '\0'; i++)
	{
			word = environ[i];
			for (j = 0; name[j] != '\0'; j++)
			{
				if (name[j] != word[j])
					break;
			}
			if ((name[j] == '\0') && (word[j] == '='))
				return (word);
	}
	return NULL;
}

/*int main(int ac, char **argv)
{
	char *res;
	if (ac != 2)
		return (1);

	res = _getenv(argv[1]);
	if (res)
		printf("%s\n", res);
	else
		printf("No se encontro nada wachin\n");
	return (0);
}*/
