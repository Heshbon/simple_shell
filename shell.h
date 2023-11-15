#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_INPUT_SIZE 100
int main(int arc, char **argv);
void rncmd(char **arv, char **envp);

void excute_command(char *args[]);
char *handle_path(char *command);
int exce(int argc, char *argv[]);
int _stncmp(char *strn1, char *strn2);
char *_strcat(char *dest, char *src);
char *_strndup(const char *strn);
int _strnlen(char *c);
char *_strncpy(char *dest, char *src);
int handle_command(ssize_t rd);
#endif
