/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:17:01 by user              #+#    #+#             */
/*   Updated: 2021/09/30 18:09:21 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

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
    /*     while (i < frame->a->size)
    {
        printf("GUIDE: %d\n", frame->guide[i]);
        i++;
    }
    exit(0); */
}

void make_guide_flags(t_frame *frame)
{
    int i = 0;
    int j = 0;
    int size = 0;
    if (frame->guide_size <= 100)
        CHUNK = 10;
    if (frame->guide_size > 100)
        CHUNK = 25;
    size = frame->a->size / CHUNK;
    frame->flags_size = size;
    frame->guide_flags = malloc(size * sizeof(int));
    if (frame->guide_flags == NULL)
        return;
    while (i < frame->a->size && j < frame->a->size / CHUNK)
    {
        if (i % CHUNK == 0)
        {
            frame->guide_flags[j] = frame->guide[i];
            j += 1;
        }
        i += 1;
    }
    /*     j = 0;
    while (j < size)
    {
        printf("FLAGS: %d\n", frame->guide_flags[j]);
        j++;
    }
    exit(0); */
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
            if (frame->a->tail->value < frame->a->head->next->value)
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
    return;
}

void do_solution_3(t_frame *frame)
{
    make_guide_flags(frame);
    int j = 1;
    int rotate = 0;
    while (j < frame->flags_size)
    {
        while (find_median(frame, 'a', frame->guide_flags[j]) != 0)
        {
            rotate = find_next(frame, 'a', frame->guide_flags[j]);
            while (rotate > 0)
            {
                do_ra(frame);
                rotate -= 1;
            }
            if (frame->a->head->value <= frame->guide_flags[j])
                do_pb(frame);
        }
        j += 1;
    }
    while (frame->a->size != 0)
        do_pb(frame);

    /*   ~~~~~~~~~ */
    /*  OPS : 500  */
    /*   ~~~~~~~~~ */

    int i = frame->guide_size - 1;
    PUSH = find_position(frame, frame->guide[i], 'b');
    while (i > 0)
    {
        while (PUSH > 0)
        {
            do_rb(frame);
            PUSH -= 1;
        }
        if (frame->b->head->value == frame->guide[i])
        {
            do_pa(frame);
            i -= 1;
            PUSH = find_position(frame, frame->guide[i], 'b');
            while (PUSH > CHUNK)
            {
                do_rrb(frame);
                PUSH = find_position(frame, frame->guide[i], 'b');
                if (PUSH > frame->b->size)
                {
                    PUSH = 0;
                    break;
                }
            }
        }
    }
    do_pa(frame);
    return;
}

void do_solution_4(t_frame *frame)
{
    do_solution_3(frame);
}

void solver(t_frame *frame)
{
    make_guide(frame);
    if (frame->a->size <= 5)
        do_solution_1(frame);
    else if (frame->a->size <= 60)
        do_solution_2(frame);
    else if (frame->a->size <= 100)
        do_solution_3(frame);
    else
        do_solution_4(frame);
    //print_the_stack(frame, 'a');
    /*     if(check_sorted_a(frame))
        printf("OK");
    else
        printf("KO"); */
}