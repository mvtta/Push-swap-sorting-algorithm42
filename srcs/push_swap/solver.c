/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:16:38 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/08/24 12:49:42 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void partition(t_frame *frame, char stack_id)
{
    frame->element = frame->a->head;

    if (frame->parts_size <= 2)
        return;
    frame->biggest = find_biggest(frame, stack_id);
    find_median(frame, 'a');
    while (1)
    {
        if (frame->element->value <= 10)
            do_pb(frame);
        if (frame->a->size <= 3)
            break;
        else if (check_sorted_a(frame)!= SORTED)
            break;
        else
            do_ra(frame);
    }
    visualize(frame);
}

void solve_a(t_frame *frame)
{
    if (frame->a->size == 1)
        return;
    do_pyramid(frame, 'a');
}

void solve_b(t_frame *frame)
{
    do_inverted_pyramid(frame, 'b');
    //undo_hourglass();
}

void do_pyramid(t_frame *frame, char stack_id)
{
    if (stack_id == 'a')
        frame->element = frame->a->head;
    BIGGEST = find_biggest(frame, 'a');
    SMALLEST = find_smallest(frame, 'a');
    MEDIAN = find_median(frame, 'a');
    printf("BIG: %ld\n", BIGGEST);
    printf("MEDIAN: %ld\n", MEDIAN);
    printf("SMALLB: %ld\n", SMALLEST);
    //exit(0);
    while (check_sorted_a(frame) != SORTED)
    {
        if(frame->a->head->value < MEDIAN)
            do_pb(frame);
        else
            do_ra(frame);
        exit(0);
    }
}

void do_inverted_pyramid(t_frame *frame, char stack_id)
{
    if (stack_id == 'b')
        frame->element = frame->b->head;
    BIGB = find_biggest(frame, 'b');
    frame->small_b = find_smallest(frame, 'b');
    MEDIANB = find_median(frame, 'b');
    printf("BIG: %d\n", BIGB);
    printf("MEDIAN: %ld\n", MEDIANB);
    printf("SMALLB: %ld\n", frame->small_b);
    BIG_ROTATE = find_position(frame, BIGGEST, 'b');
    while (frame->b->tail->value != BIGB)
    {
        if (frame->a->head->value < MEDIANB)
            do_sb(frame->b);
        else
            do_rb(frame);
    }
}
