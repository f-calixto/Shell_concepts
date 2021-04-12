#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *special_char_finder(char *str, char ch)
{
        char *aux;
        unsigned int i = 0, l = 0;

	if (!str)
		return ("holholaa");
        l = strlen(str);
        while ((str[i] != ch) && str[i])
        {
                i++;
        }
        if (i == l)
                return (str);
        aux = malloc(sizeof(char) * (i + 1));
        str = strncpy(aux, str, i);
        return (str);
}
char *mod(char *str, char *ch)
{
	char *res = NULL;

	res = strtok(str, "#");
	if (res)
		return (res);
	else
		return(str);
}
int main (void)
{
	char *m = malloc(30);
	char *r;

	strcpy(m, "Hola que #onda");
	printf("orig: %s\n", m);
	printf("antes\n");
	r = mod(m, "#");
	printf("desp\n");
	printf("res: %s\n", r);
	free(r);

	return(0);
}
