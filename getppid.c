#include <unistd.h>
#include <stdio.h>
int main(void)
{
	pid_t value, val;

	value = getppid();
	val = getpid();
	printf("PID: %u -- PPID: %u\n",val , value);
	return (0);
}
