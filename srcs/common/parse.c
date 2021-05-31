/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:43:20 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/29 10:43:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "pslib.h"

int		main(int ac, char **av)
{
	int i = 0;
	int a = 1;
	t_list *head;
	t_list *node;
	t_list *stack_a;
	
	printf("\E[H\E[2J");
	while(av[a])
	{
		node = new_node(0);
		if(head == NULL)
		{
			head = node;
			stack_a = head;
		}
		else 
		{
			stack_a->next = new_node(ft_atoi(av[a++]));
			stack_a->next->prev = stack_a;
			stack_a = stack_a->next;
			//print_stack(stack_a->value, "stack a");
	}
	}
	print_info("stack_a");
	iterate(head);
	delete_ele(&head, 88);
	iterate(head);
	stack_a = head;
	while(stack_a != NULL)
	{
		print_stack(stack_a->value, "stack a");
		stack_a = stack_a->next;
	}
	print_info("stack_a");
	return(0);
}
