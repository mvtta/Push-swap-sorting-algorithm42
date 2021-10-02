/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_stack4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:14:15 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/10/02 16:11:52 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void	stack_flip_a(t_frame *frame)
{
	frame->rotate = new_stack();
	frame->rotate->head = frame->a->tail;
	frame->element = frame->rotate->head;
	while (frame->a->tail)
	{
		frame->element = stack_add_front(frame->rotate, frame->a->tail->value);
		frame->a->tail = frame->a->tail->prev;
		frame->element = frame->element->next;
	}
	free(frame->a);
	frame->a = NULL;
	frame->a = frame->rotate;
}

void	stack_flip_b(t_frame *frame)
{
	frame->rotate = new_stack();
	frame->rotate->head = frame->b->tail;
	frame->element = frame->rotate->head;
	while (frame->b->tail)
	{
		frame->element = stack_add_front(frame->rotate, frame->b->tail->value);
		frame->b->tail = frame->b->tail->prev;
		frame->element = frame->element->next;
	}
	free(frame->b);
	frame->b = NULL;
	frame->b = frame->rotate;
}

int	stack_traverse(t_frame *frame, char id)
{
	if (id == 'a')
		frame->element = frame->a->head;
	else if (id == 'b')
		frame->element = frame->b->head;
	else
		return (-1);
	while (frame->element)
		frame->element = frame->element->next;
	return (0);
}
