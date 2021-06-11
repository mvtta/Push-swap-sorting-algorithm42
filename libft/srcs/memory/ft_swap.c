/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:00:21 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/02/12 19:26:20 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: none only built in c++
** SYN: swaps value of variables
** DESC: swap values with the use of three assignment statement
** and no function or paramters.
** (｡◕‿◕｡)
*/

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
