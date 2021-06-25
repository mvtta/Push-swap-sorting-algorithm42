/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:56:15 by user              #+#    #+#             */
/*   Updated: 2021/06/26 00:39:38 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"
#include "../../libft/includes/libft.h"



void push_swap_error()
{
    write(2, "Error\n", 6);
    exit(-1);
}

int intdup(int to_check)
{
    static int space;
    int *save = malloc(sizeof(int) * space);
    if(!save)
        return(0);
    save[space + 1] = to_check;
    while(save)
    {
        if(*save == to_check)
            return(1);
        save++;
    }
    save[space + 1] = to_check;
    space += 1;
    return(0);
}

int error_check(int to_check)
{
    //printf("here\n");
    //printf("to check is : %i\n", to_check);
    if(ft_isalpha(to_check) == 1)
        push_swap_error();
    if(intdup(to_check) == 1)
        push_swap_error();
    return(0);
}
