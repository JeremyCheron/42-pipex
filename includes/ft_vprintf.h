/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:18:53 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/18 11:25:56 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VPRINTF_H
# define FT_VPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include "libft.h"

int		ft_vprintf(int fd, const char *str, ...);
int		ft_vprint_c(int fd, char c);
int		ft_vprint_d(int fd, int n);
int		ft_vprint_s(int fd, char *s);
int		ft_vprint_x(int fd, unsigned int n, int format);
int		ft_vprint_p(int fd, uintptr_t ptr);
int		ft_vprint_u(int fd, unsigned int n);

#endif
