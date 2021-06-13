/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:30:06 by user              #+#    #+#             */
/*   Updated: 2021/06/13 23:26:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/mvaldeta/02.push_swap/includes/pslib.h"

void        do_checker(t_frame *frame)
{
    fill_stack_a(frame);
    do_launch(frame);
    sort_test(frame);
    push_swap_free(frame);
}

int     main(int argc, char **argv)
{
    t_frame     *frame;

    frame = NULL;
    if(argc > 2)
        return(1);
    frame = init_frame(frame, argv);
    do_checker(frame);
    return(0);
}

