/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:33:02 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/02/12 19:36:37 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: none
** SYN: i/o
** DESC: Outputs the string ’s’ to the given file descriptor.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}
