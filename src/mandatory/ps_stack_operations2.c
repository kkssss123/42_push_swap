/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_operations2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:41:49 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/11 10:16:48 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * The first element becomes the last one.
 */
void	rx(t_node **top, t_print_mode mode)
{
	t_node	*first;
	t_node	*last;

	if (!*top || !((*top)->next))
		return (print_op(mode, "ra\n", "rb\n"));
	first = *top;
	last = ps_lstlast(*top);
	*top = first->next;
	last->next = first;
	first->next = NULL;
	print_op(mode, "ra\n", "rb\n");
}

void	rr(t_node **a, t_node **b, t_print_mode mode)
{
	rx(a, PRINT_NONE);
	rx(b, PRINT_NONE);
	if (mode == PRINT_BOTH)
		write(1, "rr\n", 3);
}

/**
 * The last element becomes the first one.
 */
void	rrx(t_node **top, t_print_mode mode)
{
	t_node	*prev;
	t_node	*last;

	if (!*top || !((*top)->next))
		return (print_op(mode, "rra\n", "rrb\n"));
	prev = NULL;
	last = *top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *top;
	*top = last;
	print_op(mode, "rra\n", "rrb\n");
}

void	rrr(t_node **a, t_node **b, t_print_mode mode)
{
	rrx(a, PRINT_NONE);
	rrx(b, PRINT_NONE);
	if (mode == PRINT_BOTH)
		write(1, "rrr\n", 4);
}
