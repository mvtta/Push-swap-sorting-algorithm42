/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:14:15 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/06/02 12:51:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "pslib.h"

t_stack_link 	*new_link(int data, t_stack_info *stack)
{
	t_stack_link *new;
	new = malloc(sizeof(t_stack_link));

	new->value = data;
	new->prev = NULL;
	new->next = NULL;
	stack->size++;

	return(new);
}

t_stack_info	*new_stack(void)
{
	t_stack_info	*new;

	new = malloc(sizeof(t_stack_info));
	new->head = NULL;
	new->tail = NULL;
	new->size = 0;

	return(new);
}

static inline t_stack_link  **find_link(t_stack_info *stack, t_stack_link *target)
{
	t_stack_link **p = &stack->head;
	
	while((*p) && (*p) != target)
		p = &(*p)->next;
	return p;
}

void			stack_push(t_stack_info *stack, t_stack_link *current, t_stack_link *new)
{
	stack->head = new->prev;
	new->next = current->prev;
	stack->size++;
}

void			stack_pop_front(t_stack_info *stack, t_stack_link *out)
{
	t_stack_link **p;

	*p = out->next;
	stack->head = (*p);
	free(&out);
	stack->size--;
	
}

void			stack_pop_back(t_stack_info *stack, t_stack_link *out)
{
	t_stack_link **p;

	*p = out->prev;
	stack->tail = (*p);
	free(&out);
	stack->size--;
}

void			stack_key_pop_push(t_stack_info *stack, t_stack_link *target)
{
	t_stack_link **p = find_link(stack, target);
	*p = target->next;
	free(&target);
	stack->size--;
}

int	*stack_top_peek(t_stack_info *stack)
{
		return(&stack->head->value);

}
int	*stack_tail_peek(t_stack_info *stack)
{
		return(&stack->tail->value);
}

int		main(void)
{
	t_stack_info *stack = NULL;
	t_stack_link *element = NULL;
	int i = 0;

	stack = new_stack();
	while(i++ < 10)
	{
		element =  new_link(i, stack);
		printf("%d\n", element->value);
	}
	while(stack->head != NULL)
	{
		printf("%lu\n", stack->head);
		stack->head->next;
	}
	printf("size:%d", stack->size);
/* 	printf("head:%d", stack->head->value);
	printf("tail:%d", stack->tail->value); */

}