#include "holberton.h"

/**
 * _which - entry point
 * @cmd: command to find full path
 * Return: full path on success
 *
 */

char *_which(char *cmd)
{
	int i = 0;
	struct stat st;
	static char buff[1024];
	char **path = NULL;

	path = findpath();
	for (i = 1; path[i]; i++)
	{
		if (cmd[0] == '.')
			_strcpy(buff, cmd);
		else
		{
			_strcpy(buff, path[i]);
			_strcat(buff, "/");
			_strcat(buff, cmd);
			printf("h:%s\n", buff);
		}
		if (stat(buff, &st) == 0)
		{
			printf("SI\n");
			free(path);
			return (buff);
		}
	}
	free(path);
	return (cmd);
}

/**
 * special_char_finder - entry point
 * @str: string to search special character
 * @ch: char to search for (its a string)
 * Return: changed string (or not)
 */
char *special_char_finder(char *str, char *ch)
{
	char *res = NULL;

	if(str[0] == '#')
		return ("");
	res = strtok(str, ch);
	if (res)
		return (res);
	else
		return(str);
}
