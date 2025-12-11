/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:00:49 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/11 10:16:31 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_node **top, t_print_mode mode)
{
	t_node	*temp;

	if (!*top || !((*top)->next))
		return (print_op(mode, "sa\n", "sb\n"));
	temp = *top;
	*top = (*top)->next;
	temp->next = (*top)->next;
	(*top)->next = temp;
	print_op(mode, "sa\n", "sb\n");
}

void	ss(t_node **a, t_node **b, t_print_mode mode)
{
	sx(a, PRINT_NONE);
	sx(b, PRINT_NONE);
	if (mode == PRINT_BOTH)
		write(1, "ss\n", 3);
}

/**
 * pa -> px(b, a, PRINT_A);
 * Take the first element at the top of b and put it at the top of a.
 * pb -> px(a, b, PRINT_B);
 * Take the first element at the top of a and put it at the top of b.
 */
void	px(t_node **from, t_node **to, t_print_mode mode)
{
	t_node	*temp;

	if (!*from)
		return (print_op(mode, "pa\n", "pb\n"));
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
	print_op(mode, "pa\n", "pb\n");
}
