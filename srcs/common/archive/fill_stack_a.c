/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:56:15 by user              #+#    #+#             */
/*   Updated: 2021/06/12 12:41:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/mvaldeta/02.push_swap/includes/pslib.h"

void			push_swap_error(t_frame *frame)
{
	write(2, "Error\n", 6);
	push_swap_free(frame);
	exit(-1);
}

int     duplicates(int  bucket[], size_t bucket_size)
{
    
}

int             error_check(int to_check, char **argv)
{
    long int test = 2147483647;
    if(ft_is_digit(to_check) == 0 && 
        to_check > -(test + 1) && to_check < to_check)
        return(0);
    return(1);
}

void            fill_stack_a(t_frame *frame, t_stack_info *info)
{

}