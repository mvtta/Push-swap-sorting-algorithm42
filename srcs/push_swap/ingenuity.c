/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingenuity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:28:04 by user              #+#    #+#             */
/*   Updated: 2021/08/13 14:41:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

static int above_median(t_frame *frame, int median)
{
    frame->element = frame->a->head;
    int flag = 0;

    while (frame->element)
    {
        if (frame->element->value < median)
            flag += 1;
        frame->element = frame->element->next;
    }
    return (flag);
}

void split_stacks(t_frame *frame)
{
    int half;
    long median;

    frame->element = frame->a->head;
    half = frame->a->size / 2;
    frame->biggest = find_biggest(frame, 'a');
    frame->smallest = find_smallest(frame, 'a');
    median = find_median(frame, 'a');
    int flag = above_median(frame, median);

    while (flag > 0 && frame->a->size > 1)
    {
        if (frame->a->head->value < median)
            do_pb(frame);
        else
            do_ra(frame);
        show_stacks(frame);
    }
}

/* tagg this for the future
    printf("    median: %ld\n", median);
    printf("      flag: %d\n", flag); */


void get_ingenuity(t_frame *frame)
{
    t_stack_link *a_ele;
    t_stack_link *b_ele;

    a_ele = frame->a->head;
    b_ele = frame->b->head;
    partition(frame, 'a');
    solve_a(frame);
    solve_b(frame);
    merge(frame);
    /*     solve_a(frame, 'a');
    solve_b(frame, 'b');
    merge(frame); */
}