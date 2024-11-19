/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprint_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:41:54 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/19 11:34:07 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vprintf.h"

#define NULL_STR "(null)"

int	ft_vprint_s(int fd, char *s)
{
	if (!s)
		return (write(fd, NULL_STR, ft_strlen(NULL_STR)));
	return (write(fd, s, ft_strlen(s)));
}
