#include <stdio.h>
int main (int vc, char **va, char **env)
{
	extern char **environ;
	printf("Env Address: %p\n", &env);
	printf("test2: %p\n", &*env);
	printf("Environ Address: %p\n", &environ);
	printf("Test: %p\n", &*environ);
	return (0);
}
