/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:24:00 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/23 20:36:25 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: <stdlib.h>
** SYN: converts string characters into their value int, my version might be
** slower than the iteractive version, felt cute might change it later.
** DESC: skips all white-space characters at the beginning of
** the string, converts the subsequent characters as part of the number,
** and then stops when it encounters the first character that isn't a number.
** (｡◕‿◕｡)
*/

#include "pslib.h"

int ft_atoi(const char *str)
{
	int res;
	int i = 0;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
		   *str == '\f' || *str == '\r')
		str++;
	while (*str != '\0')
	{
		res = res * 10 + str[i] - '0';
		if (*str == '-')
			return (-ft_atoi(++str));
		if (*str == '+')
			return (ft_atoi(++str));
		str++;
	}
	return (ft_atoi(str));

}
