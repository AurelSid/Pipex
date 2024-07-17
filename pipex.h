#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "Libft/libft.h"
#include <sys/wait.h>

char *ft_get_exec(char **env, char *cmd);
void ft_exec_pipe(char *argv, char **env);
char *get_next_line(int fd);
void ft_limiter_exec(char **argv);
#endif