/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:38:46 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/08/26 13:44:58 by user             ###   ########.fr       */
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

long find_median(t_frame *frame, char id)
{
    long median = 0;

    if (id == 'a')
        median = BIGGEST - SMALLEST / frame->a->size;
    else if (id == 'b')
        median = BIGB - SMALLB / frame->b->size;;

    printf("BIG: %ld\n", BIGGEST);
    printf("median: %ld\n", median);
    printf("SMALLB: %ld\n", SMALLEST);
    printf("frame->a->size: %d\n", frame->a->size);
    return (median);
}