/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprint_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:08:45 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/18 11:24:38 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vprintf.h"

static int	_ft_vprint_x(int fd, unsigned int n, char *chars)
{
	if (n >= 16)
		return (_ft_vprint_x(fd, n / 16, chars)
			+ _ft_vprint_x(fd, n % 16, chars));
	return (ft_vprint_c(fd, chars[n]));
}

int	ft_vprint_x(int fd, unsigned int n, int format)
{
	char	*_chars;

	if (format == 'x')
		_chars = "0123456789abcdef";
	else
		_chars = "0123456789ABCDEF";
	return (_ft_vprint_x(fd, n, _chars));
}
