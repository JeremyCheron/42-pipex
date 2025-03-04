/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:41:54 by jcheron           #+#    #+#             */
/*   Updated: 2024/10/22 15:44:37 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define NULL_STR "(null)"

int	ft_print_s(char *s)
{
	if (!s)
		return (write(STDOUT_FILENO, NULL_STR, ft_strlen(NULL_STR)));
	return (write(STDOUT_FILENO, s, ft_strlen(s)));
}
