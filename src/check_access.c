/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:16:51 by roko              #+#    #+#             */
/*   Updated: 2024/07/18 14:24:04 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**ft_find_cmd(char **env)
{
	char	*path;
	char	*full_path;
	char	**split_paths;
	int		i;
	int		j;

	j = 0;
	i = 0;
	path = "PATH";
	while (env[i])
	{
		full_path = ft_strnstr(env[i], path, ft_strlen(env[i]));
		if (full_path)
			break ;
		i++;
	}
	full_path = ft_strchr(full_path, '/');
	split_paths = ft_split(full_path, ':');
	while (split_paths[j])
	{
		j++;
	}
	return (split_paths);
}
void	ft_check_access(char **env, char *cmd)
{
	char	**all_paths;
	int		i;
	char	*cmd_path;
	char	**cmd_split;
	char	*cmd_name;
	int		access_ok;

	access_ok = 0;
	i = 0;
	cmd_split = ft_split(cmd, ' ');
	cmd_name = cmd_split[0];
	all_paths = ft_find_cmd(env);
	while (all_paths[i])
	{
		cmd_path = ft_strjoin(all_paths[i], "/");
		cmd_path = ft_strjoin(cmd_path, cmd_name);
	
		if (access(cmd_path, F_OK) == 0)
			access_ok = 1;
		i++;
	}
	if (access_ok == 0)
	{
		write(2, "zsh: command not found: ", 24);
		write(2, cmd_name, ft_strlen(cmd_name));
		write(2, "\n", 1);
		exit(-1);
	}
}
