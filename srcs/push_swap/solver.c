/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:17:01 by user              #+#    #+#             */
/*   Updated: 2021/08/26 16:32:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

/* void algo(t_frame *frame)
{

} */

void do_solution_1(t_frame *frame)
{
    
}

/* void do_solution_2(t_frame *frame)
{

}

void do_solution_3(t_frame *frame)
{

} */

void solver(t_frame *frame)
{
    if(frame->a->size <= 10)
        do_solution_1(frame);
/*     else if(frame->a->size <= 100)
        do_solution_2(frame);
    else
        do_solution_3(frame); */
}