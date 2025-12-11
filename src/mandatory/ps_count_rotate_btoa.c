/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_count_rotate_btoa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:18:21 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/11 08:32:26 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rotate_btoa(t_node *stack_a, int num)
{
	t_node	*curr;
	t_node	*next;
	int		i;

	i = 1;
	if (stack_a->num > num && num > ps_lstlast(stack_a)->num)
		i = 0;
	else if (num < get_min(stack_a) || num > get_max(stack_a))
		i = get_index(stack_a, get_min(stack_a));
	else
	{
		curr = stack_a;
		next = curr->next;
		while (curr->num > num || num > next->num)
		{
			curr = next;
			next = curr->next;
			i++;
		}
	}
	return (i);
}

int	count_rarb_btoa(t_node *stack_a, t_node *stack_b, int num)
{
	int	cnt;

	cnt = count_rotate_btoa(stack_a, num);
	if (cnt < get_index(stack_b, num))
		cnt = get_index(stack_b, num);
	return (cnt);
}

int	count_rarrb_btoa(t_node *stack_a, t_node *stack_b, int num)
{
	int	cnt;

	cnt = 0;
	if (get_index(stack_b, num))
		cnt = ps_lstsize(stack_b) - get_index(stack_b, num);
	cnt += count_rotate_btoa(stack_a, num);
	return (cnt);
}

int	count_rrarb_btoa(t_node *stack_a, t_node *stack_b, int num)
{
	int	cnt;

	cnt = 0;
	if (count_rotate_btoa(stack_a, num))
		cnt = ps_lstsize(stack_a) - count_rotate_btoa(stack_a, num);
	cnt += get_index(stack_b, num);
	return (cnt);
}

int	count_rrarrb_btoa(t_node *stack_a, t_node *stack_b, int num)
{
	int	cnt;

	cnt = 0;
	if (count_rotate_btoa(stack_a, num))
		cnt = ps_lstsize(stack_a) - count_rotate_btoa(stack_a, num);
	if (get_index(stack_b, num) && \
		cnt < ps_lstsize(stack_b) - get_index(stack_b, num))
		cnt = ps_lstsize(stack_b) - get_index(stack_b, num);
	return (cnt);
}
