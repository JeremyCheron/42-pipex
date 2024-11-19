/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:24:24 by jcheron           #+#    #+#             */
/*   Updated: 2024/10/17 13:44:21 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*s;
	char		*d;

	if (!src && !dest)
		return (NULL);
	s = (char *)src;
	d = (char *)dest;
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		ft_memcpy(dest, s, len);
	}
	return (dest);
}
// int main(void)
// {
// 	char str[] = "coucou";
// 	ft_memmove(str + 2, str, 3);
// 	printf("\n%s\n", str);

// 	char str2[] = "coucou";
// 	memmove(str2 + 2, str2, 3);
// 	printf("\n%s\n", str2);
// }
