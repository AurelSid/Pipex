/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:44:29 by asideris          #+#    #+#             */
/*   Updated: 2024/07/20 17:54:13 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

char	*ft_get_exec(char **env, char *cmd);
void	ft_exec_pipe(char *argv, char **env);
char	*get_next_line(int fd);
void	ft_limiter_exec(char **argv);
void	ft_check_access(char **env, char *cmd);
void	ft_free_split(char **strs);
#endif