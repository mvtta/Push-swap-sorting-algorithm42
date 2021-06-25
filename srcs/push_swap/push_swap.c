/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:19:39 by user              #+#    #+#             */
/*   Updated: 2021/06/26 00:28:41 by mvaldeta         ###   ########.fr       */
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
    frame->a = new_stack();
    frame->b = new_stack();
    frame->element = new_link(process(argv[1]), frame->a);
    COUNTER += 1;
    A_HEAD = frame->element;
    while (argv[COUNTER])
    {
        //printf("int is: %i", frame->element->value);
        error_check(frame->element->value);
        NEW = stack_append(frame->a, process(argv[COUNTER]));
        NEXT = frame->element->next;
        COUNTER++;
    }

    check_sorted(frame->a, frame->element);
    free(frame);
    frame = NULL;
    return (0);
}