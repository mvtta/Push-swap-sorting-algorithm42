/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2linkedlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:52:58 by user              #+#    #+#             */
/*   Updated: 2021/05/25 23:27:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "/Users/mvaldeta/02.push_swap/pslib/includes/pslib.h"

t_list* new_node(int data)
{
    t_list *new;
    
    new = malloc(sizeof(t_list));
    new->value = data;
    new->prev = NULL;
    new->next = NULL;

    return(new);
}

t_linked_list* new_linked_list(int value)
{
    t_list *a;

    a = new_node(value);
    t_linked_list *l = malloc(sizeof(t_linked_list));
    l->head = a;

    return(l);
}

