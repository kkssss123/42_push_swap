/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:42:16 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/11 13:26:47 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(t_print_mode mode, char *op_a, char *op_b)
{
	if (mode == PRINT_A)
		write(1, op_a, ft_strlen(op_a));
	else if (mode == PRINT_B)
		write(1, op_b, ft_strlen(op_b));
}

void	error_exit(t_error err)
{
	(void)err;
	write(1, "ERROR\n", 6);
	exit(1);
}
