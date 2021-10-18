/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:22:33 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/10/15 22:01:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSLIB_H
# define PSLIB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../../libft/includes/libft.h"

/*
** Part 1 - Info frame in memory a + b
*/

typedef struct s_frame
{
	struct s_stack_info	*a;
	struct s_stack_info	*b;
	struct s_stack_info	*rotate;
	struct s_stack_link	*element;

	int					*save;
	char				**argv;
	int					*guide;
	int					*guide_flags;
	int					guide_size;
	int					flags_size;
	int					to_push;
	int					chunk;
	long				big_a;
	long				big_b;
	long				quarter;
	long				median_a;
	long				median_b;
	long				small_a;
	long				small_b;
	int					counter;
	int					i;
	int					j;

}	t_frame;

/*
** Macro-frame
*/

# define TRUE 1
# define FALSE 0
# define SORTED 8
# define A frame->a
# define B frame->b
# define A_HEAD frame->a->head
# define B_HEAD frame->b->head
# define MEDIANA frame->median_a
# define MEDIANB frame->median_b
# define INDEX frame->counter
# define NEW frame->element->next
# define NEXT frame->element->next
# define BIGA frame->big_a
# define BIGB frame->big_b
# define SMALLA frame->small_a
# define SMALLB frame->small_b
# define PUSH frame->to_push
# define CHUNK frame->chunk

/*
STACK LIB
*/

/*
** Part 0 -	Stack node
*/
typedef struct s_stack_link
{
	struct s_stack_link	*prev;
	struct s_stack_link	*next;
	int	 				value;
}	t_stack_link;

/*
** Part 1 - Stack info
*/
typedef struct s_stack_info
{
	struct s_stack_link	*head;
	struct s_stack_link	*tail;
	int					size;
}	t_stack_info;

/*
** Part 2 - Struct for merge aux flags
*/
typedef struct s_flags
{
	int		top1_flag;
	int		top2_flag;
	int		bottom1_flag;
	int		bottom2_flag;

}	t_flags;

/*
** 	Part 3 - Stack functions
*/
void			stack_pop_front(t_stack_info *stack);
void			stack_pop_back(t_stack_info *stack);
void			stack_push(t_stack_info *src, t_stack_info *t, t_stack_link *n);
void			stack_key_pop_push(t_stack_info *stack, t_stack_link *target);
void			print_the_stack(t_frame *frame, char id);
int				stack_traverse(t_frame *frame, char id);
int				stack_top_peek(t_stack_info *stack);
int				stack_tail_peek(t_stack_info *stack);
int				find_value(t_stack_link *value, int the_one);
t_stack_link	*stack_append(t_stack_info *stack, int i);
t_stack_link	*stack_add_front(t_stack_info *stack, int i);
t_stack_link	*new_link(t_stack_info *stack, int data);
t_stack_info	*new_stack(void);

/* init frame */
t_frame			*init_frame(t_frame *frame, char **argv);

/* print unit */
void			push_swap_error(void);
int				print_stack(int stack, char *str);
int				print_info(char *str);
int				error_check(int *array, int array_size, long to_check);
int				process(const char *str);

/* identity */
int				check_sorted_first(t_frame *frame);
int				check_sorted_a(t_frame *frame);
int				check_sorted_b(t_frame *frame);
int				qprocess(const char *str);

/* instructions */
int				do_sa(t_stack_info *label);
int				do_sb(t_stack_info *label);
int				do_ss(t_stack_info *label);
int				do_pa(t_frame *frame);
int				do_pb(t_frame *frame);
int				do_ra(t_frame *frame);
int				do_rb(t_frame *frame);
int				do_rr(t_frame *frame);
int				do_rra(t_frame *frame);
int				do_rrb(t_frame *frame);
int				do_rrr(t_frame *frame);

/* aux_guide */
void			swap(int *xp, int *yp);
void			make_loop(t_frame *frame);
void			make_guide(t_frame *frame);
void			make_guide_flags(t_frame *frame);

/* solver */
void			solver(t_frame *frame);
void			do_small(t_frame *frame);
void			do_medium(t_frame *frame);
void			do_large(t_frame *frame);

/* make */
void			make_guide_flags(t_frame *frame);
void			make_guide(t_frame *frame);

/* finder */
long			find_biggest(t_frame *frame, char id);
long			find_smallest(t_frame *frame, char id);
long			find_median(t_frame *frame, char id, long median);
int				find_position(t_frame *frame, int the_one, char id);
int				find_next(t_frame *frame, char id, int flag);

/* visualize */
void			visualize(t_frame *frame);
void			show_stacks(t_frame *frame);
void			print(t_stack_info *label, t_stack_link *ele, char id, int i);
void			stop_visualize(t_frame *frame);
void			clear_screen(void);

/* small gears*/
void			do_small_2(t_frame *frame);
void			do_small_3(t_frame *frame);
void			do_loop_small(t_frame *frame);
void			do_the_trick(t_frame *frame);

/* large gears*/
void			split_in_chunks(t_frame *frame);
void			put_sorted(t_frame *t_frame, int i);

#endif
