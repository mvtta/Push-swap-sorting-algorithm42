/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:04:22 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/02/12 19:26:48 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: <stdlib.h>
** SYN: Allocates and fills with 0.
** DESC: contiguously allocates enough space for blocks, of x size & memory
** is filled with bytes of value zero.
** (。◕‿◕。)
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*dst;

	total = count * size;
	if (!(dst = malloc(total)))
		return (0);
	ft_memset(dst, 0, total);
	return (dst);
}
