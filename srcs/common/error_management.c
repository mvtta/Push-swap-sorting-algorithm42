/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:56:15 by user              #+#    #+#             */
/*   Updated: 2021/06/28 20:11:33 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"
#include "../../libft/includes/libft.h"



void push_swap_error()
{
    write(2, "Error\n", 6);
    exit(-1);
}

int error_check(int *array, int array_size, int to_check)
{
    if(!array)
        return(0);
    if(array_size == 1)
        return(0);
    int i = 0;
    while(i < array_size)
    {
        if(array[i] == to_check)
            push_swap_error();
        i++;
    }
    return(0);
}

/* 
int error_check(t_frame *frame, int to_check)
{
    if(ft_isalpha(to_check) == 1)
        push_swap_error();
    if(intdup(frame, to_check) == 1)
        push_swap_error();
    return(0);
} */
