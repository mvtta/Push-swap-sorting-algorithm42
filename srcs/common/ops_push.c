/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:22:35 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/10/15 21:25:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

/* sorry, norm made me do it */

int	do_pa(t_frame *frame)
{
	stack_push(frame->b, frame->a, frame->element);
	write(1, "pa\n", 3);
	return (0);
}

int	do_pb(t_frame *frame)
{
	stack_push(frame->a, frame->b, frame->element);
	write(1, "pb\n", 3);
	return (0);
}

int	do_rrr(t_frame *frame)
{
	do_ra(frame);
	do_rb(frame);
	write(1, "rrr\n", 4);
	return (0);
}
