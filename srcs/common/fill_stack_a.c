/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:56:15 by user              #+#    #+#             */
/*   Updated: 2021/06/23 12:53:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/mvaldeta/02.push_swap/includes/pslib.h"

void			push_swap_error(t_frame *frame)
{
	write(2, "Error\n", 6);
	exit(-1);
}

int             error_check(int to_check)
{
    long int test = 2147483647;
    int map[256] = {0};
    unsigned char c;

    c = (unsigned char)to_check;
    if(ft_isdigit(to_check) == 0 && 
        to_check >(-test + 1) && to_check < test)
        {
            map[c] += 1;
            if(map[c] < 2)
                return(0);
        }
    return(1);
}
