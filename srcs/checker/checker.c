/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:30:06 by user              #+#    #+#             */
/*   Updated: 2021/06/11 11:01:15 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/mvaldeta/02.push_swap/includes/pslib.h"

void        checker(t_frame *frame)
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
    frame = create_frame(frame, argv);
    checker(frame);
    return(0);
}

