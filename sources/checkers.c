/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:55:32 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/28 09:10:34 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

char	*join_path_cmd(
			const char *path,
			const char *cmd)
{
	char	*full_path;
	char	*temp;

	temp = ft_strjoin(path, "/");
	if (!temp)
		return (NULL);
	full_path = ft_strjoin(temp, cmd);
	free(temp);
	return (full_path);
}

int	pipex_check_ac(
			int ac)
{
	if (ac != 5)
	{
		ft_vprintf(STDERR_FILENO, "Usage: ./pipex file1 cmd1 cmd2 file2\n");
		return (0);
	}
	return (1);
}

int	check_files(
			char *file1)
{
	if (access(file1, F_OK) == -1)
	{
		ft_vprintf(STDERR_FILENO,
			"pipex: %s: No such file or directory\n", file1);
		return (0);
	}
	return (1);
}

char	**get_allpaths(
			char **env)
{
	char	*path;
	char	**all_paths;

	while (*env && ft_strncmp(*env, "PATH=", 5) != 0)
		env++;
	if (!*env)
		return (NULL);
	path = *env + 5;
	all_paths = ft_split(path, ':');
	if (!all_paths)
		return (NULL);
	return (all_paths);
}

char	*find_exec(
			char *cmd,
			char **env)
{
	char	**all_paths;
	char	*full_path;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	all_paths = get_allpaths(env);
	if (!all_paths)
		return (NULL);
	i = 0;
	while (all_paths[i])
	{
		full_path = join_path_cmd(all_paths[i], cmd);
		if (full_path && access(full_path, X_OK) == 0)
		{
			ft_free_split(all_paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	return (ft_free_split(all_paths), NULL);
}
