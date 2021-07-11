/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:39:05 by user              #+#    #+#             */
/*   Updated: 2021/07/11 22:39:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void do_solution_1(t_frame *frame)
{
    int half;
    long median;

    frame->element = frame->a->head;
    half = frame->a->size / 2;
    frame->biggest = find_biggest(frame, 'a');
    frame->smallest = find_smallest(frame, 'a');
    median = find_median(frame, 'a');
    printf("---------MEDIAN: %lu--------\n", median);
    while (frame->element)
    {
        if(frame->element->value >= median)
        {
            do_pb(frame);
            frame->element = frame->a->head;
        }
        else
            frame->element = frame->element->next;
    }
    get_ingenuity(frame);

    /*         do_pb(frame); */
    //printf("stack b head:%d\n", frame->b->head->value);
    return;
}