/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:19:39 by user              #+#    #+#             */
/*   Updated: 2021/06/23 13:26:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"
#include "../../libft/includes/libft.h"

int main(int argc, char **argv)
{
    t_frame *frame;
    t_stack_info *stack = NULL;
    t_stack_link *element = NULL;
    frame = NULL;
    if (argc < 2)
        return (1);
    int i = 1;
    stack = new_stack();
    element = new_link(ft_atoi(argv[1]), stack);
    i += 1;
    stack->head = element;
    while (argv[i])
    {
        //printf("%d\n", element->value);
        if(error_check(element->value) == 1)
            return(printf("error"));
        element->next = stack_append(stack, element, ft_atoi(argv[i]));
        element = element->next;
        i++;
    }
    element = stack->head;
    while (element->next != NULL)
    {
        printf("%d\n", element->value);
        element = element->next;
    }

/*     todo:
    1)make checker work: error has several probs but someting is there
    2)re-arrange init frame 
    3)at last decide strategy, don't do anymore reserach */
    return (0);
}