/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_min_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:11:39 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/10 18:30:28 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_rotate_atob(t_node *stack_a, t_node *stack_b)
{
	int		min;
	t_node	*temp;

	min = INT_MAX;
	temp = stack_a;
	while (temp)
	{
		if (min > count_rarb_atob(stack_a, stack_b, temp->num))
			min = count_rarb_atob(stack_a, stack_b, temp->num);
		if (min > count_rarrb_atob(stack_a, stack_b, temp->num))
			min = count_rarrb_atob(stack_a, stack_b, temp->num);
		if (min > count_rrarb_atob(stack_a, stack_b, temp->num))
			min = count_rrarb_atob(stack_a, stack_b, temp->num);
		if (min > count_rrarrb_atob(stack_a, stack_b, temp->num))
			min = count_rrarrb_atob(stack_a, stack_b, temp->num);
		temp = temp->next;
	}
	return (min);
}

int	get_min_rotate_btoa(t_node *stack_a, t_node *stack_b)
{
	int		min;
	t_node	*temp;

	min = INT_MAX;
	temp = stack_b;
	while (temp)
	{
		if (min > count_rarb_btoa(stack_a, stack_b, temp->num))
			min = count_rarb_btoa(stack_a, stack_b, temp->num);
		if (min > count_rarrb_btoa(stack_a, stack_b, temp->num))
			min = count_rarrb_btoa(stack_a, stack_b, temp->num);
		if (min > count_rrarb_btoa(stack_a, stack_b, temp->num))
			min = count_rrarb_btoa(stack_a, stack_b, temp->num);
		if (min > count_rrarrb_btoa(stack_a, stack_b, temp->num))
			min = count_rrarrb_btoa(stack_a, stack_b, temp->num);
		temp = temp->next;
	}
	return (min);
}
