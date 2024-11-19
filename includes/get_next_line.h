/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:30:40 by jcheron           #+#    #+#             */
/*   Updated: 2024/10/29 21:25:05 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

// size_t	ft_strlen(char *s);
void	ft_fill(char *filled, char *s1, char *s2);
// char	*ft_strjoin(char *s1, char *s2);
// char	*ft_strdup(char *s1);
// char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif
