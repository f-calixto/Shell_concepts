#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "_getenv.c"

typedef struct paths_s
{
	char *dir_name;
	struct paths_s *next;
} paths_t;

/*function to print every element of linked list to make sure it was created with no problem*/
void print_list(paths_t *h)
{
	paths_t *current = h;
	unsigned int count = 0;

	while (current)
	{
		printf("%s\n", current->dir_name);
		current = current->next;
	}
}

/*find PATH name and create an array of arrays where evrey element is a directory of the path*/
char **findpath(void)
{
	int j = 0, i;
	char *path;
	char **res;
	char *word;
	
	path = _getenv("PATH");
	res = malloc(sizeof(char *) * 20);
	word = strtok(path, ":="); 
        while (word)
        {
                res[j] = word;
                word = strtok(NULL, ":=");
                j++;
        }
	return (res);
}
/*created a linked list from scratch where every element has a string corresponding to every directory on the PATH*/
/*returns pointer to the header node*/
paths_t *create_path_list(void)
{
	unsigned int c, arr_len;
	char **array;
	paths_t *head, *aux, *last;

	head = malloc(sizeof(paths_t));
	if (!head)
		exit(98);
	array = findpath();
	arr_len = ((sizeof(array) / sizeof(char)) - 2);
	head->dir_name = strdup(array[1]);
	head->next = NULL;
	aux = head;
	for (c = 2; c <= arr_len; c++)
	{
		last = malloc(sizeof(paths_t));
		if (!last)
			exit(98);
		last->dir_name = strdup(array[c]);
		last->next = NULL;
		aux->next = last;
		aux = aux->next;
	}
	return (head);
}

int main(void)
{
	char **res;
	paths_t *head;

	head = create_path_list();
	print_list(head);
	return (0);
}
