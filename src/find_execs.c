/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_execs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:16:51 by roko              #+#    #+#             */
/*   Updated: 2024/07/20 14:36:52 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_find_path(char **env)
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

char	*ft_get_exec(char **env, char *cmd)
{
	char	**all_paths;
	int		i;
	char	*cmd_path;
	char	**cmd_split;
	char	*cmd_name;

	i = 0;
	cmd_split = ft_split(cmd, ' ');
	cmd_name = cmd_split[0];
	all_paths = ft_find_path(env);
	while (all_paths[i])
	{
		cmd_path = ft_strjoin(all_paths[i], "/");
		cmd_path = ft_strjoin(cmd_path, cmd_name);
		if (execve(cmd_path, cmd_split, env) == -1)
			printf("exe error: %s: %s\n", cmd, cmd_path);
		else
			printf("exe ok");
		i++;
	}
	ft_free_split(cmd_split);
	ft_free_split(all_paths);
	return (cmd_path);
}
