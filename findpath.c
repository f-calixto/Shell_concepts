#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Function return size of string and convert signed  *
 *integer to ascii value and store them in array of  *
 *character with NULL at the end of the array        */

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


char ** findpath(int *len)
{
	int fd, ppid, size, j = 0, i;
	char str[20] = "/proc/", path[10240], aux[5];
	char **res = malloc(sizeof(char *) * 20);
	char *word;

	ppid = /*1546*/ getppid();
	_itoa(ppid, aux);
	strcat(str, aux);
	strcat(str, "/environ");
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("Fallo FD");
		return ;
	}
	size = read(fd, path, 10240);
	while (size != 0)
		size = read(fd, path, 1024);
	/*printf("%s\n", path);*/
	word = strtok(path, ":="); 
        while (word)
        {
                res[j] = word;
                word = strtok(NULL, ":=");
                j++;
        }
	for (i = 0; i < j ; i++)
	{
		printf("%s\n",res[i]);
	}
	*len = j;

	return res;
}

int main(void)
{
	int i, j = 0;
	char **a;

	a = findpath(&j);
	printf("De aca pa abajo es main\n");
	for (i = 0; i < j ; i++)
        {
               printf("%s\n",a[i]);
        }

	return (0);
}
