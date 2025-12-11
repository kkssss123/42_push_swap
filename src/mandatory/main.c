/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:09:28 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/11 08:38:40 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;

	if (argc < 2)
		exit(0);
	stack_a = init_stack(argc, argv);
	if (contains_duplicate(stack_a))
	{
		ps_lstclear(&stack_a);
		error_exit(ERR_DUPLICATE);
	}
	if (!is_sorted(stack_a))
		sort(&stack_a);
	ps_lstclear(&stack_a);
}
