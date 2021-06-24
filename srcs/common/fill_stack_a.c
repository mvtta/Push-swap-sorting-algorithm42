/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:56:15 by user              #+#    #+#             */
/*   Updated: 2021/06/23 12:53:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"
#include "../../libft/includes/libft.h"

void push_swap_error()
{
    write(2, "Error\n", 6);
    exit(-1);
}

int error_check(int to_check)
{
    long int test = 2147483647;
    int map[256] = {0};
    unsigned char c;

    printf("arrived in function: %d\n", to_check);
    c = (unsigned char)to_check;
    if (map[c] == 1)
        push_swap_error();
    if (ft_isalpha(to_check))
        push_swap_error();
    if (!map[c])
        map[c] = 1;
return (0);
}
