//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2linkedlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:52:58 by user              #+#    #+#             */
/*   Updated: 2021/05/26 12:16:26 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "/Users/mvaldeta/Documents/42Cursus/02.push_swap/pslib/includes/pslib.h"

t_list* new_node(int data)
{
    t_list *new;
    
    new = malloc(sizeof(t_list));
    new->value = data;
    new->prev = NULL;
    new->next = NULL;

    return(new);
}


