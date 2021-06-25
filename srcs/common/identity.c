/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:58:15 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/06/25 15:42:01 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

int     check_sorted(t_stack_info *label, t_stack_link *node)
{
    int counter;

    counter = label->size;
    node = label->head;
    if (counter == 1)
        exit(SORTED);
    while(counter-- != 0)
    {
        if(node->value < node->next->value)
            exit(SORTED); 
    }
    return(0);
}

