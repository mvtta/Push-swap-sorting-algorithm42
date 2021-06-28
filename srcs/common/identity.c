/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:58:15 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/06/28 19:22:44 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

int     check_sorted(t_stack_info *label, t_stack_link *node)
{
    int counter;

    counter = label->size;
    int sorted = 0;
    if (counter == 1)
        exit(SORTED);
    node = label->head;
    while(counter-- != 0)
    {
        //printf("%d < %d\n", node->value, node->next->value);
        if(node->value < node->next->value)
            sorted+=1; 
        node = node->next;
    }
    if (sorted == counter)
        exit(SORTED);
    return(0);
}

