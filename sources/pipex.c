/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:43:10 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/28 10:22:01 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_input(
			char *filename)
{
	int	fd;

	if (access(filename, R_OK) == -1)
	{
		pipex_err_file(ERROR_OPEN_INPUT, filename);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		pipex_err_file(ERROR_OPEN_INPUT, filename);
	return (fd);
}

int	open_output(
			char *filename)
{
	int	fd;

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		pipex_err_file(ERROR_OPEN_OUTPUT, filename);
		return (-1);
	}
	if (fd == -1)
		pipex_err_file(ERROR_OPEN_OUTPUT, filename);
	return (fd);
}

void	handle_pipes(
			int ac,
			char **av,
			int *files,
			char **envp)
{
	int	pipe_fd[2];
	int	i;

	i = 2;
	while (i < ac - 2)
	{
		if (pipe(pipe_fd) == -1)
			pipex_err(ERROR_PIPE);
		if (!execute_cmd(av[i], files[0], pipe_fd[PIPE_WRITE], envp))
		{
			close(pipe_fd[PIPE_READ]);
			close(files[1]);
			exit(1);
		}
		close(pipe_fd[PIPE_WRITE]);
		files[0] = pipe_fd[PIPE_READ];
		i++;
	}
	execute_cmd(av[ac - 2], files[0], files[1], envp);
	close(files[0]);
}

int	main(
			int ac,
			char **av,
			char **envp)
{
	int	files[2];
	int	infile;
	int	outfile;
	int	status;

	if (ac < 5 || !check_files(av[1]))
		return (ft_vprintf(STDERR_FILENO, USAGE), 1);
	infile = open_input(av[1]);
	if (infile == -1)
		exit(1);
	outfile = open_output(av[ac - 1]);
	if (outfile == -1)
	{
		close(infile);
		exit(1);
	}
	files[0] = infile;
	files[1] = outfile;
	handle_pipes(ac, av, files, envp);
	close(outfile);
	close(infile);
	while (--ac > 3)
		wait(&status);
	return (0);
}
