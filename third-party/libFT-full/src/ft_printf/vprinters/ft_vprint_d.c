/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprint_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:12:52 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/18 11:25:17 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vprintf.h"

static int	_ft_vprint_d(int fd, long n)
{
	if (n >= 10)
		return (ft_vprint_d(fd, n / 10) + ft_vprint_d(fd, n % 10));
	return (ft_vprint_c(fd, n + 48));
}

int	ft_vprint_d(int fd, int n)
{
	long	_n;

	_n = n;
	if (n < 0)
		return (write(fd, "-", 1) + _ft_vprint_d(fd, -_n));
	return (_ft_vprint_d(fd, _n));
}
