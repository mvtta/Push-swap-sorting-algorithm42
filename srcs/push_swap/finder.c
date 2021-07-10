/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:38:46 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/07/10 17:11:18 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

long find_biggest(t_frame *frame, char id)
{
    long max = 0;
    if (id == 'a')
        frame->element = frame->a->head;
    else if (id == 'b')
        frame->element = frame->b->head;

    while (frame->element)
    {
        if (max < frame->element->value)
            max = frame->element->value;
        frame->element = frame->element->next;
    }
    return (find_position(frame, max, id));
}

long find_smallest(t_frame *frame, char id)
{
    long min;
    if (id == 'a')
        frame->element = frame->a->head;
    else if (id == 'b')
        frame->element = frame->b->head;
    min = frame->element->value;
    while (frame->element)
    {
        if (min > frame->element->value)
            min = frame->element->value;
        frame->element = frame->element->next;
    }
    return (find_position(frame, min, id));
}