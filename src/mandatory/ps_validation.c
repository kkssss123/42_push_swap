/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:12:00 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/09 19:21:16 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	contains_duplicate(t_node *head)
{
	t_node	*temp;

	while (head)
	{
		temp = head->next;
		while (temp)
		{
			if (head->num == temp->num)
				return (true);
			temp = temp->next;
		}
		head = head->next;
	}
	return (false);
}

bool	is_sorted(t_node *head)
{
	int	temp;

	temp = head->num;
	head = head->next;
	while (head)
	{
		if (temp > head->num)
			return (false);
		temp = head->num;
		head = head->next;
	}
	return (true);
}
