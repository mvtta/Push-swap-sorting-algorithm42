/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borala.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:59:31 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/31 13:46:48 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	int				value;
	//struct s_list 	*prev;
	struct s_list	*next;
}				t_list;

t_list	*stack_new_ele(int nb)
{
	t_list *new;
	new = malloc(sizeof(t_list));
	new->value = nb;
	new->next = NULL;
	
	return(new);	
}

void	stack_push(t_list  **head, t_list *node)
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

int	main(void)
{
	t_list *stack_a = NULL;
	t_list *stack_b = NULL;
	
	int nb = 9;
	stack_a = stack_new_ele(nb);
/* 	nb = 10;
	stack_push(&stack_a, stack_new_ele(nb));
	nb = 11;
	stack_push(&stack_a, stack_new_ele(nb)); */
	//stack_a->value = 9;

	t_list *head;
	head = stack_a;
	nb +=1;
	while(nb < 20)
	{
		printf("%d\n", stack_a->value);
		if (nb < 19)
		{
			stack_push(&stack_a, stack_new_ele(nb));
			stack_a = stack_a->next;			
		}
		nb++;
	}
	printf("head :%d\n", head->value);
	printf("tail :%d\n", stack_a->value);
	printf("escondido :%p\n", stack_a->next);
	return(0);
}