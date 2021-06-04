/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:14:15 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/06/04 19:29:34 by mvaldeta         ###   ########.fr       */
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
	new->prev = new->next;
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
	t_stack_link *to_del;
	t_stack_link *newtail;

	printf("node received : %d\n", out->value);
	to_del = stack->tail;
	stack->tail = stack->tail->prev;
	newtail = stack->tail->prev;
	printf("last : %d", to_del->value);
	printf("new last : %d", newtail->value);
	//free(to_del);
/* 	free(out->prev);
	free(out->next);
	free(&out->value); */
	stack->size--;
}

void			stack_key_pop_push(t_stack_info *stack, t_stack_link *target)
{
	t_stack_link **p = find_link(stack, target);
	*p = target->next;
	free(&target);
	stack->size--;
}

int	stack_top_peek(t_stack_info *stack)
{
		return(stack->head->value);

}
int	stack_tail_peek(t_stack_info *stack)
{
		return(stack->tail->value);
}

t_stack_link			*stack_append(t_stack_info *stack, t_stack_link *new, int i)
{
	t_stack_link *to_insert;
	to_insert = new_link(i, stack);
	to_insert->prev = stack->tail;
	stack->tail = to_insert;

	return(to_insert);
}

int		main(void)
{
	t_stack_info *stack = NULL;
	t_stack_link *element = NULL;
	int i = 0;

	stack = new_stack();
	element =  new_link(i, stack);
	stack->head = element;
	//printf("%d\n", element->value);
	while(i++ <= 10)
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
	stack_pop_back(stack, element);
	printf("head:%d\n", stack->head->value);
	printf("peek head:%d\n", stack_top_peek(stack));
	printf("tail:%d\n", stack->tail->value);
	printf("peek tail:%d\n", stack_tail_peek(stack));
/* 	element = stack->head;
	stack_pop_back(stack, element+=1);
	while(element->next != NULL)
	{
		printf("%d\n", element->value);
		printf("next :%p\n", element->next);
		printf("node :%p\n\n", element);
		element = element->next;
	} */
/* 	printf("head:%d", stack->head->value);
	printf("tail:%d", stack->tail->value); */

}