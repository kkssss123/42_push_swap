/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:05:48 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/11 09:36:03 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	max_len(char *a, char *b)
{
	size_t	ret;

	ret = ft_strlen(a);
	if (ret < ft_strlen(b))
		ret = ft_strlen(b);
	return (ret);
}

static void	free_clear_exit(char *line, t_node **stack_a, t_node **stack_b)
{
	free(line);
	ps_lstclear(stack_a);
	ps_lstclear(stack_b);
	error_exit(INVALID_INPUT);
}

void	check_and_exec(char *line, t_node **stack_a, t_node **stack_b)
{
	if (!ft_strncmp(line, "sa\n", max_len(line, "sa")))
		sx(stack_a, PRINT_NONE);
	else if (!ft_strncmp(line, "sb\n", max_len(line, "sb")))
		sx(stack_b, PRINT_NONE);
	else if (!ft_strncmp(line, "ss\n", max_len(line, "ss")))
		ss(stack_a, stack_b, PRINT_NONE);
	else if (!ft_strncmp(line, "pa\n", max_len(line, "pa")))
		px(stack_b, stack_a, PRINT_NONE);
	else if (!ft_strncmp(line, "pb\n", max_len(line, "pb")))
		px(stack_a, stack_b, PRINT_NONE);
	else if (!ft_strncmp(line, "ra\n", max_len(line, "ra")))
		rx(stack_a, PRINT_NONE);
	else if (!ft_strncmp(line, "rb\n", max_len(line, "rb")))
		rx(stack_b, PRINT_NONE);
	else if (!ft_strncmp(line, "rr\n", max_len(line, "rr")))
		rr(stack_a, stack_b, PRINT_NONE);
	else if (!ft_strncmp(line, "rra\n", max_len(line, "rra")))
		rrx(stack_a, PRINT_NONE);
	else if (!ft_strncmp(line, "rrb\n", max_len(line, "rrb")))
		rrx(stack_b, PRINT_NONE);
	else if (!ft_strncmp(line, "rrr\n", max_len(line, "rrr")))
		rrr(stack_a, stack_b, PRINT_NONE);
	else
		free_clear_exit(line, stack_a, stack_b);
}

char	*check_stack_and_free(t_node **stack_a, t_node **stack_b)
{
	char	*ret;

	ret = "KO\n";
	if (is_sorted(*stack_a) && !*stack_b)
		ret = "OK\n";
	ps_lstclear(stack_a);
	ps_lstclear(stack_b);
	return (ret);
}
