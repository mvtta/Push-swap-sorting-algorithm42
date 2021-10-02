/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a2i.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:24:00 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/10/02 15:04:04 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

static	int	checkspace(int chr)
{
	return (chr == 9 || chr == 10
		|| chr == 11 || chr == 12 || chr == 13
		|| chr == 0 || chr == ' ');
}

static	int	checksign(char chr)
{
	return (chr == '-' || chr == '+');
}

static	int	checkdigit(char chr)
{
	return (chr >= '0' && chr <= '9');
}

static	int	ft_limits(const char *str)
{
	size_t	i;
	size_t	max;

	i = 0;
	max = 0;
	i = ft_strlen(str);
	max = 10;
	if (i >= 10)
		push_swap_error();
	return (0);
}

int	process(const char *str)
{
	int	sign;
	int	res;

	sign = 1;
	ft_limits(str);
	while (checkspace(*str))
		str++;
	if (checksign(*str))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		push_swap_error();
	res = 0;
	while (checkdigit(*str))
		res = res * 10 + (*(str++) - 48);
	return (res * sign);
}
