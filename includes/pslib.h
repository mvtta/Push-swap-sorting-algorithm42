/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:22:33 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/07/12 13:41:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSLIB_H
#define PSLIB_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include <stdbool.h>
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
	int					do_visualizer;
	int					full;
	int 				instructions_only;

} t_frame;

/*
** Macro-frame
*/

#define TRUE			1
#define FALSE			0
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
#define	A				frame->a
#define	B				frame->b
#define INDEX			frame->counter
#define NEW				frame->element->next
#define NEXT			frame->element->next
#define A_HEAD			frame->a->head
#define B_HEAD			frame->b->head

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

void 			stack_pop_front(t_stack_info *stack);
void 			stack_pop_back(t_stack_info *stack);
void 			stack_push(t_stack_info *source, t_stack_info *target, t_stack_link *new_head_s);
void 			stack_key_pop_push(t_stack_info *stack, t_stack_link *target);
void			print_the_stack(t_stack_info *stack, t_stack_link *element);
int				stack_traverse(t_frame *frame, char id);
int 			stack_top_peek(t_stack_info *stack);
int 			stack_tail_peek(t_stack_info *stack);
int				find_value(t_stack_link *value, int the_one);
t_stack_link 	*stack_append(t_stack_info *stack, int i);
t_stack_link	*stack_add_front(t_stack_info *stack, int i);
t_stack_link 	*new_link(t_stack_info *stack, int data);
t_stack_info 	*new_stack(void);

/*
** 	Part 4 - Printing functions
*/

int				print_stack(int stack, char *str);
int				print_info(char *str);

int 			error_check(int *array, int array_size, int to_check);
int				process(const char *str);
void 			push_swap_error();
t_frame 		*init_frame(t_frame *frame, char **argv);

/* identity */
int				check_sorted_first(t_frame *frame);
int				check_sorted_a(t_frame *frame);
int    			check_sorted_b(t_frame *frame);
int				qprocess(const char *str);

/* instructions */

int     do_sa(t_stack_info *label);
int     do_sb(t_stack_info *label);
int     do_ss(t_stack_info *label);
int    	do_pa(t_frame *frame);
int 	do_pb(t_frame *frame);
int 	do_ra(t_frame *frame);
int     do_rb(t_frame *frame);
int     do_rr(t_frame *frame);
int     do_rra(t_frame *frame);
int     do_rrb(t_frame *frame);
int     do_rrr(t_frame *frame);

/* classify */
void	classify(t_frame *frame);

/* solutions */
void 	do_solution_1(t_frame *frame);

/* finder */
long 	find_biggest(t_frame *frame, char id);
long 	find_smallest(t_frame *frame, char id);
long	find_median(t_frame *frame, char id);
int		find_position(t_frame *frame, int the_one, char id);

/* ingenuity */
void    get_ingenuity(t_frame *frame);
void	split_stacks(t_frame *frame);

/* verify */
void    seek_veritas(t_frame *frame);

/* visualize */
void    visualize(t_frame * frame);
void    show_stacks(t_frame *frame);
void    print(t_stack_info *label, t_stack_link *ele, char id, int i);
void    stop_visualize(t_frame *frame);
void    clear_screen();
#endif

