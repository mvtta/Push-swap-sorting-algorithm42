/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingenuity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:28:04 by user              #+#    #+#             */
/*   Updated: 2021/08/24 13:02:09 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

static int  above_median(t_frame *frame, int median)
{
    frame->element = frame->a->head;
    int flag = 0;

    while(frame->element)
    {
        if(frame->element->value < median)
            flag +=1;
        frame->element = frame->element->next;
    }
    return(flag);
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
        if(frame->a->tail->value == frame->biggest)
            break;
            /* instead of "break" send to solver a */ 
    }
}

/* tagg this for the future
    printf("    median: %ld\n", median);
    printf("      flag: %d\n", flag); */
    
/*     if (check_sorted_a(frame) == SORTED && check_sorted_b(frame) == SORTED)
    {
        if(frame->b->head->value > frame->a->head->value)
        {
            do_pb(frame);
            do_sb(frame->b);
            //do_pa(frame);
            while(frame->b->head)
                do_pa(frame);
        }
    } */

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
    while (check_sorted_a(frame) != SORTED && check_sorted_b(frame) != SORTED)
    {
        solve_b(frame);
        solve_a(frame);
    }
    merge(frame);
}