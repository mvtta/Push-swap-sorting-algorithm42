/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:38:46 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/09/27 15:30:35 by user             ###   ########.fr       */
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
    return (max);
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
    return (min);
}

long find_median(t_frame *frame, char id, long median)
{
    int has = 0;
    if (id == 'a')
        frame->element = frame->a->head;
    if (id == 'b')
        frame->element = frame->b->head;
    while(frame->element)
    {
        if(frame->element->value < median)
            has += 1;
        frame->element = frame->element->next;
    }
    return (has);
}

int find_next(t_frame *frame, char id, int flag)
{
    int i = 0;
    if (id == 'a')
        frame->element = frame->a->head;
    if (id == 'b')
        frame->element = frame->b->head;
    while(frame->element)
    {
        if(frame->element->value <= flag)
            return (i);
        frame->element = frame->element->next;
        i++;
    }
    return (-1);
}