/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:55:07 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/02/16 17:01:51 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: <string.h>
** SYN: find firsr occurence and return a ptr of the location of c
** DESC: searches for the first occurrence of the character c (an unsigned char)
** in the string pointed to by the argument str.
** if c is `\0', the functions locate the terminating `\0'
** (｡◕‿◕｡)
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (char)c != *s)
		s++;
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}
