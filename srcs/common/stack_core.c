/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:14:15 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/06/11 20:02:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "/Users/mvaldeta/02.push_swap/includes/pslib.h"

t_stack_link *new_link(int data, t_stack_info *stack)
{
	t_stack_link *new;
	new = malloc(sizeof(t_stack_link));

	new->value = data;
	new->prev = new->next;
	new->next = NULL;
	stack->size++;

	return (new);
}

t_stack_info *new_stack(void)
{
	t_stack_info *new;

	new = malloc(sizeof(t_stack_info));
	new->head = NULL;
	new->tail = NULL;
	new->size = 0;

	return (new);
}

static inline t_stack_link **find_link(t_stack_info *stack, t_stack_link *target)
{
	t_stack_link **p = &stack->head;

	while ((*p) && (*p) != target)
		p = &(*p)->next;
	return p;
}

void stack_pop_front(t_stack_info *stack)
{
	t_stack_link *p;

	p = stack->head;
	stack->head = stack->head->next;
	free(p);
	stack->size--;
}

void stack_pop_back(t_stack_info *stack)
{
	t_stack_link *to_del;

	to_del = stack->tail;
	stack->tail = stack->tail->prev;
	free(to_del);
	printf("new last : %p\n", stack->tail);
	stack->size--;
}

void stack_key_pop_push(t_stack_info *stack, t_stack_link *target)
{
	t_stack_link **p = find_link(stack, target);
	*p = target->next;
	free(&target);
	stack->size--;
}

int stack_top_peek(t_stack_info *stack)
{
	return (stack->head->value);
}
int stack_tail_peek(t_stack_info *stack)
{
	return (stack->tail->value);
}

t_stack_link *stack_append(t_stack_info *stack, t_stack_link *new, int i)
{
	t_stack_link *to_insert;
	to_insert = new_link(i, stack);
	to_insert->prev = stack->tail;
	stack->tail = to_insert;

	return (to_insert);
}§

int find_value(t_stack_link *value, int the_one)
{
	while (value->value != the_one)
		value = value->next;
	return (value->value);
}


/* int main(void)
{
	t_stack_info *stack = NULL;
	t_stack_link *element = NULL;
	int i = 0;
	stack = new_stack();
	element = new_link(i, stack);
	stack->head = element;
	printf("%d\n", element->value);
	while (i++ <= 10)
	{
		element->next = stack_append(stack, element, i);
		element = element->next;
	}
	element = stack->head;
	while(element->next != NULL)
	{
		printf("%d\n", element->value);
		printf("next :%p\n", element->next);
		printf("node :%p\n\n", element);
		element = element->next;
	}
	while (element != stack->tail)
	{
		printf("%d\n", element->value);
		printf("next :%p\n", element->next);
		printf("node :%p\n\n", element);
		element = element->next;
	}
	printf("size before pop: %d\n", stack->size);
	stack_pop_back(stack);
	printf("size after pop: %d\n", stack->size);
	printf("size before pop2: %d\n", stack->size);
	stack_pop_back(stack);
	printf("size after pop2: %d\n", stack->size);
	element = stack->head;
	printf("find value: %d\n", find_value(element, 7));
	element = stack->head;
	stack_pop_front(stack);
	printf("size after pop-front: %d\n", stack->size);
	element = stack->head;
	while (element != stack->tail)
	{
		printf("%d\n", element->value);
		printf("next :%p\n", element->next);
		printf("node :%p\n\n", element);
		element = element->next;
	}
} */