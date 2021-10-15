/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_gears.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:04:50 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/10/15 19:46:31 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void	split_in_chunks(t_frame *frame)
{
	int	j;
	int	rotate;

	j = 1;
	rotate = 0;
	while (j < frame->flags_size)
	{
		while (find_median(frame, 'a', frame->guide_flags[j]) != 0)
		{
			rotate = find_next(frame, 'a', frame->guide_flags[j]);
			while (rotate > 0)
			{
				do_ra(frame);
				rotate -= 1;
			}
			if (frame->a->head->value <= frame->guide_flags[j])
				do_pb(frame);
		}
		j += 1;
	}
}

void	put_sorted(t_frame *frame, int i)
{
	while (i > 0)
	{
		while (PUSH > 0)
		{
			do_rb(frame);
			PUSH -= 1;
		}
		if (frame->b->head->value == frame->guide[i])
		{
			do_pa(frame);
			i -= 1;
			PUSH = find_position(frame, frame->guide[i], 'b');
			while (PUSH > CHUNK)
			{
				do_rrb(frame);
				PUSH = find_position(frame, frame->guide[i], 'b');
				if (PUSH > frame->b->size)
				{
					PUSH = 0;
					break ;
				}
			}
		}
	}
}
