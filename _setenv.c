#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "_getenv.c"
int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0, j = 0;
	extern char **environ;
	char new_val[100];

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
					/*new_val = malloc(sizeof(char) * 1024);*/
					if(!new_val)
						return (-1);
					strcpy(new_val, name);
					strcat(new_val, "=");
					strcat(new_val, value);
					environ[i] = new_val;
					/*free(new_val);*/
					return 0;
				}
				else
					return (0);
			}
	}
	if (environ[i] == '\0')
	{
		/*new_val = malloc(sizeof(char) * 1024);*/
                if(!new_val)
			return (-1);
		strcpy(new_val, name);
		strcat(new_val, "=");
		strcat(new_val, value);
		environ[i] = new_val;
		environ[i + 1] = '\0';
		/*free(new_val);*/
	}
	return 0;
}

int main(void)
{
	char *r;
	char *argv[] = {"TEST", "hola", "0"};
	/*r = _getenv(argv[0]);
	if(!r)
		printf("No se encontro pa\n");
	else
		printf("%s\n", r);
	printf("antes");*/
	 _setenv(argv[0], argv[1], atoi(argv[2]));
	printf("despues");
	r = _getenv("TEST");
        if(!r)
                printf("No se encontro pa\n");
        else
                printf("%s\n", r);
	return (0);
}
