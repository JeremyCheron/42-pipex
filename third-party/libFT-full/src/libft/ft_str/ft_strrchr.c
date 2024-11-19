/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:29:07 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/07 18:23:06 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*r;

	r = NULL;
	while (*s)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			r = s;
		++s;
	}
	if (*(unsigned char *)s == (unsigned char)c)
		r = s;
	return ((char *) r);
}
