/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:19:25 by user              #+#    #+#             */
/*   Updated: 2021/09/13 15:02:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void    clear_screen()
{
  const char *clear;

  clear = "\n\n\n\n\n\n\n\n\n\n";
  write(STDOUT_FILENO, clear, 10);
}

void    stop_visualize(t_frame *frame)
{
    frame->do_visualizer = 0;
}

void    print(t_stack_info *label, t_stack_link *ele, char id, int i)
{
    if (i < label->size)
    {
        if (id == 'a')
            printf("   %d", ele->value);
        if (id == 'b' && ele)
            printf("            %d\n", ele->value);
    }
    else
        printf("                \n");
}

void    show_stacks(t_frame *frame)
{
    const char      *top;
    t_stack_link    *a;
    t_stack_link    *b;
    
    top = "Stack A | Stack B\n\n";
    a = frame->a->head;
    b = frame->b->head;
    INDEX = 0; 
    clear_screen();
    write(STDOUT_FILENO, top, 20);
    while(INDEX < frame->a->size || INDEX < frame->b->size)
    {
        print(frame->a, a, 'a', INDEX);
        print(frame->b, b, 'b', INDEX);
        write(STDOUT_FILENO, "\n", 1);
        if(INDEX < frame->a->size)
            a = a->next;
        if(INDEX < frame->b->size)
            b = b->next;
        INDEX+=1;
    }

}

void    visualize(t_frame * frame)
{
    if(frame->do_visualizer)
    {
        //usleep(100000);
        if (frame->full)
        {
            //clear_screen();
            show_stacks(frame);
        }
    }
}  