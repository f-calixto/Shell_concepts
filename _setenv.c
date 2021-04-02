#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "_getenv.c"
int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0, j = 0;
	extern char **environ;
	char *new_val;

	for (i = 0; environ[i] != '\0'; i++)
	{
			char *word = environ[i];
			for (j = 0; name[j] != '\0'; j++)
			{
				if (name[j] != word[j])
					break;
			}
			if ((name[j] == '\0') && (word[j] == '='))
			{
				if(overwrite != 0)
				{
					new_val = malloc(sizeof(char *));
					if(!new_val)
						return (-1);
					strcat(new_val, name);
					strcat(new_val, "=");
					strcat(new_val, value);
					environ[i] = new_val;
					return 0;
				}
				else
					return (0);
			}
	}
	if (environ[i] == '\0')
	{
		new_val = malloc(sizeof(char *));
                if(!new_val)
			return (-1);
		strcat(new_val, name);
		strcat(new_val, "=");
		strcat(new_val, value);
		environ[i] = new_val;
		environ[i + 1] = '\0';
	}
	return 0;
}

int main(int ac, char **argv)
{
	char *r;
	if (ac != 4)
		return (1);
	r = _getenv(argv[1]);
	if(!r)
		printf("No se encontro pa\n");
	else
		printf("%s\n", r);

	 _setenv(argv[1], argv[2], atoi(argv[3]));
	r = _getenv(argv[1]);
        if(!r)
                printf("No se encontro pa\n");
        else
                printf("%s\n", r);
	return (0);
}
