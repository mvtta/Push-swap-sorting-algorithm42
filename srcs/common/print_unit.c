/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:25:46 by user              #+#    #+#             */
/*   Updated: 2021/05/29 10:13:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"
#include <stdio.h>

/* \E[H\E[2J = escape sequance to clear window */

int    print_stack(int stack, char *str)
{
    printf(" %d\n", stack);
/*     printf("%s\n", "----");
    printf("%s\n", str); */
    return(0);  

}
int    print_info(char *str)
{
    printf("%s\n", "------       ------");
    printf("%s      stack b  ", str);
    return(0);  
}