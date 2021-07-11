/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingenuity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:28:04 by user              #+#    #+#             */
/*   Updated: 2021/07/11 22:36:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void get_ingenuity(t_frame *frame)
{
    t_stack_link *a_ele;
    t_stack_link *b_ele;

    a_ele = frame->a->head;
    b_ele = frame->b->head;
    if (a_ele->value > a_ele->next->value)
        do_sa(frame->a);
    if (b_ele->value < b_ele->next->value)
        do_sb(frame->b);
    while (check_sorted_a(frame) != SORTED && check_sorted_b(frame) != SORTED)
    {
        if (a_ele->value < a_ele->next->value)
            do_sa(frame->a);
        if (b_ele->value > b_ele->next->value)
            do_sb(frame->b);
    }
}