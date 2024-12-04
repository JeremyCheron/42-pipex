/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:48:04 by jcheron           #+#    #+#             */
/*   Updated: 2024/12/04 18:55:51 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	main(int ac, char **av, char **envp)
// {
// 	int		infile;
// 	int		outfile;
// 	int		pipe_fd[2];
// 	int		status;
// 	int		i;

// 	if (ac < 5)
// 	{
// 		ft_vprintf(STDERR_FILENO, USAGE);
// 		return (1);
// 	}
// 	if (!check_files(av[1]))
// 		return (1);
// 	infile = open(av[1], O_RDONLY);
// 	if (infile == -1)
// 		pipex_err_file(ERROR_OPEN_INPUT, av[1]);
// 	outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
// 	if (outfile == -1)
// 	{
// 		close(infile);
// 		pipex_err_file(ERROR_OPEN_OUTPUT, av[ac - 1]);
// 	}

// 	for (i = 2; i < ac - 2; i++)
// 	{
// 		if (pipe(pipe_fd) == -1)
// 		{
// 			close(infile);
// 			close(outfile);
// 			pipex_err(ERROR_PIPE);
// 		}
// 		execute_cmd(av[i], infile, pipe_fd[1], envp);
// 		close(pipe_fd[1]);
// 		infile = pipe_fd[0];
// 	}

// 	execute_cmd(av[ac - 2], infile, outfile, envp);
// 	close(outfile);

// 	for (i = 0; i < ac - 3; i++)
// 		wait(&status);

// 	return (0);
// }
