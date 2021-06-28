/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:28:25 by user              #+#    #+#             */
/*   Updated: 2021/06/11 19:35:30 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

t_frame *init_frame(t_frame *frame, char **argv)
{
    frame = malloc(sizeof(t_frame));
    if (!frame)
        exit(1);
    frame->a = NULL;
    frame->b = NULL;
    frame->argv = argv;
    QUARTER = 0;
    MEDIAN = 0;
    THREE_Q = 0;
    BIGGEST = 0;
    BIG_ROTATE = 0;
    BIG_RROTATE = 0;
    BIG_FLAG = 0;
    SMALLEST = 0;
    SMALL_ROTATE = 0;
    SMALL_RROTATE = 0;
    SMALL_FLAG = 0;
    COUNTER = 0;
    frame->after_rotate = 0;
    return (frame);
}
