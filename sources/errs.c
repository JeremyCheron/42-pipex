/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:50:41 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/19 11:55:42 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_err(char *msg)
{
	ft_vprintf(STDERR_FILENO, "pipex: %s\n", msg);
	exit(1);
}

int	pipex_err_file(char *msg, char *filename)
{
	ft_vprintf(STDERR_FILENO, "pipex: %s: %s\n", msg, filename);
	return (1);
}

void	pipex_err_file_no_exit(char *msg, char *filename)
{
	if (filename)
		ft_vprintf(STDERR_FILENO, "pipex: %s: %s\n", msg, filename);
	ft_vprintf(STDERR_FILENO, "pipex: %s\n", msg);
}
