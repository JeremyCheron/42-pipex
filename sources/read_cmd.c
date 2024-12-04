/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:12:51 by jcheron           #+#    #+#             */
/*   Updated: 2024/12/04 18:29:45 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	_ft_free_split(char **args)
{
	ft_free_split(args);
	return (1);
}

static void	_closefds(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

static void	pid_error(int input_fd, int output_fd, char *exec, char **args)
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

void	execute_cmd(char *cmd, int input_fd, int output_fd, char **envp)
{
	pid_t	pid;
	char	*exec;
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
		pipex_err(ERROR_ALLOC);
	exec = find_exec(args[0], envp);
	if (!exec)
	{
		pipex_err_file(ERROR_CMD_NOT_FOUND, args[0]);
		exit (_ft_free_split(args));
	}
	pid = fork();
	if (pid == -1)
		pipex_err(ERROR_FORK);
	else if (pid == 0)
	{
		pid_error(input_fd, output_fd, exec, args);
	}
	free(exec);
	ft_free_split(args);
}
