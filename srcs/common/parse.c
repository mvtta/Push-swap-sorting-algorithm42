/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:43:20 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/26 14:04:59 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "/Users/mvaldeta/Documents/42Cursus/02.push_swap/pslib/includes/pslib.h"

int		main(int ac, char **av)
{
	int i = 0;
	int a = 1;
	t_list *head;
	t_list *node;
	t_list *stack_a;

	while(av[a])
	{
		node = new_node(0);
		if(head == NULL)
		{
			head = node;
			stack_a = head;
		}
		else {
			stack_a->next = new_node(ft_atoi(av[a++]));
			stack_a->next->prev = stack_a;
			stack_a = stack_a->next; 
			printf("%d\n", stack_a->value);
		}
	}
	return(0);
}
