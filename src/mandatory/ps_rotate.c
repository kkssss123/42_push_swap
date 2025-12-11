/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:41:00 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/10 19:14:55 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_rarb(t_node **stack_a, t_node **stack_b, int num, int mode)
{
	if (mode == ATOB)
	{
		while ((*stack_a)->num != num && count_rotate_atob(*stack_b, num))
			rr(stack_a, stack_b, PRINT_BOTH);
		while ((*stack_a)->num != num)
			rx(stack_a, PRINT_A);
		while (count_rotate_atob(*stack_b, num))
			rx(stack_b, PRINT_B);
		px(stack_a, stack_b, PRINT_B);
	}
	else
	{
		while ((*stack_b)->num != num && count_rotate_btoa(*stack_a, num))
			rr(stack_a, stack_b, PRINT_BOTH);
		while ((*stack_b)->num != num)
			rx(stack_b, PRINT_B);
		while (count_rotate_btoa(*stack_a, num))
			rx(stack_a, PRINT_A);
		px(stack_b, stack_a, PRINT_A);
	}
	return (-1);
}

int	exec_rarrb(t_node **stack_a, t_node **stack_b, int num, int mode)
{
	if (mode == ATOB)
	{
		while ((*stack_a)->num != num)
			rx(stack_a, PRINT_A);
		while (count_rotate_atob(*stack_b, num))
			rrx(stack_b, PRINT_B);
		px(stack_a, stack_b, PRINT_B);
	}
	else
	{
		while (count_rotate_btoa(*stack_a, num))
			rx(stack_a, PRINT_A);
		while ((*stack_b)->num != num)
			rrx(stack_b, PRINT_B);
		px(stack_b, stack_a, PRINT_A);
	}
	return (-1);
}

int	exec_rrarb(t_node **stack_a, t_node **stack_b, int num, int mode)
{
	if (mode == ATOB)
	{
		while ((*stack_a)->num != num)
			rrx(stack_a, PRINT_A);
		while (count_rotate_atob(*stack_b, num))
			rx(stack_b, PRINT_B);
		px(stack_a, stack_b, PRINT_B);
	}
	else
	{
		while (count_rotate_btoa(*stack_a, num))
			rrx(stack_a, PRINT_A);
		while ((*stack_b)->num != num)
			rx(stack_b, PRINT_B);
		px(stack_b, stack_a, PRINT_A);
	}
	return (-1);
}

int	exec_rrarrb(t_node **stack_a, t_node **stack_b, int num, int mode)
{
	if (mode == ATOB)
	{
		while ((*stack_a)->num != num && count_rotate_atob(*stack_b, num))
			rrr(stack_a, stack_b, PRINT_BOTH);
		while ((*stack_a)->num != num)
			rrx(stack_a, PRINT_A);
		while (count_rotate_atob(*stack_b, num))
			rrx(stack_b, PRINT_B);
		px(stack_a, stack_b, PRINT_B);
	}
	else
	{
		while ((*stack_b)->num != num && count_rotate_btoa(*stack_a, num))
			rrr(stack_a, stack_b, PRINT_BOTH);
		while ((*stack_b)->num != num)
			rrx(stack_b, PRINT_B);
		while (count_rotate_btoa(*stack_a, num))
			rrx(stack_a, PRINT_A);
		px(stack_b, stack_a, PRINT_A);
	}
	return (-1);
}
