/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:43:10 by jcheron           #+#    #+#             */
/*   Updated: 2024/12/04 18:59:42 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_input(char *filename)
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

int	open_output(char *filename)
{
	int	fd;

	if (access(filename, W_OK) == -1)
	{
		pipex_err_file(ERROR_OPEN_OUTPUT, filename);
		return (-1);
	}
	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		pipex_err_file(ERROR_OPEN_OUTPUT, filename);
	return (fd);
}

void	handle_pipes(int ac, char **av, int *infile, int *outfile, char **envp)
{
	int	pipe_fd[2];
	int	i;

	i = 2;
	while (i < ac - 2)
	{
		if (pipe(pipe_fd) == -1)
			pipex_err(ERROR_PIPE);
		execute_cmd(av[i], *infile, pipe_fd[1], envp);
		close(pipe_fd[1]);
		*infile = pipe_fd[0];
		i++;
	}
	execute_cmd(av[ac - 2], *infile, *outfile, envp);
}

int	main(int ac, char **av, char **envp)
{
	int	infile;
	int	outfile;
	int	status;

	if (ac < 5 || !check_files(av[1]))
		return (ft_vprintf(STDERR_FILENO, USAGE), 1);
	infile = open_input(av[1]);
	outfile = open_output(av[ac - 1]);
	handle_pipes(ac, av, &infile, &outfile, envp);
	close(outfile);
	while (--ac > 3)
		wait(&status);
	return (0);
}
