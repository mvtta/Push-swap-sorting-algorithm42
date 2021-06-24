/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:22:33 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/06/23 13:23:18 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSLIB_H
# define PSLIB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
#include "../../libft/includes/libft.h"

/*
** Macro-frame
*/

# define QUARTER frame->quarter
# define MEDIAN frame->median
# define THREE_Q frame->three_quarters
# define BIGGEST frame->biggest
# define BIG_ROTATE frame->big_rotate
# define BIG_RROTATE frame->big_rrotate
# define BIG_FLAG frame->big_flag
# define SMALLEST frame->smallest
# define SMALL_ROTATE frame->small_rotate
# define SMALL_RROTATE frame->small_rrotate
# define SMALL_FLAG frame->small_flag

/*
** handy-enumerations
*/

# define INSTRUCTIONS "sa sb ss pa pb ra rb rr rra rrb rrr"

typedef enum e_ins
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	END_INS
} t_ins;


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
}						t_stack_info;

/*
** Part 1 - Info frame in memory a + b
*/

typedef struct 			s_frame
{
	struct s_stack_info	*a;
	struct s_stack_info	*b;

	char				**argv;
	char				*line;
	char				*str;

	int					print_stacks;
	int					do_write;
	
	long				quarter;
	long				median;
	long				three_quarters;

	long				biggest;
	int					big_rotate;
	int					big_rrotate;
	int					big_flag;

	long				smallest;
	int					small_rotate;
	int					small_rrotate;
	int					small_flag;

	int					after_rotate;

}						t_frame;

/*
** Funtion ptr aka jump table
*/

typedef void			(*t_table)(t_frame	*frame);


/*
** Checker functions
*/

void					do_launch(t_frame	*frame);
void					sort_test(t_frame	*frame);

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

t_stack_info *new_stack(void);
t_stack_link *new_link(int data, t_stack_info *stack);
void stack_pop_front(t_stack_info *stack);
void stack_pop_back(t_stack_info *stack);
void stack_key_pop_push(t_stack_info *stack, t_stack_link *target);
int stack_top_peek(t_stack_info *stack);
int stack_tail_peek(t_stack_info *stack);
t_stack_link *stack_append(t_stack_info *stack, t_stack_link *new, int i);
int find_value(t_stack_link *value, int the_one);
void	print_the_stack(t_stack_info *stack, t_stack_link *element, char id);


/*
** 	Part 4 - Printing functions
*/

int		print_stack(int stack, char *str);
int		print_info(char *str);


int             error_check(int to_check);
void			push_swap_error();
t_frame         *init_frame(t_frame *frame, char **argv);



#endif