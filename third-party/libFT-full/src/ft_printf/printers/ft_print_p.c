/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:35:47 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/18 21:26:17 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define NIL_STR "(nil)"
#define ADDR_STR "0x"

static int	_ft_print_p(uintptr_t ptr)
{
	if (ptr >= 16)
		return (_ft_print_p(ptr / 16) + _ft_print_p(ptr % 16));
	return (ft_print_c(HEX_LOWER[ptr]));
}

int	ft_print_p(uintptr_t ptr)
{
	if (!ptr)
		return (ft_printf(NIL_STR));
	if (ft_print_s(ADDR_STR) < 0)
		return (-1);
	return (_ft_print_p(ptr) + 2);
}
