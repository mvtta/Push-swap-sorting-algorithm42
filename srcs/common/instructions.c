/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:11:10 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/07/07 11:01:14 by user             ###   ########.fr       */
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
    frame->rotate = new_stack();
    frame->rotate->head = frame->a->tail;
    frame->element = frame->rotate->head;

    while (frame->a->tail)
    {
        frame->element = stack_add_front(frame->rotate, frame->a->tail->value);
        /*         printf("value on the top: %d\n", frame->rotate->head->value); */
        frame->a->tail = frame->a->tail->prev;
        frame->element = frame->element->next;
    }
    free(frame->a);
    frame->a = NULL;
    frame->a = frame->rotate;
    return (0);
}
int do_rb(t_frame *frame)
{
    frame->rotate = new_stack();
    frame->rotate->head = frame->b->tail;
    frame->element = frame->rotate->head;

    while (frame->b->tail)
    {
        frame->element = stack_add_front(frame->rotate, frame->b->tail->value);
        /*         printf("value on the top: %d\n", frame->rotate->head->value); */
        frame->b->tail = frame->b->tail->prev;
        frame->element = frame->element->next;
    }
    free(frame->b);
    frame->b = NULL;
    frame->b = frame->rotate;
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
    do_ra(frame);
    return (0);
}
int do_rrb(t_frame *frame)
{
    do_rb(frame);
    return (0);
}
int do_rrr(t_frame *frame)
{
    do_ra(frame);
    do_rb(frame);
    return (0);
}