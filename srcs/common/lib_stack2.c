/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_stack2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:40:07 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/10/02 16:03:17 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void	stack_pop_back(t_stack_info *stack)
{
	t_stack_link	*to_del;

	to_del = stack->tail;
	stack->tail = stack->tail->prev;
	free(to_del);
	printf("new last : %p\n", stack->tail);
	stack->size--;
}

int	stack_top_peek(t_stack_info *stack)
{
	return (stack->head->value);
}

int	stack_tail_peek(t_stack_info *stack)
{
	return (stack->tail->value);
}
