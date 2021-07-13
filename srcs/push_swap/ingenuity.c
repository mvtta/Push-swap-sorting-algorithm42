/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingenuity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:28:04 by user              #+#    #+#             */
/*   Updated: 2021/07/12 16:22:33 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void split_stacks(t_frame *frame)
{
    int half;
    long median;
    //int moves;

    frame->element = frame->a->head;
    half = frame->a->size / 2;
    frame->biggest = find_biggest(frame, 'a');
    frame->smallest = find_smallest(frame, 'a');
    median = find_median(frame, 'a');
    //moves = half;
    while (check_sorted_a(frame) != SORTED)
    {
        if (frame->a->head->value < median)
            do_pb(frame);
        else
            do_rra(frame);
    }
    if (check_sorted_a(frame) == SORTED && check_sorted_b(frame) == SORTED)
    {
        if(frame->b->head->value > frame->a->head->value)
        {
            do_pb(frame);
            do_sb(frame->b);
            //do_pa(frame);
            while(frame->b->head)
                do_pa(frame);
        }
    }
}

/* This is definitly not optimal, 
but my fried brain thinks 
this is ok for now. 
@35 i need a better breaking option asap
update: fixed it */

void get_ingenuity(t_frame *frame)
{
    t_stack_link *a_ele;
    t_stack_link *b_ele;

    a_ele = frame->a->head;
    b_ele = frame->b->head;
    if (a_ele->value > a_ele->next->value)
        do_sa(frame->a);
    if (b_ele->value < b_ele->next->value)
        do_sb(frame->b);
    while (check_sorted_a(frame) != SORTED && check_sorted_b(frame) != SORTED)
    {
        if (a_ele->value < a_ele->next->value)
            do_sa(frame->a);
        if (b_ele->value > b_ele->next->value)
            do_sb(frame->b);
    }
}