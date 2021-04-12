#include "holberton.h"
/**
* free_grid - Entry point
* @grid: matrix
* @height: int
*
* Description: Free a matrix
* Return: Nothing
*/
void free_grid(char **grid)
{
        int i = 0, size = 0;

        for (size = 0 ; grid[size] != '\0' ; size++)
        {
        }
        for (i = 0 ; i < size ; i++)
                free(grid[i]);
        free(grid);
}

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

char **array_copy(char **arr, int extra)
{
        int i = 0, len = 0;
        char **new_arr;

        for (i = 0 ; arr[i] != '\0' ; i++)
        {
        }
        new_arr = malloc(sizeof(char *) * (i + extra + 1));
        for (i = 0 ; arr[i] != '\0' ; i++)
        {
                len = strlen(arr[i]);
                new_arr[i] = malloc(sizeof(char) * (len + 1));
                strcpy(new_arr[i], arr[i]);
                new_arr[i][len] = '\0';
        }
        new_arr[i] = NULL;
        return (new_arr);
}

int _setenv(char *name, char *value, int overwrite, char **env)
{
	int i = 0, j = 0, size = 0;
	char *new_val;
	char **new_env;

	for (i = 0; env[i] != '\0'; i++)
	{
			char *word = env[i];
			for (j = 0; name[j] != '\0'; j++)
			{
				if (name[j] != word[j])
					break;
			}
			if ((name[j] == '\0') && (word[j] == '='))
			{
				if(overwrite != 0)
				{
					/*free(env[i]);*/
					size = (_strlen(name) + 3 + _strlen(value));
					printf("%i\n", size);
					new_val = malloc(sizeof(char) * size);
					if(!new_val)
						return (-1);
					strcpy(new_val, name);
					strcat(new_val, "=");
					strcat(new_val, value);
					strcat(new_val , "\0");
					strcpy(env[i], new_val);
					free(new_val);
					return 0;
				}
				else
					return (0);
			}
	}
	if (env[i] == '\0')
	{
		size = (_strlen(name) + 3 + _strlen(value));
                new_val = malloc(sizeof(char) * size);
                if(!new_val)
			return (-1);
		new_env = array_copy(env, 1);
		new_env[i] = malloc(sizeof(char *));
		strcpy(new_val, name);
		strcat(new_val, "=");
		strcat(new_val, value);
		strcat(new_val, "\0");
		strcpy(new_env[i] , new_val);
		new_env[i + 1] = NULL;
		free_grid(env);
		env = array_copy(new_env, 0);
		/*for (j = 0; new_env[j] != '\0' ; j++)
			printf("%s\n", new_env[j]);*/
		free_grid(new_env);
		free(new_val);
	}
	return 0;
}



