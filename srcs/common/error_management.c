/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:56:15 by user              #+#    #+#             */
/*   Updated: 2021/09/30 16:58:19 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void push_swap_error()
{
    write(2, "Error\n", 6);
    exit(-1);
}

int error_check(int *array, int array_size, long to_check)
{
    int freq = 0;
    int i = 0;
    if(to_check > 2147483647 || to_check <= -2147483648)
		push_swap_error();
    if(!array)
        return(0);
    if(array_size == 1)
        return(0);
    while(i < array_size)
    {
        if(array[i] == to_check)
            freq+=1;
        i++;
    }
    if(freq > 1)
        push_swap_error();
    return(0);
}

