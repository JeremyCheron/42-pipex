/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:12:51 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/28 10:16:31 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	_ft_free_split(
			char **args)
{
	ft_free_split(args);
	return (1);
}

void	_closefds(
			int fd1,
			int fd2)
{
	close(fd1);
	close(fd2);
}

static void	execute_child_process(
			int input_fd,
			int output_fd,
			char *exec,
			char **args)
{
	if ((dup2(input_fd, STDIN_FILENO) == -1)
		|| (dup2(output_fd, STDOUT_FILENO) == -1))
		pipex_err(ERROR_DUP2);
	_closefds(input_fd, output_fd);
	if (execve(exec, args, NULL) == -1)
	{
		perror(ERROR_EXEC);
		exit(1);
	}
}

int	execute_cmd(
			char *cmd,
			int input_fd,
			int output_fd,
			char **envp)
{
	pid_t	pid;
	char	*exec;
	char	**args;

	exec = NULL;
	args = ft_split(cmd, ' ');
	if (!args)
		pipex_err(ERROR_ALLOC);
	if (cmd[0] == '/' || ft_strncmp(cmd, "./", 2) == 0)
		exec = ft_strdup(args[0]);
	else
		exec = find_exec(args[0], envp);
	if (exec == NULL)
	{
		_closefds(input_fd, output_fd);
		pipex_err_file(ERROR_CMD_NOT_FOUND, args[0]);
		return (_ft_free_split(args), 0);
	}
	pid = fork();
	if (pid == -1)
		pipex_err(ERROR_FORK);
	else if (pid == 0)
		execute_child_process(input_fd, output_fd, exec, args);
	free(exec);
	return (ft_free_split(args), 1);
}
