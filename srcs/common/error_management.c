/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:56:15 by user              #+#    #+#             */
/*   Updated: 2021/09/22 15:34:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"

void push_swap_error()
{
    write(2, "Error\n", 6);
    exit(-1);
}

int error_check(int *array, int array_size, int to_check)
{
    int freq = 0;
    int i = 0;
    
    if(!array)
        return(0);
    if(array_size == 1)
        return(0);
    while(i < array_size + 1)
    {
        if(array[i] == to_check)
            freq+=1;
        i++;
    }
    if(freq > 1)
        push_swap_error();
    return(0);
}

