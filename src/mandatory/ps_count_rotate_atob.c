/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_count_rotate_atob.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:13:55 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/11 08:31:54 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rotate_atob(t_node *stack_b, int num)
{
	t_node	*curr;
	t_node	*next;
	int		i;

	i = 1;
	if (stack_b->num < num && num < ps_lstlast(stack_b)->num)
		i = 0;
	else if (num < get_min(stack_b) || num > get_max(stack_b))
		i = get_index(stack_b, get_max(stack_b));
	else
	{
		curr = stack_b;
		next = curr->next;
		while (curr->num < num || num < next->num)
		{
			curr = next;
			next = curr->next;
			i++;
		}
	}
	return (i);
}

int	count_rarb_atob(t_node *stack_a, t_node *stack_b, int num)
{
	int	cnt;

	cnt = count_rotate_atob(stack_b, num);
	if (cnt < get_index(stack_a, num))
		cnt = get_index(stack_a, num);
	return (cnt);
}

int	count_rarrb_atob(t_node *stack_a, t_node *stack_b, int num)
{
	int	cnt;

	cnt = 0;
	if (count_rotate_atob(stack_b, num))
		cnt = ps_lstsize(stack_b) - count_rotate_atob(stack_b, num);
	cnt += get_index(stack_a, num);
	return (cnt);
}

int	count_rrarb_atob(t_node *stack_a, t_node *stack_b, int num)
{
	int	cnt;

	cnt = 0;
	if (get_index(stack_a, num))
		cnt = ps_lstsize(stack_a) - get_index(stack_a, num);
	cnt += count_rotate_atob(stack_b, num);
	return (cnt);
}

int	count_rrarrb_atob(t_node *stack_a, t_node *stack_b, int num)
{
	int	cnt;

	cnt = 0;
	if (count_rotate_atob(stack_b, num))
		cnt = ps_lstsize(stack_b) - count_rotate_atob(stack_b, num);
	if (get_index(stack_a, num) && \
		cnt < ps_lstsize(stack_a) - get_index(stack_a, num))
		cnt = ps_lstsize(stack_a) - get_index(stack_a, num);
	return (cnt);
}
