#include "holberton.h"
void sig_handler(int signum);
/**
 * exit_hsh - Entry point
 * @eof: eof
 * @argv0: command
 * description: handles different cases where user want to exit shell
 * Return: 0
 */

int exit_hsh(ssize_t eof, char **argv, int flag, char *line, char **env)
{
	int i;

	if (eof == EOF)
	{
		if(flag == 1)
			_putchar('\n');
		return (0);
	}
	if (argv[0])
	{
		if (_strcmp(argv[0], "exit") == 0)
		{
			if(argv[1])
			{
				i = _atoi(argv[1]);
				free_everything(line, argv, env);
				exit(i);
			}
			else
				return (0);
		}

		if ((_strcmp(argv[0], "env") == 0) && argv[1] == NULL)
		{
			printf("Entro en env\n");
			for (i = 0; env[i] != '\0' ; i++)
				_puts(env[i]);
			write(1,"salio\n",6);
			strcpy(argv[0], "ls");
		}
		if ((_strcmp(argv[0], "env") == 0) && argv[1] != NULL)
		{
			for (i = 1 ; argv[i] != '\0' ; i++)
				_strcpy(argv[i - 1], argv[i]);
			printf("i=%i\n", i);
			argv[i - 1] = NULL;
		}
		/*cd_builtin(argv);*/
		if ((_strcmp(argv[0], "setenv") == 0) && argv[1] != NULL && argv[2] != NULL)
		{
			_setenv(argv[1] , argv[2] , 1 , env);
			/*argv[0] = NULL;*/
			strcpy(argv[0], "ls");
		}
		cd_builtin(argv);
		/*if (_strcmp(argv[0], "cd") == 0)
		{
			printf("helo");
			if (argv[1] == NULL)
			{
				strtok(_getenv("HOME"), "=");
				dog = strtok(NULL, "=");
				printf("%s\n", dog);
				chdir(dog);
				argv[0] = NULL;
			}
			else if (argv[1][0] == '/')
			{
				printf("%s\n", argv[1]);
				chdir(argv[1]);
				argv[0] = NULL;
			}
			else if (argv[1][0] == '-')
			{
				strtok(_getenv("OLDPWD"), "=");
				dog = strtok(NULL, "=");
				chdir(dog);
				argv[0] = NULL;
			}
			else
			{
				chdir(argv[1]);
				argv[0] = NULL;
			}
		}*/
		
	}
	return (1);
}

/**
 * free_everything - Entry point
 * @line: eof
 * @argv: command
 * description: sets some variables to null and frees allocs
 * Return: void
 */

void free_everything(char *line, char **argv, char **env)
{
	free_grid(env);
	free(line);
	line = NULL;
	free(argv);
}


/**
 * interactive - Entry point
 * @f: command
 * description: returns according to interactive mode
 * Return: void
 */

int interactive(int f)
{
	if (!isatty(STDIN_FILENO))
		f = 0;
	if (isatty(STDIN_FILENO))
		write (1, "($) ", 4);
	return (f);
}

/**
 * main - Entry point
 * description: main
 * Return: 0
 */

int main(void)
{
	pid_t child = 100; /* Para darnos cuenta si falla */
	int status = 0;
	size_t len = 0, f = 1;
	ssize_t eof = 0;
	char **args = NULL;
	char *line = NULL;
	char *mm;
	char **my_environ;
	/*int r;*/

	my_environ = array_copy(environ,0);
	/*for (m = 0 ; my_environ[m] != '\0' ; m++)
		printf("%s\n", my_environ[m]);*/
	while (1 == 1)
	{
		printf("pid:%i\n",getpid());
		f = interactive(f);
		signal(SIGINT, sig_handler);
		eof = getline(&line, &len, stdin);
		free(args);
		args = parser(line);
		if ((exit_hsh(eof, args, f, line, my_environ)) == 0)
		{
			fflush(STDIN_FILENO);
			break;
		}
		child = fork();
		if (child == -1)
		{
			free_everything(line, args, my_environ);
			return (1);
		}
		if (child == 0)
		{
			if (args[0])
			{
				mm = _which(args[0]);
				printf("mm=%s\n", mm);
				/*for (r = 0 ; args[r] ; r++)
					printf("arg[%i]=%s\n",r,args[r]);*/
				if (execve(mm, args, NULL) == -1)
					perror("./hsh");
			}
			break;
		}
		else
			wait(&status);
		fflush(STDIN_FILENO);
	}
	free_everything(line, args, my_environ);
	return (0);
}

void sig_handler(int signum)
{
  /*Return type of the handler function should be void*/
  /*printf("\nInside:%i handler function\n", signum);*/
	signum = signum;
	/*signal(SIGINT, sig_handler);*/
	write(1,"\n($) ",5);
}
