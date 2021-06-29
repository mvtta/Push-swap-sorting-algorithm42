/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:11:10 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/06/29 15:27:08 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/pslib.h"

int     do_sa(t_stack_info *label)
{
    t_stack_link *new_head;

    new_head = label->head->next;
    new_head->prev = NULL;
    label->head->prev = new_head;
    new_head->next = label->head;;
    //label->head = label->head->next;
    //exit(0);
    return(0);
}
/* int     do_sb(t_stack_info *label)
{
    
}
int     do_ss(t_stack_info *label)
{
    
}
int     do_pa(t_stack_info *label)
{
    
}
int     do_pb(t_stack_info *label)
{
    
}
int     do_ra(t_stack_info *label)
{
    
}
int     do_rb(t_stack_info *label)
{
    
}
int     do_rr(t_stack_info *label)
{
    
}
int     do_rra(t_stack_info *label)
{
    
}
int     do_rrb(t_stack_info *label)
{
    
}
int     do_rrr(t_stack_info *label)
{
    
} */