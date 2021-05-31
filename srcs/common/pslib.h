/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:22:33 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/29 10:26:22 by user             ###   ########.fr       */
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

typedef struct	s_list
{
	int				value;
	struct s_list 	*prev;
	struct s_list	*next;
}				t_list;


/*
** Part 1 - Libc functions
*/

int				ft_atoi(const char *str);

/*
** Part 2 - Additional functions
*/

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			**ft_split(char const *s, char c);

/*
**DLL costum funcs
*/

t_list* new_node(int data);
int    print_stack(int stack, char *str);
int    print_info(char *str);
int iterate(t_list *head);
void delete_ele(t_list **head_ref, int key);

#endif
