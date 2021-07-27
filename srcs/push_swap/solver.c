/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:16:38 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/07/24 17:20:36 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void partition(t_frame *frame, char stack_id)
{
    if(stack_id == 'a')
    {
        frame->element = frame->a->head;
        frame->parts_size = frame->a->size;
    }
    if(stack_id == 'b')
    {
        frame->element = frame->b->head;
        frame->parts_size = frame->b->size;
    }
    if (frame->parts_size <= 2)
        return;
    else
    {
        
    }
}

solve_recursive(t_frame *frame, char stack_id)
{

}

solve_a(t_frame *frame, char stack_id)
{
    solve_recursive(frame, 'a');
}

solve_b(t_frame *frame, char stack_id)
{
    solve_recursive(frame,'b');
}

