//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2linkedlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:52:58 by user              #+#    #+#             */
/*   Updated: 2021/05/26 12:16:26 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "pslib.h"

t_list* new_node(int data)
{
    t_list *new;
    
    new = malloc(sizeof(t_list));
    new->value = data;
    new->prev = NULL;
    new->next = NULL;

    return(new);
}

int iterate(t_list *head)
{
    int tr;
    t_list *p = head;
    tr = -1;
    while(p != NULL)
    {
        //printf("%d", p->value);
        p = p->next;
        tr++;
    }
    printf("\n\nlist len:%d", tr);
    return(tr);
}

void delete_ele(t_list **head_ref, int key)
{
    // Store head node
    t_list *temp = *head_ref, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->value == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->value != key) {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    free(temp); // Free memory
}


