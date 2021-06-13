/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borala.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:59:31 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/06/01 15:30:32 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct 	s_stack
{
	int				size;
	t_list			*head;
	t_list			*tail;

}				t_stack;

t_list	*stack_new_ele(int nb)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	new->value = nb;
	new->prev = NULL;
	new->next = NULL;
	return(new);	
}

/* inserT @ last */
void	stack_pop(t_list  **head, t_list *node)
{
	t_list *tmp;
	
	tmp = *head;
	if(*head == NULL)
	{
		*head = node;
		return;		
	}
	while(!tmp)
	{
		tmp = tmp->next;
	}
	tmp->next = node;
}

/* insert @ front */
t_list	*stack_push(t_list 	*tmpelem, t_list *node, t_stack *stack)
{
	t_stack *tmpstack = NULL;
	
/* 	if(stack->head == NULL)
	{
		stack->head = node;
		return(node);
	} */
	return(tmpelem);
}

int	main(void)
{
	t_list *stack_a = NULL;
	t_list *stack_b = NULL;
	t_stack *a = malloc(sizeof(t_stack));
	
	int nb = 9;
	stack_a = stack_new_ele(nb);
/* 	nb = 10;
	stack_push(&stack_a, stack_new_ele(nb));
	nb = 11;
	stack_push(&stack_a, stack_new_ele(nb)); */
	//stack_a->value = 9;

	t_list *head;
	head = stack_a;
	a->head = head;
	nb +=1;
	while(nb < 20)
	{
		//printf("%d\n", stack_a->value);
		if (nb < 19)
		{
			//stack_pop(&stack_a, stack_new_ele(nb));
			stack_push(stack_a, stack_new_ele(nb), a);
			//stack_a = stack_a->prev;			
		}
		nb++;
	}
	printf("head :%d\n", head->value);
	printf("tail :%d\n", stack_a->value);
	printf("escondido :%p\n", stack_a->next);
	printf("prev :%p\n", stack_a->prev);
	return(0);
}