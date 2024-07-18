/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:03:54 by roko              #+#    #+#             */
/*   Updated: 2024/07/18 19:02:06 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_exec_pipe(char *argv, char **env)
{
	int		pipe_fd[2];
	pid_t	process_id;

	if (pipe(pipe_fd) == -1)
		exit(0);
	process_id = fork();
	if (process_id == 0)
	{
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		ft_get_exec(env, argv);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
	}
}

int	open_files(int argc, char **argv, int *infd, int *outfd)
{
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
	{
		if (argc < 6)
			return (0);
		*outfd = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
		ft_limiter_exec(argv);
		return (3);
	}
	else
	{
		*infd = open(argv[1], O_RDONLY);
		if (*infd < 0)
		{
			write(2, "zsh: no such file or directory: ", 32);
			write(2, argv[1], ft_strlen(argv[1]));
			write(2, "\n", 1);
			exit(-1);
		}
		*outfd = open(argv[argc - 1], O_WRONLY | O_CREAT, 0644);
		dup2(*infd, 0);
		return (2);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	infd;
	int	outfd;
	int	i;
	int	j;

	j = open_files(argc, argv, &infd, &outfd);
	i = 0;
	while (j < argc - 1)
	{
		ft_check_access(env, argv[j]);
		j++;
	}
	while (i < argc - 2)
	{
		ft_exec_pipe(argv[i], env);
		i++;
	}
	dup2(outfd, 1);
	ft_get_exec(env, argv[argc - 2]);
	system("leaks pipex");
	return (0);
}
