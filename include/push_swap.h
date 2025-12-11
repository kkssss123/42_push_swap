/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:03:14 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/11 09:35:43 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define ATOB 0
# define BTOA 1

# include "../libft/libft.h"
# include "stdbool.h"

typedef struct s_node
{
	int				num;
	struct s_node	*next;
}	t_node;

/**
 * PRINT_A:		print operations for stack a (sa, sa, ra, rra)
 * PRINT_B: 	print operations for stack b (sb, pb, rb, rrb)
 * PRINT_BOTH: 	print dual operations (ss, rr, rrr)
 * PRINT_NONE: 	suppress printing operations (used for checker / ss, rr, rrr)
 */
typedef enum e_print_mode {
	PRINT_A,
	PRINT_B,
	PRINT_BOTH,
	PRINT_NONE
}	t_print_mode;

typedef enum e_error {
	ERR_MALLOC,
	INVALID_INPUT,
	ERR_DUPLICATE,
	ERR_DEBUG,
}	t_error;

void		error_exit(t_error err);
void		print_op(t_print_mode mode, char *op_a, char *op_b);
/* node operations */
t_node		*ps_lstnew(int num);
t_node		*ps_lstlast(t_node *lst);
int			ps_lstsize(t_node *lst);
void		ps_lstadd_back(t_node **lst, t_node *new);
void		ps_lstclear(t_node **lst);
int			get_min(t_node *lst);
int			get_max(t_node *lst);
int			get_index(t_node *lst, int num);
/* stack operations */
void		sx(t_node **top, t_print_mode mode);
void		ss(t_node **a, t_node **b, t_print_mode mode);
void		px(t_node **from, t_node **to, t_print_mode mode);
void		rx(t_node **top, t_print_mode mode);
void		rr(t_node **a, t_node **b, t_print_mode mode);
void		rrx(t_node **top, t_print_mode mode);
void		rrr(t_node **a, t_node **b, t_print_mode mode);

long long	ps_atoi(const char *str);
t_node		*init_stack(int argc, char **argv);
bool		contains_duplicate(t_node *head);
bool		is_sorted(t_node *head);
void		sort(t_node **stack_a);

int			get_min_rotate_atob(t_node *stack_a, t_node *stack_b);
int			count_rotate_atob(t_node *stack_b, int num);
int			count_rarb_atob(t_node *stack_a, t_node *stack_b, int num);
int			count_rarrb_atob(t_node *stack_a, t_node *stack_b, int num);
int			count_rrarb_atob(t_node *stack_a, t_node *stack_b, int num);
int			count_rrarrb_atob(t_node *stack_a, t_node *stack_b, int num);

int			get_min_rotate_btoa(t_node *stack_a, t_node *stack_b);
int			count_rotate_btoa(t_node *stack_a, int num);
int			count_rarb_btoa(t_node *stack_a, t_node *stack_b, int num);
int			count_rarrb_btoa(t_node *stack_a, t_node *stack_b, int num);
int			count_rrarb_btoa(t_node *stack_a, t_node *stack_b, int num);
int			count_rrarrb_btoa(t_node *stack_a, t_node *stack_b, int num);

int			exec_rarb(t_node **stack_a, t_node **stack_b, int num, int mode);
int			exec_rarrb(t_node **stack_a, t_node **stack_b, int num, int mode);
int			exec_rrarb(t_node **stack_a, t_node **stack_b, int num, int mode);
int			exec_rrarrb(t_node **stack_a, t_node **stack_b, int num, int mode);

/* bonus */
void		check_and_exec(char *line, t_node **stack_a, t_node **stack_b);
char		*check_stack_and_free(t_node **stack_a, t_node **stack_b);

#endif