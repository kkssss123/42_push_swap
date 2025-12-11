/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstutils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:44:22 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/10 18:17:25 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_node *lst)
{
	int	min;

	min = lst->num;
	while (lst)
	{
		if (min > lst->num)
			min = lst->num;
		lst = lst->next;
	}
	return (min);
}

int	get_max(t_node *lst)
{
	int	max;

	max = lst->num;
	while (lst)
	{
		if (max < lst->num)
			max = lst->num;
		lst = lst->next;
	}
	return (max);
}

int	get_index(t_node *lst, int num)
{
	int	i;

	i = 0;
	while (lst && lst->num != num)
	{
		i++;
		lst = lst->next;
	}
	if (!lst)
		i = -1;
	return (i);
}
