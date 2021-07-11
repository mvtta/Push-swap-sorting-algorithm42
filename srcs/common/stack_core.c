/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:14:15 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/07/11 15:36:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../includes/pslib.h"
#include "../../libft/includes/libft.h"

t_stack_link *new_link(t_stack_info *stack, int data)
{
	t_stack_link *new;
	new = malloc(sizeof(t_stack_link));

	new->value = data;
	new->prev = NULL;
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

void stack_push(t_stack_info *source, t_stack_info *target, t_stack_link *new_head_s)
{
	t_stack_link *new_head_t;
	t_stack_link *old_head_t;

	if (target->size == 0)
	{
		target->head = stack_append(target, source->head->value);
		stack_pop_front(source);
		return;
	}
	new_head_s = NULL;
	new_head_t = NULL;
	old_head_t = NULL;
	old_head_t = target->head;
	new_head_s = source->head->next;
	new_head_t = source->head;
	target->head->prev = new_head_t;
	new_head_t->next = old_head_t;
	source->head = new_head_s;
	target->head = new_head_t;
	old_head_t->prev = new_head_t;
	source->size -=1;
	target->size +=1;
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

t_stack_link *stack_append(t_stack_info *stack, int i)
{
	t_stack_link *to_insert = NULL;

	if (stack->head == NULL)
	{
		//printf("here1\n");
		to_insert = new_link(stack, i);
		stack->head = to_insert;
		stack->tail = to_insert;
		stack->head->prev = NULL;
	}
	else
	{
		//printf("here2\n");
		to_insert = new_link(stack, i);
		to_insert->prev = stack->tail;
		stack->tail->next = to_insert;
		stack->tail = to_insert;
	}
	return (to_insert);
}

t_stack_link *stack_add_front(t_stack_info *stack, int i)
{
	t_stack_link *to_insert = NULL;

	to_insert = new_link(stack, i);
	to_insert->next = stack->head;
	to_insert->prev = NULL;
	stack->head = to_insert;

	return (to_insert);
}

int find_value(t_stack_link *value, int the_one)
{
	while (value->value != the_one)
		value = value->next;
	return (value->value);
}

int find_position(t_frame *frame, int the_one, char id)
{
	int i;

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

void print_the_stack(t_stack_info *stack, t_stack_link *element)
{
	element = stack->head;
	/* 	printf("stack head:  %d\n", stack->head->value);
	printf("stack head->next:  %d\n", stack->head->next->value); */
	while (element)
	{
		printf("element value:%d\n", element->value);
		printf("next ptr:%p\n", element->next);
		printf("current node ptr:%p\n\n", element);
		element = element->next;
	}
}

void stack_flip_a(t_frame *frame)
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
}

void stack_flip_b(t_frame *frame)
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
}

int stack_traverse(t_frame *frame, char id)
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