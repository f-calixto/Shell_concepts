#include "holberton.h"

/**
 * _puts - Entry point
 * @str: Array of char
 *
 * Description: print the content of str
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	char flag = 0;

	while (!flag)
	{
		if (str[i] == '\0')
		{
			_putchar('\n');
			flag = 1;
		}
		else
		{
			_putchar(str[i]);
			i++;
		}
	}
}

/**
 * _strncpy - entry point
 * @dest: string to append
 * @src: string to be appended
 * @n: number of characters or src to be concatenated
 * Return: concatenaded strings
 */

char *_strncpy(char *dest, char *src, int n)
{
	char *start = NULL;

	if ((dest == NULL) &&(src == NULL))
		return NULL;
	start = dest;
	while (*src && n--)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return start;
}

/**
 * _atoi - entry point
 * @s: string to convert to int
 * Return: converted integer
 */

int _atoi(char *s)
{
	int c = 1;
	int n = 0;

	for (; *s != 0; s++)
	{
		if (*s == '-')
			c = -c;
		if (*s >= 48 && *s <= 57)
		{
			n = n * 10 + c * (*s - '0');
			if (*(s + 1) < '0' || *(s + 1) > '9')
				return (n);
		}
	}
	return (n);
}
