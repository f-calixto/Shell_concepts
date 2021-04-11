#include "holberton.h"
void cd_builtin(char **argv)
{
	char *dog;

	if (_strcmp(argv[0], "cd") == 0)
                {
                        printf("helo");
                        if (argv[1] == NULL)
                        {
                                strtok(_getenv("HOME"), "=");
                                dog = strtok(NULL, "=");
                                printf("%s\n", dog);
                                chdir(dog);
                                argv[0] = NULL;
                        }
                        else if (argv[1][0] == '/')
                        {
                                printf("%s\n", argv[1]);
                                chdir(argv[1]);
                                argv[0] = NULL;
                        }
                        else if (argv[1][0] == '-')
                        {
                                strtok(_getenv("OLDPWD"), "=");
                                dog = strtok(NULL, "=");
                                chdir(dog);
                                argv[0] = NULL;
                        }
                        else
                        {
                                chdir(argv[1]);
                                argv[0] = NULL;
                        }
                }
}
