/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:17:01 by user              #+#    #+#             */
/*   Updated: 2021/09/20 12:59:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

/* void algo(t_frame *frame)
{

} */

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void make_guide(t_frame *frame)
{
    frame->element = frame->a->head;
    frame->guide = malloc(frame->a->size * sizeof(int));
    frame->guide_size = frame->a->size;
    int i = 0;
    if (frame->guide == NULL)
        return;
    while (i < frame->a->size)
    {
        frame->guide[i] = frame->element->value;
        //printf("GUIDE: %d\n", frame->guide[i]);
        frame->element = frame->element->next;
        i++;
    }
    i = -1;
    int j = 0;
    while (i++ < frame->a->size)
    {
        j = i + 1;
        while (j < frame->a->size)
        {
            if (j == frame->a->size)
                break;
            if (frame->guide[j] < frame->guide[i])
                swap(&frame->guide[j], &frame->guide[i]);
            j++;
        }
    }
    i = 0;
    while (i < frame->a->size)
    {
        //printf("GUIDE: %d\n", frame->guide[i]);
        i++;
    }
}

void do_solution_1(t_frame *frame)
{
    if (frame->a->size == 2)
    {
        if (frame->a->head->value > frame->a->head->next->value)
            do_sa(frame->a);
        return;
    }
    if (frame->a->size == 3)
    {
            if (frame->a->head->value > frame->a->head->next->value && frame->a->head->next->value < frame->a->tail->value)
                do_ra(frame);
            if (frame->a->head->value > frame->a->head->next->value)
                do_sa(frame->a);
            if (frame->a->tail->value < frame->a->head->value)
                do_rra(frame);
        return;
    }
    if (frame->a->size > 3)
    {
        MEDIANA = frame->guide[frame->guide_size / 2];
        /*         printf("MEDIANA: %ld\n", MEDIANA);
        exit(0); */
        int index = frame->guide_size / 2;
        while (index > 0)
        {
            if (frame->a->head->value < MEDIANA)
            {
                do_pb(frame);
                index--;
            }
            if (frame->a->head->next->value < MEDIANA)
            {
                do_sa(frame->a);
                do_pb(frame);
                index--;
            }
            else
                do_ra(frame);
        }
        if (frame->a->size == 2)
        {
            if (frame->a->head->value > frame->a->head->next->value)
                do_sa(frame->a);
        }
        if (frame->a->size == 3)
        {
                if (frame->a->tail->value < frame->a->head->value)
                    do_ra(frame);
                if (frame->a->head->value > frame->a->head->next->value)
                    do_sa(frame->a);
                if(frame->a->tail->value < frame->a->head->next->value)
                {
                    do_rra(frame);
                    do_sa(frame->a);
                } 
        }
        while (frame->b)
        {
            PUSH = find_position(frame, find_biggest(frame, 'b'), 'b');
            while (frame->b->head->value != find_biggest(frame, 'b'))
                do_rb(frame);
            if (frame->b->head->value == find_biggest(frame, 'b'))
                do_pa(frame);
            if (frame->b->size < 1)
                break;
        }
    }
}

void do_solution_2(t_frame *frame)
{
    do_solution_3(frame);
        return;
}

void do_solution_3(t_frame *frame)
{
    int i = frame->guide_size - 1;
    while (frame->a->size != 0)
        do_pb(frame);
    //print_the_stack(frame->b, frame->element);
    PUSH = find_position(frame, frame->guide[i], 'b');
    while (PUSH != -1)
    {
        /* calculate cheapest rb/rrb*/
        do_rb(frame);
        if (frame->b->head->value == frame->guide[i])
        {
            do_pa(frame);
            i--;
            PUSH = find_position(frame, frame->guide[i], 'b');
        }
        if (frame->b->size == 1)
        {
            do_pa(frame);
            PUSH = -1;
        }
    }
}

void solver(t_frame *frame)
{
    make_guide(frame);
    //do_solution_3(frame);
    //print_the_stack(frame->b, frame->element);

    if (frame->a->size <= 5)
        do_solution_1(frame);
    else if (frame->a->size <= 100)
        do_solution_2(frame);
    else
        do_solution_3(frame);
    //print_the_stack(frame);
}