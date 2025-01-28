/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:55:53 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/28 09:10:14 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft.h"
# include "ft_printf.h"
# include "ft_vprintf.h"
# include <fcntl.h>

# define USAGE "Usage: ./pipex file1 cmd1 cmd2 file2"
# define ERROR_MISSING_ARG "missing argument"
# define ERROR_INT "internal error"
# define ERROR_CMD_NOT_FOUND "command not found"
# define HEREDOC "here_doc"
# define ERROR_ALLOC "memory allocation failed"
# define ERROR_FORK "fork failed"
# define ERROR_DUP2 "dup2 failed"
# define ERROR_EXEC "execvp failed"
# define ERROR_PIPE "pipe creation failed"
# define ERROR_OPEN_INPUT "can't open input file"
# define ERROR_OPEN_OUTPUT "can't open output file"

# define RET_ERR 1
# define RET_OK 0

# define PIPE_READ 0
# define PIPE_WRITE 1

# define BUFFER_SIZE 4096

typedef struct s_args
{
	int		intput_fd;
	int		input_flags;
	int		output_fd;
	int		null_fd;
	char	**start;
	char	**end;
	char	**paths;
	char	**envp;
}	t_args;

// checkers.c
int		check_files(
			char *file1);

int		pipex_check_ac(
			int ac);

void	get_paths(
			char **env);

char	*find_exec(
			char *cmd,
			char **env);

// errs.c
void	pipex_err(
			char *msg);

int		pipex_err_file(
			char *msg,
			char *filename);

void	pipex_err_file_no_exit(
			char *msg,
			char *filename);

// read_cmd.c
void	execute_cmd(
			char *cmd,
			int input_fd,
			int output_fd,
			char **envp);

void	_closefds(
			int fd1,
			int fd2);

#endif
