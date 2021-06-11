/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:25:59 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/02/12 19:26:07 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: <string.h>
** SYN: counts len of str
** DESC: takes a string as an argument and returns its length
** (｡◕‿◕｡)
*/

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}
