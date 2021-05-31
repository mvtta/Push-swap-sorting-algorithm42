/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:22:33 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/31 11:39:43 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: none
** (｡◕‿◕｡)
*/

#ifndef PSLIB_H
# define PSLIB_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*
** Part 0 -	Stack node
*/

typedef struct	s_list
{
	int				value;
	struct s_list 	*prev;
	struct s_list	*next;
}				t_list;

/*
** Part 1 -	Libc functions
*/

int				ft_atoi(const char *str);

/*
** 	Part 2 - Additional functions
*/

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			**ft_split(char const *s, char c);

/*
** 	Part 3 - Stack functions
*/

t_list* stack_new_node(int data);
int		stack_size(t_list *head);
void    stack_push(t_list *head, t_list *node, t_list *stack_a, int data);
void	stack_pop_key(t_list **head_ref, int key);
void	stack_pop(t_list **head_ref, int key);
void	stack_peek(t_list **head_ref, int key);

/*
** 	Part 4 - Printing functions
*/

int		print_stack(int stack, char *str);
int		print_info(char *str);

#endif
