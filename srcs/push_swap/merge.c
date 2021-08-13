/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 08:01:10 by user              #+#    #+#             */
/*   Updated: 2021/08/10 12:11:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void merge(t_frame *frame)
{
    while(frame->b->size != 0)
    {
        if(frame->b->size > 1 && frame->b->head < frame->b->tail)
            do_rrb(frame);
        do_pa(frame);
        if(frame->a->size > 1 && frame->a->head->value > frame->a->head->next->value)
            do_sa(frame->a);
        show_stacks(frame);
    }
}