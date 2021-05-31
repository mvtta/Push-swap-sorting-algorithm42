/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:43:20 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/31 12:52:25 by mvaldeta         ###   ########.fr       */
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
	
	//printf("\E[H\E[2J"); fix this key is commanding to clear screen
	while(av[a])
	{
			node = stack_new_node(0);
			stack_push(&head, node, stack_a, ft_atoi(av[a++]));
			//print_stack(stack_a->value, "stack a");
	}
	//print_info("stack_a");
	stack_size(head);
	stack_pop_key(&head, 88);
	stack_size(head);
	stack_a = head;
	while(stack_a != NULL)
	{
		print_stack(stack_a->value, "stack a");
		stack_a = stack_a->next;
	}
	//print_info("stack_a");
	return(0);
}
