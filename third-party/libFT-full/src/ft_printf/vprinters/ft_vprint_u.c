/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprint_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:23:02 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/18 11:24:33 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vprintf.h"

int	ft_vprint_u(int fd, unsigned int n)
{
	if (n >= 10)
		return (ft_vprint_u(fd, n / 10) + ft_vprint_u(fd, n % 10));
	return (ft_vprint_c(fd, n + 48));
}
