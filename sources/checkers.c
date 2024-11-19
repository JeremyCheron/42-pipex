/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:55:32 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/19 10:30:15 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

int	pipex_check_ac(int ac)
{
	if (ac != 5)
	{
		ft_vprintf(STDERR_FILENO, "Usage: ./pipex file1 cmd1 cmd2 file2\n");
		return (0);
	}
	return (1);
}

int	check_files(char *file1)
{
	if (access(file1, F_OK) == -1)
	{
		ft_vprintf(STDERR_FILENO,
			"pipex: %s: No such file or directory\n", file1);
		return (0);
	}
	return (1);
}

char	*find_exec(char *cmd, char **env)
{
	char	*path;
	char	**all_paths;
	char	*full_path;
	int		i;
	char	*temp;

	while (*env && ft_strncmp(*env, "PATH=", 5) != 0)
		env++;
	if (!*env)
		return (NULL);
	path = *env + 5;
	all_paths = ft_split(path, ':');
	if (!all_paths)
		return (NULL);
	i = 0;
	while (all_paths[i])
	{
		full_path = ft_strjoin(all_paths[i], "/");
		temp = full_path;
		full_path = ft_strjoin(full_path, cmd);
		free(temp);
		if (access(full_path, X_OK) == 0)
		{
			ft_free_split(all_paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	ft_free_split(all_paths);
	return (NULL);
}
