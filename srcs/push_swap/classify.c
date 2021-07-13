/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:17:01 by user              #+#    #+#             */
/*   Updated: 2021/07/12 08:21:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void classify(t_frame *frame)
{
    if(frame->a->size <= 5)
        do_solution_1(frame);
/*     else if(frame->a->size <= 100)
        do_solution_2();
    else
        do_solution_3(); */
}