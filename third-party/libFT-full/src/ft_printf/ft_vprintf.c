/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:16:31 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/18 12:17:34 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vprintf.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_vformats(int fd, va_list args, const char format)
{
	if (format == 'c')
		return (ft_vprint_c(fd, va_arg(args, int)));
	if (format == 's')
		return (ft_vprint_s(fd, va_arg(args, char *)));
	if (format == 'd' || format == 'i')
		return (ft_vprint_d(fd, va_arg(args, int)));
	if (format == '%')
		return (ft_vprint_c(fd, '%'));
	if (format == 'x' || format == 'X')
		return (ft_vprint_x(fd, va_arg(args, unsigned int), format));
	if (format == 'p')
		return (ft_vprint_p(fd, va_arg(args, uintptr_t)));
	if (format == 'u')
		return (ft_vprint_u(fd, va_arg(args, unsigned int)));
	return (0);
}

int	ft_vprintf(int fd, const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_vformats(fd, args, str[i + 1]);
			i++;
		}
		else
			len += write(fd, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
