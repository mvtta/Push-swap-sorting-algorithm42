/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:11:10 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/09/30 17:41:34 by mvaldeta         ###   ########.fr       */
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
    write(1, "sa\n", 3);
    return (0);
}

int do_sb(t_stack_info *label)
{
    t_stack_link *new_head;
    if (label->size == 1)
        return (0);
    new_head = label->head->next;
    new_head->prev = NULL;
    label->head->prev = new_head;
    label->head->next = label->head->next->next;
    new_head->next = label->head;
    label->head = new_head;
    write(1, "sb\n", 3);
    return (0);
}

int do_ss(t_stack_info *label)
{
    do_sa(label);
    do_sb(label);
    write(1, "ss\n", 3);
    return (0);
}

int do_pa(t_frame *frame)
{
    stack_push(frame->b, frame->a, frame->element);
    write(1, "pa\n", 3);
    return (0);
}

int do_pb(t_frame *frame)
{
    stack_push(frame->a, frame->b, frame->element);
    write(1, "pb\n", 3);
    return (0);
}

int do_ra(t_frame *frame)
{
    t_stack_link *new_tail;
    t_stack_link *new_head;

    if (frame->a->size <= 1)
        return (0);      
    new_tail = frame->a->head;
    new_tail->prev = frame->a->tail;
    new_head = frame->a->head->next;
    frame->a->head = NULL;
    frame->a->head = new_head;
    frame->a->tail->next = new_tail;
    frame->a->tail = new_tail;
    new_tail->next = NULL;
    write(1, "ra\n", 3);
    return (0);
}

int do_rb(t_frame *frame)
{
    t_stack_link *new_tail;
    t_stack_link *new_head;

    if (frame->b->size <= 1)
        return (0);
    new_tail = frame->b->head;
    new_tail->prev = frame->b->tail;
    new_head = frame->b->head->next;
    frame->b->head = NULL;
    frame->b->head = new_head;
    frame->b->tail->next = new_tail;
    frame->b->tail = new_tail;
    new_tail->next = NULL;
    write(1, "rb\n", 3);
    return (0);
}

int do_rr(t_frame *frame)
{
    do_ra(frame);
    do_rb(frame);
    write(1, "rr\n", 3);
    return (0);
}

int do_rra(t_frame *frame)
{
    t_stack_link *new_tail;
    t_stack_link *new_head;

    if (frame->a->size == 1)
        return (0);

    new_tail = frame->a->tail->prev;
    new_head = frame->a->tail;
    new_head->next = frame->a->head;
    frame->a->head = NULL;
    frame->a->head = new_head;
    frame->a->tail = new_tail;
    write(1, "rra\n", 4);
    return (0);
}

/* fix rra */

int do_rrb(t_frame *frame)
{
    t_stack_link *new_tail;
    t_stack_link *new_head;

    if (frame->b->size <= 1)
        return (0);

    new_tail = frame->b->tail->prev;
    new_head = frame->b->tail;
    new_head->next = frame->b->head;
    frame->b->head = NULL;
    frame->b->head = new_head;
    frame->b->tail = new_tail;
    write(1, "rrb\n", 4);
    return (0);
}

int do_rrr(t_frame *frame)
{
    do_ra(frame);
    do_rb(frame);
    write(1, "rrr\n", 4);
    return (0);
}