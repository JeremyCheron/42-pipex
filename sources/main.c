/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:48:04 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/19 13:05:44 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	_ft_free_split(char **args)
{
	ft_free_split(args);
	return (1);
}
void	execute_cmd(char *cmd, int input_fd, int output_fd, char **envp)
{
	pid_t	pid;
	char	*exec;
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
		pipex_err("pipex: memory allocation failed");

	exec = find_exec(args[0], envp);
	if (!exec)
	{
		pipex_err_file("pipex: command not found", args[0]);
		exit (_ft_free_split(args));
	}

	pid = fork();
	if (pid == -1)
		pipex_err("pipex: fork failed");
	else if (pid == 0)
	{
		if ((dup2(input_fd, STDIN_FILENO) == -1)
			|| (dup2(output_fd, STDOUT_FILENO) == -1))
			pipex_err("pipex: dup2 failed");
		close(input_fd);
		close(output_fd);
		if (execve(exec, args, NULL) == -1)
		{
			perror("pipex: execvp failed");
			exit(1);
		}
	}
	free(exec);
	ft_free_split(args);
}

int	main(int ac, char **av, char **envp)
{
	int		infile;
	int		outfile;
	int		pipe_fd[2];
	int		status;
	int		i;

	if (ac < 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 ... cmdN file2\n", 2);
		return (1);
	}
	if (!check_files(av[1]))
		return (1);
	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		pipex_err_file("Can't open input file", av[1]);
	outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		close(infile);
		pipex_err_file("Can't open output file", av[ac - 1]);
	}

	for (i = 2; i < ac - 2; i++)
	{
		if (pipe(pipe_fd) == -1)
		{
			close(infile);
			close(outfile);
			pipex_err("pipex: pipe creation failed");
		}
		execute_cmd(av[i], infile, pipe_fd[1], envp);
		close(pipe_fd[1]);
		infile = pipe_fd[0];
	}

	execute_cmd(av[ac - 2], infile, outfile, envp);
	close(outfile);

	for (i = 0; i < ac - 3; i++)
		wait(&status);

	return (0);
}

// int	main(int ac, char **av, char **envp)
// {
// 	int		infile, outfile, pipe_fd[2];
// 	pid_t	pid1, pid2;

// 	get_paths(envp);

// 	if (!pipex_check_ac(ac))
// 		return 1;

// 	infile = open(av[1], O_RDONLY);
// 	if (infile == -1)
// 		pipex_err_file("Can't open input file", av[1]);
// 	outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
// 	if (outfile == -1)
// 	{
// 		close(infile);
// 		pipex_err_file("Can't open input file", av[4]);
// 	}

// 	if (pipe(pipe_fd) == -1)
// 	{
// 		close(infile);
// 		close(outfile);
// 		pipex_err("Pipe creation failed\n");
// 	}
// 	pid1 = fork();
// 	if (pid1 == -1)
// 	{
// 		close(infile);
// 		close(outfile);
// 		close(pipe_fd[0]);
// 		close(pipe_fd[1]);
// 		pipex_err("Fork failed\n");
// 	}
// 	if (pid1 == 0)
// 	{
// 		char **cmd1_args = ft_split(av[2], ' ');
// 		dup2(infile, STDIN_FILENO);
// 		dup2(pipe_fd[1], STDOUT_FILENO);

// 		close(pipe_fd[0]);
// 		close(infile);

// 		execve(ft_strjoin(BIN_PATH, cmd1_args[0]), cmd1_args, NULL);
// 		pipex_err_file("Execution failed for cmd1", cmd1_args[0]);
// 	}
// 	pid2 = fork();
// 	if (pid2 == -1)
// 	{
// 		close(infile);
// 		close(outfile);
// 		close(pipe_fd[0]);
// 		close(pipe_fd[1]);
// 		pipex_err("Fork failed\n");
// 	}
// 	pid2 = fork();
// 	if (pid2 == -1)
// 	{
// 		close(infile);
// 		close(outfile);
// 		close(pipe_fd[0]);
// 		close(pipe_fd[1]);
// 		pipex_err("Fork failed");
// 	}
// 	if (pid2 == 0)
// 	{
// 		char **cmd2_args = ft_split(av[3], ' ');
// 		dup2(pipe_fd[0], STDIN_FILENO);
// 		dup2(outfile, STDOUT_FILENO);

// 		close(pipe_fd[1]);
// 		close(outfile);

// 		execve(ft_strjoin(BIN_PATH, cmd2_args[0]), cmd2_args, NULL);
// 		pipex_err_file("Execution failed for cmd2", cmd2_args[0]);
// 	}
// 	close(infile);
// 	close(outfile);
// 	close(pipe_fd[0]);
// 	close(pipe_fd[1]);

// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// }
