/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:08:45 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/18 21:27:24 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_ft_print_x(unsigned int n, char *chars)
{
	if (n >= 16)
		return (_ft_print_x(n / 16, chars) + _ft_print_x(n % 16, chars));
	return (ft_print_c(chars[n]));
}

int	ft_print_x(unsigned int n, int format)
{
	char	*_chars;

	if (format == 'x')
		return (_ft_print_x(n, HEX_LOWER));
	return (_ft_print_x(n, HEX_UPPER));
}
