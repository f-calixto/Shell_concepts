#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

/*protoypes*/
char **parser(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _putchar(char c);
void free_array(char **argv);
size_t _strcspn(char *s, char par);
char *_getenv(const char *name, char **env);
char **findpath(char **env);
char *_which(char *cmd, char **env);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
void _puts(char *str);
char *_strncpy(char *dest, char *src, int n);
char *special_char_finder(char *str, char *ch);
void free_everything(char *line, char **argv, char **env);
int _atoi(char *s);
void cd_builtin(char **argv, char **env);
void free_grid(char **grid);
char **array_copy(char **arr, int extra);
int _setenv(char *name, char *value, int overwrite, char **env, char ***envi);

#endif
