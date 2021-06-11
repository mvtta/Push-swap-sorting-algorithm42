/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:08:11 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/02/16 17:14:18 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: <string.h>
** SYN: find last and return a ptr of the location of c
** DESC: searches for the flast occurrence of the character c (an unsigned char)
** in the string pointed to by the argument str.
** (｡◕‿◕｡)
*/

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*ini;

	ini = s;
	i = ft_strlen(s);
	s = (s + i);
	while (*s != *ini && (char)c != *s)
		s--;
	if ((char)c == *s)
		return ((char *)s);
	return (0);
}
