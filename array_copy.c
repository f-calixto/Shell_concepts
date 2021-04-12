#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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

/**
* free_grid - Entry point
* @grid: matrix
* @height: int
*
* Description: Free a matrix
* Return: Nothing
*/
void free_grid(char **grid, int height)
{
	int i = 0, size = 0;

	for (size = 0 ; grid[size] != '\0' ; size++)
	{
	}
	for (i = 0 ; i < height ; i++)
		free(grid[i]);
	free(grid);
}

int main(int argc, char **argv)
{
	int i = 0;
	char **test;

	test = array_copy(argv,0);
	for (i = 0 ; test[i] != '\0' ; i++)
		printf("%s\n", test[i]);
	free_grid(test, argc);
	return (0);
}
