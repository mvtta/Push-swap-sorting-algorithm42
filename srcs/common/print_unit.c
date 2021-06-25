/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:25:46 by user              #+#    #+#             */
/*   Updated: 2021/06/25 22:36:32 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pslib.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

/* \E[H\E[2J = escape sequance to clear window */

int    print_stack(int stack, char *str)
{
    printf(" %d\n", stack);
    printf("%s\n", "----");
    printf("%s\n", str);
    return(0);  

}
int    print_info(char *str)
{
    printf("%s\n", "------       ------");
    printf("%s      stack b  ", str);
    return(0);  
}