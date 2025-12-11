/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:22:52 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/11 08:38:04 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_nums(t_node **stack_a)
{
	if ((*stack_a)->num == get_min(*stack_a))
	{
		rrx(stack_a, PRINT_A);
		sx(stack_a, PRINT_A);
	}
	else if ((*stack_a)->num == get_max(*stack_a))
	{
		rx(stack_a, PRINT_A);
		if (!is_sorted(*stack_a))
			sx(stack_a, PRINT_A);
	}
	else
	{
		if (is_sorted((*stack_a)->next))
			sx(stack_a, PRINT_A);
		else
			rrx(stack_a, PRINT_A);
	}
}

void	push_atob_iter(t_node **stack_a, t_node **stack_b)
{
	int		min;
	t_node	*temp;

	while (ps_lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
	{
		temp = *stack_a;
		min = get_min_rotate_atob(*stack_a, *stack_b);
		while (min >= 0)
		{
			if (min == count_rarb_atob(*stack_a, *stack_b, temp->num))
				min = exec_rarb(stack_a, stack_b, temp->num, ATOB);
			else if (min == count_rarrb_atob(*stack_a, *stack_b, temp->num))
				min = exec_rarrb(stack_a, stack_b, temp->num, ATOB);
			else if (min == count_rrarb_atob(*stack_a, *stack_b, temp->num))
				min = exec_rrarb(stack_a, stack_b, temp->num, ATOB);
			else if (min == count_rrarrb_atob(*stack_a, *stack_b, temp->num))
				min = exec_rrarrb(stack_a, stack_b, temp->num, ATOB);
			else
				temp = temp->next;
		}
	}
}

t_node	*push_atob(t_node **stack_a)
{
	t_node	*stack_b;

	stack_b = NULL;
	if (ps_lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		px(stack_a, &stack_b, PRINT_B);
	if (ps_lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		px(stack_a, &stack_b, PRINT_B);
	if (ps_lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		push_atob_iter(stack_a, &stack_b);
	if (!is_sorted(*stack_a))
		sort_three_nums(stack_a);
	return (stack_b);
}

void	push_btoa(t_node **stack_a, t_node **stack_b)
{
	int		min;
	t_node	*temp;

	while (*stack_b)
	{
		temp = *stack_b;
		min = get_min_rotate_btoa(*stack_a, *stack_b);
		while (min >= 0)
		{
			if (min == count_rarb_btoa(*stack_a, *stack_b, temp->num))
				min = exec_rarb(stack_a, stack_b, temp->num, BTOA);
			else if (min == count_rarrb_btoa(*stack_a, *stack_b, temp->num))
				min = exec_rarrb(stack_a, stack_b, temp->num, BTOA);
			else if (min == count_rrarb_btoa(*stack_a, *stack_b, temp->num))
				min = exec_rrarb(stack_a, stack_b, temp->num, BTOA);
			else if (min == count_rrarrb_btoa(*stack_a, *stack_b, temp->num))
				min = exec_rrarrb(stack_a, stack_b, temp->num, BTOA);
			else
				temp = temp->next;
		}
	}
}

void	sort(t_node **stack_a)
{
	t_node	*stack_b;
	int		min;
	int		i;

	stack_b = NULL;
	if (ps_lstsize(*stack_a) == 2)
		sx(stack_a, PRINT_A);
	else
	{
		stack_b = push_atob(stack_a);
		push_btoa(stack_a, &stack_b);
		min = get_min(*stack_a);
		i = get_index(*stack_a, min);
		if (i < ps_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->num != min)
				rx(stack_a, PRINT_A);
		}
		else
		{
			while ((*stack_a)->num != min)
				rrx(stack_a, PRINT_A);
		}
	}
}
