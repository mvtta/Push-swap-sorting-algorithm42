/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:22:33 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/06/01 16:25:52 by mvaldeta         ###   ########.fr       */
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

typedef struct			s_stack_link
{
	struct s_stack_link *prev;
	int					value;
	struct s_stack_link	*next;
}						t_stack_link;

/*
** Part 0.1 - Stack info
*/
typedef struct			s_stack_info
{
	struct s_stack_link	*head;
	struct s_stack_link	*tail;
	int					size;
	int					most_likely;	
}						t_stack_info;


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



/*
** 	Part 4 - Printing functions
*/

int		print_stack(int stack, char *str);
int		print_info(char *str);

#endif