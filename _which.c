#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int _itoa(int value,char *ptr)
     {
        int count=0,temp;
        if(ptr==NULL)
            return 0;   
        if(value==0)
        {   
            *ptr='0';
            return 1;
        }

        if(value<0)
        {
            value*=(-1);    
            *ptr++='-';
            count++;
        }
        for(temp=value;temp>0;temp/=10,ptr++);
        *ptr='\0';
        for(temp=value;temp>0;temp/=10)
        {
            *--ptr=temp%10+'0';
            count++;
        }
        return count;
     }

char **findpath(int *len)
{
	int fd, ppid, size, j = 0, i;
	char str[20] = "/proc/", path[10240], aux[5];
	char **res;
	char *word;

	ppid = /*1546*/ getppid();
	_itoa(ppid, aux);
	strcat(str, aux);
	strcat(str, "/environ");
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("Fallo FD");
		return;
	}
	size = read(fd, path, 10240);
	while (size != 0)
		size = read(fd, path, 1024);
	/*printf("%s\n", path);*/
	res = malloc(sizeof(char *) * 20);
	word = strtok(path, ":="); 
        while (word)
        {
                res[j] = word;
                word = strtok(NULL, ":=");
                j++;
        }
	*len = j;
	return (res);
}




/**
 * main - stat example
 *
 * Return: Always 0.
 */

int main(int ac, char *av[])
{
	int i, j, pichu = 0;
	char *paths[4] = {"/usr/bin", "/usr", "/bin", NULL};
	struct stat st;
	char p[1024];
	char **test;

	if (ac < 2)
		return (-1);
	//paths[] = separate_paths();
	test = findpath(&pichu);
	for (j = 0; j < (ac - 1); j++)
	{
		for (i = 1; i < pichu; i++)
		{
			strcpy(p, test[i]);
			strcat(p, "/");
			strcat(p, av[j + 1]);
			if (stat(p, &st) == 0)
			{
				printf("%s\n", p);
			}
		}
	}
	return (0);
}
