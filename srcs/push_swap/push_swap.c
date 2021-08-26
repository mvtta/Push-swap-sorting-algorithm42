/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:19:39 by user              #+#    #+#             */
/*   Updated: 2021/08/26 15:36:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

int main(int argc, char **argv)
{
    t_frame *frame;

    if (argc < 2)
        return (1);
    frame = NULL;
    frame = init_frame(frame, argv);
    int temp[argc - INDEX];
    frame->a = new_stack();
    frame->b = new_stack();
    int i = 1;
    while (argv[i])
    {
        frame->element = stack_append(frame->a, process(argv[i]));
        temp[INDEX] = frame->element->value;
        INDEX++;
        error_check(temp, INDEX, frame->element->value);
        frame->element = frame->element->next;
        i++;
    }
    solver(frame);
    free(frame);
    return (0);
}