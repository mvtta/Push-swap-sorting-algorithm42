/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:17:01 by user              #+#    #+#             */
/*   Updated: 2021/10/15 19:43:34 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void	do_small(t_frame *frame)
{
	if (frame->a->size > 3)
	{
		MEDIANA = frame->guide[frame->guide_size / 2];
		do_loop_small(frame);
		if (frame->a->size == 2)
			do_small_2(frame);
		if (frame->a->size == 3)
			do_the_trick(frame);
		while (frame->b)
		{
			PUSH = find_position(frame, find_biggest(frame, 'b'), 'b');
			while (frame->b->head->value != find_biggest(frame, 'b'))
				do_rb(frame);
			if (frame->b->head->value == find_biggest(frame, 'b'))
				do_pa(frame);
			if (frame->b->size < 1)
				break ;
		}
	}
}

void	do_medium(t_frame *frame)
{
	int	i;

	i = frame->guide_size - 1;
	while (frame->a->size != 0)
		do_pb(frame);
	PUSH = find_position(frame, frame->guide[i], 'b');
	while (PUSH != -1)
	{
		do_rb(frame);
		if (frame->b->head->value == frame->guide[i])
		{
			do_pa(frame);
			i--;
			PUSH = find_position(frame, frame->guide[i], 'b');
		}
		if (frame->b->size == 1)
		{
			do_pa(frame);
			PUSH = -1;
		}
	}
	return ;
}

void	do_large(t_frame *frame)
{
	int	i;

	make_guide_flags(frame);
	split_in_chunks(frame);
	while (frame->a->size != 0)
		do_pb(frame);
	i = frame->guide_size - 1;
	PUSH = find_position(frame, frame->guide[i], 'b');
	put_sorted(frame, i);
	do_pa(frame);
	return ;
}

void	solver(t_frame *frame)
{
	make_guide(frame);
	if (frame->a->size == 2)
		do_small_2(frame);
	if (frame->a->size == 3)
		do_small_3(frame);
	else if (frame->a->size <= 5)
		do_small(frame);
	else if (frame->a->size <= 60)
		do_medium(frame);
	else
		do_large(frame);
}
