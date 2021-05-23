/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:38:42 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/23 20:36:25 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: none
** SYN: i/o
** DESC: Outputs the string ’s’ to the given file descriptor.
*/

#include "pslib.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
