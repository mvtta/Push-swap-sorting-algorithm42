/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:24:00 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/26 13:46:50 by mvaldeta         ###   ########.fr       */
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

static	int	ft_isspace(int chr)
{
	return (chr == 9 || chr == 10 || chr == 11
		|| chr == 12 || chr == 13 || chr == 0 || chr == ' ');
}

static	int	ft_issign(char chr)
{
	return (chr == '-' || chr == '+');
}

static	int	ft_isdigit(char chr)
{
	return (chr >= '0' && chr <= '9');
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (ft_issign(*str))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = 0;
	while (ft_isdigit(*str))
		res = res * 10 + (*(str++) - 48);
	return (res * sign);
}