/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_guide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:25:01 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/10/15 19:51:56 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	make_loop(t_frame *frame)
{
	while (frame->i < frame->a->size)
	{
		frame->guide[frame->i] = frame->element->value;
		frame->element = frame->element->next;
		frame->i++;
	}
}

void	make_guide(t_frame *frame)
{
	frame->element = frame->a->head;
	frame->guide = malloc(frame->a->size * sizeof(int));
	frame->guide_size = frame->a->size;
	frame->i = 0;
	if (frame->guide == NULL)
		return ;
	make_loop(frame);
	frame->i = -1;
	frame->j = 0;
	while (frame->i++ < frame->a->size)
	{
		frame->j = frame->i + 1;
		while (frame-> j < frame->a->size)
		{
			if (frame->j == frame->a->size)
				break ;
			if (frame->guide[frame->j] < frame->guide[frame->i])
				swap(&frame->guide[frame->j], &frame->guide[frame->i]);
			frame->j++;
		}
	}
	frame->i = 0;
}

void	make_guide_flags(t_frame *frame)
{
	int	size;

	frame->i = 0;
	frame->j = 0;
	size = 0;
	if (frame->guide_size <= 100)
		CHUNK = 10;
	if (frame->guide_size > 100)
		CHUNK = 25;
	size = frame->a->size / CHUNK;
	frame->flags_size = size;
	frame->guide_flags = malloc(size * sizeof(int));
	if (frame->guide_flags == NULL)
		return ;
	while (frame->i < frame->a->size && frame->j < frame->a->size / CHUNK)
	{
		if (frame->i % CHUNK == 0)
		{
			frame->guide_flags[frame->j] = frame->guide[frame->i];
			frame->j += 1;
		}
		frame->i += 1;
	}
}
