#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern char **environ;

#define MAX_COMMAND_LENGTH 256
#define MAX_ARG_COUNT 64
/**
 *main - main function
 *dsp_promt - function that display promts
 *excute_command - excute promts
 *Return: void
 */
int main(void);
void display_prompt(void);
int excute_command(char *comand);
void resolve_command_line(char *command_line, char **args);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strdup(char *s);
int _strlen(char *c);
char *_getenv(char *var);
int print_env(void);
int _str_cmp(char *st1, char *st2, int n);

#endif
