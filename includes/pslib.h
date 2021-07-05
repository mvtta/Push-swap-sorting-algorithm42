/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:22:33 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/07/05 18:40:22 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSLIB_H
#define PSLIB_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include "../../libft/includes/libft.h"

/*
** Part 1 - Info frame in memory a + b
*/

typedef struct s_frame
{
	struct s_stack_info *a;
	struct s_stack_info *b;
	struct s_stack_info *rotate;
	struct s_stack_link *element;

	char				**argv;
	long				quarter;
	long				median;
	long				three_quarters;
	long				biggest;
	long				smallest;
	int					big_rotate;
	int					big_rrotate;
	int					big_flag;
	int					small_rotate;
	int					small_rrotate;
	int					small_flag;
	int					after_rotate;
	int					counter;
	int					*save;

} t_frame;

/*
** Macro-frame
*/

#define	SORTED			8
#define QUARTER			frame->quarter
#define MEDIAN			frame->median
#define THREE_Q			frame->three_quarters
#define BIGGEST			frame->biggest
#define BIG_ROTATE		frame->big_rotate
#define BIG_RROTATE 	frame->big_rrotate
#define BIG_FLAG		frame->big_flag
#define SMALLEST		frame->smallest
#define SMALL_ROTATE	frame->small_rotate
#define SMALL_RROTATE 	frame->small_rrotate
#define SMALL_FLAG		frame->small_flag
#define	A
#define	B
#define INDEX			frame->counter
#define NEW				frame->element->next
#define NEXT			frame->element->next
#define A_HEAD			frame->a->head
#define B_HEAD

/*
** handy-enumerations
*/

#define INSTRUCTIONS "sa sb ss pa pb ra rb rr rra rrb rrr"

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

typedef struct s_stack_link
{
	struct s_stack_link 	*prev;
	int 					value;
	struct s_stack_link 	*next;
} t_stack_link;

/*
** Part 0.1 - Stack info
*/

typedef struct s_stack_info
{
	struct s_stack_link 	*head;
	struct s_stack_link 	*tail;
	int						size;
} t_stack_info;


/*
** Funtion ptr aka jump table
*/

typedef void 	(*t_table)(t_frame *frame);

/*
** Checker functions
*/

void 			do_launch(t_frame *frame);
void 			sort_test(t_frame *frame);

/*
** Part 1 -	Libc functions
*/

int 			ft_atoi(const char *str);

/*
** 	Part 2 - Additional functions
*/

void 			ft_putchar_fd(char c, int fd);
void 			ft_putstr_fd(char *s, int fd);
void 			ft_putendl_fd(char *s, int fd);
void 			ft_putnbr_fd(int n, int fd);
char 			**ft_split(char const *s, char c);

/*
** 	Part 3 - Stack functions
*/

t_stack_info 	*new_stack(void);
t_stack_link 	*new_link(t_stack_info *stack, int data);
void 			stack_pop_front(t_stack_info *stack);
void 			stack_pop_back(t_stack_info *stack);
void stack_push(t_stack_info *source, t_stack_info *target, t_stack_link *new_head_s);
void 			stack_key_pop_push(t_stack_info *stack, t_stack_link *target);
int 			stack_top_peek(t_stack_info *stack);
int 			stack_tail_peek(t_stack_info *stack);
t_stack_link 	*stack_append(t_stack_info *stack, int i);
int				find_value(t_stack_link *value, int the_one);
void			print_the_stack(t_stack_info *stack, t_stack_link *element);

/*
** 	Part 4 - Printing functions
*/

int				print_stack(int stack, char *str);
int				print_info(char *str);

int 			error_check(int *array, int array_size, int to_check);
void 			push_swap_error();
t_frame 		*init_frame(t_frame *frame, char **argv);
int				process(const char *str);

/* identity */
int     		check_sorted(t_stack_info *label, t_stack_link *node, int size);
int				qprocess(const char *str);

/* instructions */

int     do_sa(t_stack_info *label);
int     do_sb(t_stack_info *label);
int     do_ss(t_stack_info *label);
int    	do_pa(t_frame *frame);
int 	do_pb(t_frame *frame);
int 	do_ra(t_frame *frame);
int     do_rb(t_stack_info *label);
int     do_rr(t_stack_info *label);
int     do_rra(t_stack_info *label);
int     do_rrb(t_stack_info *label);
int     do_rrr(t_stack_info *label);

#endif