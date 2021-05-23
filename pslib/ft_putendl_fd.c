/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:23:28 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/23 20:36:25 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: none
** SYN: i/o
** DESC: Outputs the string ’s’ to the given file descriptor, followed by '\n'
*/

#include "pslib.h"

void	ft_putendl_fd(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
	ft_putchar_fd('\n', fd);
}
