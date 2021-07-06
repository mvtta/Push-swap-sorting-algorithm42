/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:11:10 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/07/06 21:29:10 by mvaldeta         ###   ########.fr       */
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
    frame->rotate->head = frame->a->head;
    frame->element = frame->rotate->head;
        
    while (frame->a->tail)
    {
        frame->element = stack_add_front(frame->rotate, frame->a->tail->value);
        printf("value on the top: %d\n", frame->rotate->head->value);
        frame->a->tail = frame->a->tail->prev;
        frame->element = frame->element->next;
    }
    free(frame->a);
    frame->a = NULL;
    frame->a = frame->rotate;
/*     printf("------ Print Rotate --------\n");
    t_stack_link *new = NULL;
    print_the_stack(frame->rotate, new); */
    return (0);
}

/* int do_ra(t_stack_info *label)
{
}
int do_rb(t_stack_info *label)
{
}
int do_rr(t_stack_info *label)
{
}
int do_rra(t_stack_info *label)
{
}
int do_rrb(t_stack_info *label)
{
}
int do_rrr(t_stack_info *label)
{
} */