/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:56:15 by user              #+#    #+#             */
/*   Updated: 2021/06/13 23:26:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/mvaldeta/02.push_swap/includes/pslib.h"

void			push_swap_error(t_frame *frame)
{
	write(2, "Error\n", 6);
	push_swap_free(frame);
	exit(-1);
}

/* int     duplicates(int  bucket[])
{
    
} */

int             error_check(int to_check)
{
    long int test = 2147483647;
    int map[256] = {0};
    unsigned char c;

    c = (unsigned char)to_check;
    if(ft_is_digit(to_check) == 0 && 
        to_check >(-test + 1) && to_check < test)
        {
            map[c] += 1;
            if(map[c] < 2)
                return(0);
        }
    return(1);
}

void            fill_stack_a(t_frame *frame, t_stack_info *info)
{

}