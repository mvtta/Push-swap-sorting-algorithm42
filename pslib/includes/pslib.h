/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:22:33 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/25 23:27:55 by user             ###   ########.fr       */
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

typedef struct 	s_linked_list
{
	struct t_list *head;
}				t_linked_list;

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

#endif
