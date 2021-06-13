#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#include "pslib.h"

typedef struct	s_list
{
	int				value;
	struct s_list 	*prev;
	struct s_list	*next;
}				t_list;

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

t_list *stack_new_node(int data)
{
    t_list *new;

    new = malloc(sizeof(t_list));
    new->value = data;
    new->prev = NULL;
    new->next = NULL;

    return (new);
}

void    stack_push(t_list **head, t_list *node, t_list *stack_a, int data)
{
    if (*head == NULL)
    {
        *head = node;
        stack_a = *head;
    }
    else
    {
        stack_a->next = stack_new_node(data);
        stack_a->next->prev = stack_a;
        stack_a = stack_a->next;
    }
}

int stack_size(t_list *head)
{
    int tr;
    t_list *p = head;
    tr = -1;
    while (p != NULL)
    {
        //printf("%d", p->value);
        p = p->next;
        tr++;
    }
    printf("\n\nlist len:%d", tr);
    return (tr);
}

void stack_pop_key(t_list **head_ref, int key)
{
    // Store head node
    t_list *temp = *head_ref, *prev;
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->value == key)
    {
        *head_ref = temp->next; // Changed head
        free(temp);             // free old head
        return;
    }
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->value != key)
    {
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

int		main(int ac, char **av)
{
	int i = 0;
	int a = 1;
	t_list *head;
	t_list *node;
	t_list *stack_a;
	
	//printf("\E[H\E[2J");
	while(av[a])
	{		node = stack_new_node(0);
			//return(1);
			stack_push(&head, node, stack_a, ft_atoi(av[a++]));
			//print_stack(stack_a->value, "stack a");
			a++;
	}
	//return(1);	//print_info("stack_a");
	//stack_size(head);
	//stack_pop_key(&head, 88);
	//stack_size(head);
	stack_a = head;
	while(stack_a != NULL)
	{
		//print_stack(stack_a->value, "stack a");
		stack_a = stack_a->next;
	}
	//print_info("stack_a");
	return(0);
}