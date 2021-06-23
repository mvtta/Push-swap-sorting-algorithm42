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

#include "/Users/mvaldeta/02.push_swap/includes/pslib.h"

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
    while (argv[i])
    {
        element->next = stack_append(stack, element, ft_atoi(argv[i]));
        element = element->next;
        i++;
    }
/*     stack->head = fazer condição para guaradres o 1o */
    element = stack->head;
    while (element->next != NULL)
    {
        printf("%d\n", element->value);
/*         printf("next :%p\n", element->next);
        printf("node :%p\n\n", element); */
        element = element->next;
    }
    /*     frame = init_frame(frame, argv);

    int i = 0;
    stack = new_stack();
    element = new_link(i, stack);
    stack->head = element;
    printf("%d\n", element->value);
    while (i++ <= 10)
    {
        element->next = stack_append(stack, element, i);
        element = element->next;
    }
    element = stack->head;
    while (element->next != NULL)
    {
        printf("%d\n", element->value);
        printf("next :%p\n", element->next);
        printf("node :%p\n\n", element);
        element = element->next;
    }
    while (element != stack->tail)
    {
        printf("%d\n", element->value);
        printf("next :%p\n", element->next);
        printf("node :%p\n\n", element);
        element = element->next;
    }
    printf("size before pop: %d\n", stack->size);
    stack_pop_back(stack);
    printf("size after pop: %d\n", stack->size);
    printf("size before pop2: %d\n", stack->size);
    stack_pop_back(stack);
    printf("size after pop2: %d\n", stack->size);
    element = stack->head;
    printf("find value: %d\n", find_value(element, 7));
    element = stack->head;
    stack_pop_front(stack);
    printf("size after pop-front: %d\n", stack->size);
    element = stack->head;
    while (element != stack->tail)
    {
        printf("%d\n", element->value);
        printf("next :%p\n", element->next);
        printf("node :%p\n\n", element);
        element = element->next;
    } */
    return (0);
}