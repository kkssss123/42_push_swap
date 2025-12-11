/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 08:45:23 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/11 09:52:33 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	*line;

	if (argc < 2)
		exit(0);
	stack_a = init_stack(argc, argv);
	if (contains_duplicate(stack_a))
	{
		ps_lstclear(&stack_a);
		error_exit(ERR_DUPLICATE);
	}
	stack_b = NULL;
	line = get_next_line(0);
	while (line)
	{
		check_and_exec(line, &stack_a, &stack_b);
		line = get_next_line(0);
	}
	ft_printf(check_stack_and_free(&stack_a, &stack_b));
}
