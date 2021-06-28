/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a2i.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:24:00 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/06/28 23:41:57 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

static	int	checkspace(int chr)
{
	return (chr == 9 || chr == 10 || chr == 11
		|| chr == 12 || chr == 13 || chr == 0 || chr == ' ');
}

static	int	checksign(char chr)
{
	return (chr == '-' || chr == '+');
}

static	int	checkdigit(char chr)
{
	return (chr >= '0' && chr <= '9');
}

int	process(const char *str)
{
	int	sign;
	int	res;
/* 
	if(ft_isalpha(*str) == 1)
         push_swap_error(); */
	sign = 1;
	while (checkspace(*str))
		str++;
	if (checksign(*str))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = 0;
	while (checkdigit(*str))
		res = res * 10 + (*(str++) - 48);
	return (res * sign);
}