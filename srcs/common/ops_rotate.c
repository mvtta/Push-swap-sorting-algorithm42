/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:22:41 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/10/02 16:13:28 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

int	do_ra(t_frame *frame)
{
	t_stack_link	*new_tail;
	t_stack_link	*new_head;

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

int	do_rb(t_frame *frame)
{
	t_stack_link	*new_tail;
	t_stack_link	*new_head;

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

int	do_rr(t_frame *frame)
{
	do_ra(frame);
	do_rb(frame);
	write(1, "rr\n", 3);
	return (0);
}

int	do_rra(t_frame *frame)
{
	t_stack_link	*new_tail;
	t_stack_link	*new_head;

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

int	do_rrb(t_frame *frame)
{
	t_stack_link	*new_tail;
	t_stack_link	*new_head;

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
