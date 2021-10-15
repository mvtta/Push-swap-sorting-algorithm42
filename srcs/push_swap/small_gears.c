/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_gears.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:45:07 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/10/15 19:45:19 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void	do_small_2(t_frame *frame)
{
	if (frame->a->head->value > frame->a->head->next->value)
		do_sa(frame->a);
	return ;
}

void	do_small_3(t_frame *frame)
{
	if (frame->a->head->value > frame->a->head->next->value
		&& frame->a->head->next->value < frame->a->tail->value)
		do_ra(frame);
	if (frame->a->head->value > frame->a->head->next->value)
		do_sa(frame->a);
	if (frame->a->tail->value < frame->a->head->value)
		do_rra(frame);
	return ;
}

void	do_loop_small(t_frame *frame)
{
	int	index;

	index = frame->guide_size / 2;
	while (index > 0)
	{
		if (frame->a->head->value < MEDIANA)
		{
			do_pb(frame);
			index--;
		}
		if (frame->a->head->next->value < MEDIANA)
		{
			do_sa(frame->a);
			do_pb(frame);
			index--;
		}
		else
			do_ra(frame);
	}
}

void	do_the_trick(t_frame *frame)
{
	if (frame->a->tail->value < frame->a->head->value)
		do_ra(frame);
	if (frame->a->head->value > frame->a->head->next->value)
		do_sa(frame->a);
	if (frame->a->tail->value < frame->a->head->next->value)
	{
		do_rra(frame);
		do_sa(frame->a);
	}
}
