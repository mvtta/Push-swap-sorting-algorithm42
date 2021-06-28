/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:19:39 by user              #+#    #+#             */
/*   Updated: 2021/06/28 20:29:43 by mvaldeta         ###   ########.fr       */
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
    //int *temp = malloc(sizeof(int) * COUNTER);
    int temp[argc - COUNTER];
    frame->a = new_stack();
    frame->b = new_stack();
    int i = 1;
    frame->element = new_link(process(argv[i]), frame->a);
    A_HEAD = frame->element;
    temp[COUNTER] = frame->element->value;
    COUNTER+=1;
    while (argv[i])
    { 
        frame->element->next = stack_append(frame->a, process(argv[i]));
        error_check(temp, COUNTER, frame->element->next->value);
        temp[COUNTER] = frame->element->value;
        frame->element = frame->element->next;
        COUNTER++;
        i++;
    }
    int j = 1;
    while(j < argc)
    {
        printf(" array[%d] is equal to -> %d\n", j, temp[j]);
        j++;
    }
    frame->element = A_HEAD;
    print_the_stack(frame->a, frame->element);
    free(frame);
    frame = NULL;
    return (0);
}