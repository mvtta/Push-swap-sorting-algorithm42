/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:39:05 by user              #+#    #+#             */
/*   Updated: 2021/07/23 15:21:17 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void do_solution_1(t_frame *frame)
{
    split_stacks(frame);
    show_stacks(frame);
    while(frame->b && check_sorted_a(frame) != SORTED)
    {
        get_ingenuity(frame);
    }
    //get_ingenuity(frame);
    //show_stacks(frame);
    /*     seek_veritas(frame);
    get_ingenuity(frame); */
    return;
}
/* 
Code Haiku, why not? */

/* TODO:
1. A function that checks if stack a has only elements above median
(for splitsacks) 🟢
2. A functions that counts the least amout of steps
not really sure if we're going that way anymore
3. Create operation optimizer: rra + rrb + rrr etc.
4. Create motion optimizer (BLIND METHOD)
*/ 