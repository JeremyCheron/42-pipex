/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprint_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:35:47 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/18 11:24:26 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vprintf.h"

static int	_ft_vprint_p(int fd, uintptr_t ptr)
{
	if (ptr >= 16)
		return (_ft_vprint_p(fd, ptr / 16) + _ft_vprint_p(fd, ptr % 16));
	return (ft_vprint_c(fd, "0123456789abcdef"[ptr]));
}

int	ft_vprint_p(int fd, uintptr_t ptr)
{
	if (!ptr)
		return (ft_vprintf(fd, "(nil)"));
	if (ft_vprint_s(fd, "0x") < 0)
		return (-1);
	return (_ft_vprint_p(fd, ptr) + 2);
}
