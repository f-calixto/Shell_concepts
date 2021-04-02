#include <stdio.h>
#include <unistd.h>
int main(void)
{
	int i = 0;
	extern char **environ;

	for(i = 0; environ[i] != '\0'; i++)
	{
		printf("%s\n", environ[i]);
	}

	return (0);
}
