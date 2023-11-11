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
#endif
