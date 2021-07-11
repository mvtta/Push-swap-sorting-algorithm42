/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:19:39 by user              #+#    #+#             */
/*   Updated: 2021/07/11 15:34:14 by user             ###   ########.fr       */
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
/*     print_the_stack(frame->a, frame->element);
    printf("------ Changement SA --------\n"); */
    //do_sa(frame->a);
    //print_the_stack(frame->a, frame->element);
/*     printf("------ Changement PB --------\n");
    //do_pb(frame);
    printf("------ Rotate A --------\n");
    //do_rra(frame);
    printf("------ Print Rotate --------\n");
    print_the_stack(frame->a, frame->element);
    printf("size is: %d\n", frame->a->size); */
 /*    printf("------ Find Biggest --------\n");
    long position;
    position = find_biggest(frame, 'a');
    printf("the position of the biggest is: %lu\n", position);
    printf("------ Find Smallest --------\n");
    position = find_smallest(frame, 'a');
    printf("the position of the smallest is: %lu\n", position); */
    printf("------ STACK a before solution --------\n");
    print_the_stack(frame->a, frame->element);
    printf("stack a head:%d\n", frame->a->head->value);
    classify(frame);
    printf("------ STACK a after pb --------\n");
    print_the_stack(frame->a, frame->element);
    printf("stack a head:%d\n", frame->a->head->value);
    printf("------ STACK b after pb --------\n");
    print_the_stack(frame->b, frame->element);
    printf("stack b head:%d\n", frame->b->head->value);
/*     printf("stack b head->next:%d\n", frame->b->head->next->value);
    printf("stack b next->next ptr:%p\n", frame->b->head->next->next);
    printf("stack b next->next ptr value:%d\n", frame->b->head->next->next->value); */
    printf("stack b size:%d\n", frame->b->size);
 /* classify(frame);
    printf("------ STACK a --------\n");
    print_the_stack(frame->a, frame->element);
    printf("stack a head:%d", frame->a->head->value);
    printf("------ STACK b --------\n");
    print_the_stack(frame->b, frame->element);
    printf("stack b head:%d", frame->b->head->value); */
    //check_sorted(frame->a, frame->element, frame->a->size);
    free(frame);
    frame = NULL;
    return (0);
}