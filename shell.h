#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void rncmd(char **arv, char **envp);
int excute_command(int status, char *args[]);
int _stncmp(char *strn1, char *strn2);
char *_strcat(char *dest, char *src);
char *_strndup(const char *strn);
int _strnlen(char *c);
char *_strncpy(char *dest, char *src);
char *handle_path(char *command);

#endif
