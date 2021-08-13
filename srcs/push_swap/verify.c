/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 07:46:13 by user              #+#    #+#             */
/*   Updated: 2021/07/12 08:52:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void    seek_veritas(t_frame *frame)
{
    int *veritas_a = {FALSE};
    int *veritas_b = {FALSE};

    veritas_a = malloc(sizeof(int) * frame->a->size);
    veritas_b = malloc(sizeof(int) * frame->b->size);

    frame->element = frame->a->head;
    INDEX = 0;
    while(frame->element)
    {
        if(frame->element->value > frame->element->next->value)
            veritas_a[INDEX] = FALSE;
        else
            veritas_a[INDEX] = TRUE;
        INDEX+=1;
        frame->element = frame->element->next;
    }

    frame->element = frame->b->head;
    INDEX = 0;
    while(frame->element)
    {
        if(frame->element->value < frame->element->next->value)
            veritas_b[INDEX] = FALSE;
        else
            veritas_b[INDEX] = TRUE;
        INDEX+=1;
        frame->element = frame->element->next;
    }
}