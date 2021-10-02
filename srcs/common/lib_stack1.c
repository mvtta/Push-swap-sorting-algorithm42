/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_stack1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:39:06 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/10/02 15:57:23 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

t_stack_link	*new_link(t_stack_info *stack, int data)
{
	t_stack_link	*new;

	new = malloc(sizeof(t_stack_link));
	new->value = data;
	new->prev = NULL;
	new->next = NULL;
	stack->size++;
	return (new);
}

t_stack_info	*new_stack(void)
{
	t_stack_info	*new;

	new = malloc(sizeof(t_stack_info));
	new->head = NULL;
	new->tail = NULL;
	new->size = 0;
	return (new);
}

void	stack_push(t_stack_info *src, t_stack_info *target, t_stack_link *new)
{
	t_stack_link	*new_head_t;
	t_stack_link	*old_head_t;

	if (!src)
		return ;
	if (target->size == 0)
	{
		target->head = stack_append(target, src->head->value);
		stack_pop_front(src);
		target->head->next = NULL;
		return ;
	}
	old_head_t = target->head;
	if (src->size == 1)
		new = NULL;
	if (src->size > 1)
		new = src->head->next;
	new_head_t = src->head;
	target->head->prev = new_head_t;
	new_head_t->next = old_head_t;
	src->head = new;
	target->head = new_head_t;
	old_head_t->prev = new_head_t;
	src->size -= 1;
	target->size += 1;
}

void	stack_pop_front(t_stack_info *stack)
{
	t_stack_link	*p;

	p = stack->head;
	stack->head = stack->head->next;
	p = NULL;
	stack->size--;
}

/* 	new_head_s = NULL;
	new_head_t = NULL;
	old_head_t = NULL; */