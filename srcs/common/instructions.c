/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:11:10 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/07/23 15:00:17 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

int do_sa(t_stack_info *label)
{
    t_stack_link *new_head;

    new_head = label->head->next;
    new_head->prev = NULL;
    label->head->prev = new_head;
    label->head->next = label->head->next->next;
    new_head->next = label->head;
    label->head = new_head;
    return (0);
}

int do_sb(t_stack_info *label)
{
    t_stack_link *new_head;

    new_head = label->head->next;
    new_head->prev = NULL;
    label->head->prev = new_head;
    label->head->next = label->head->next->next;
    new_head->next = label->head;
    label->head = new_head;
    return (0);
}

int do_ss(t_stack_info *label)
{
    do_sa(label);
    do_sb(label);
    return (0);
}

int do_pa(t_frame *frame)
{
    stack_push(frame->b, frame->a, frame->element);
    return (0);
}

int do_pb(t_frame *frame)
{
    stack_push(frame->a, frame->b, frame->element);
    return (0);
}

int do_ra(t_frame *frame)
{
    t_stack_link *new_tail;
    t_stack_link *new_head;

    new_tail = frame->a->head;
    new_head = frame->a->head->next;
    frame->a->head = NULL;
    frame->a->head = new_head;
    frame->a->tail->next = new_tail;
    frame->a->tail = new_tail;
    new_tail->next = NULL;
    return (0);
}

int do_rb(t_frame *frame)
{
    t_stack_link *new_tail;
    t_stack_link *new_head;

    new_tail = frame->b->head;
    new_head = frame->b->head->next;
    frame->b->head = NULL;
    frame->b->head = new_head;
    frame->b->tail->next = new_tail;
    frame->b->tail = new_tail;
    new_tail->next = NULL;
    return (0);
}

int do_rr(t_frame *frame)
{
    do_ra(frame);
    do_rb(frame);
    return (0);
}

int do_rra(t_frame *frame)
{
    t_stack_link *new_tail;
    t_stack_link *new_head;

    if(frame->a->size == 1)
        return(0);

    if (frame->a->tail->prev)
        new_tail = frame->a->tail->prev;
    else
        new_tail = NULL;
    new_head = frame->a->tail;
    new_head->next = frame->a->head;
    frame->a->head = NULL;
    frame->a->head = new_head;
    frame->a->tail = new_tail;
    if (frame->a->tail)
        frame->a->tail->next = NULL;
    return (0);
}

/* fix rra */

int do_rrb(t_frame *frame)
{
    t_stack_link *new_tail;
    t_stack_link *new_head;

    new_tail = frame->b->tail->prev;
    new_head = frame->b->tail;
    new_head->next = frame->b->head;
    frame->b->head = NULL;
    frame->b->head = new_head;
    frame->b->tail = new_tail;
    //frame->b->tail->next = NULL;
    return (0);
}

int do_rrr(t_frame *frame)
{
    do_ra(frame);
    do_rb(frame);
    return (0);
}