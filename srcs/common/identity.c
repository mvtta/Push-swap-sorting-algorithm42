/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:58:15 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/06/28 23:41:02 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

int     check_sorted(t_stack_info *label, t_stack_link *node, int size)
{

    int sorted = 0;
    if (size == 1)
    {
        printf("is sorted, only one value: exit");
        exit(SORTED);
    }
    node = label->head;
    while(node->next)
    {
        if(node->value < node->next->value)
            sorted+=1; 
        node = node->next;
    }
    if (sorted == size - 1)
    {
        printf("is sorted: exit");
        exit(SORTED);
    }
    return(0);
}

