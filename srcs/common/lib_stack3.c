/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_stack3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:40:51 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/10/02 16:10:43 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

t_stack_link	*stack_append(t_stack_info *stack, int i)
{
	t_stack_link	*to_insert;

	if (stack->head == NULL)
	{
		to_insert = new_link(stack, i);
		stack->head = to_insert;
		stack->tail = to_insert;
		stack->head->prev = NULL;
	}
	else
	{
		to_insert = new_link(stack, i);
		to_insert->prev = stack->tail;
		stack->tail->next = to_insert;
		stack->tail = to_insert;
		stack->tail->prev = to_insert->prev;
	}
	return (to_insert);
}

t_stack_link	*stack_add_front(t_stack_info *stack, int i)
{
	t_stack_link	*to_insert;

	to_insert = new_link(stack, i);
	to_insert->next = stack->head;
	to_insert->prev = NULL;
	stack->head = to_insert;
	return (to_insert);
}

int	find_value(t_stack_link *value, int the_one)
{
	while (value->value != the_one)
		value = value->next;
	if (value->value == the_one)
		return (value->value);
	else
		return (-33);
}

int	find_position(t_frame *frame, int the_one, char id)
{
	int	i;

	i = 0;
	if (id == 'a')
		frame->element = frame->a->head;
	if (id == 'b')
		frame->element = frame->b->head;
	while (frame->element)
	{
		if (frame->element->value == the_one)
			return (i);
		frame->element = frame->element->next;
		i += 1;
	}
	return (i);
}

void	print_the_stack(t_frame *frame, char id)
{
	int	i;

	i = 0;
	if (id == 'a')
	{
		frame->element = frame->a->head;
		i = frame->a->size;
	}
	if (id == 'b')
	{
		frame->element = frame->b->head;
		i = frame->b->size;
	}
	while (i != 0)
	{
		frame->element = frame->element->next;
		i--;
	}
}
