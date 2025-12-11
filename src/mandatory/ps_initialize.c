/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:18:26 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/09 19:00:41 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

static void	free_clear_exit(char **tokens, t_node *head, t_error err)
{
	free_tokens(tokens);
	ps_lstclear(&head);
	error_exit(err);
}

static t_node	*parse_tokens(char **tokens, t_node *head)
{
	t_node		*new_nodes;
	t_node		*temp;
	int			i;
	long long	num;

	new_nodes = NULL;
	i = 0;
	while (tokens[i])
	{
		num = ps_atoi(tokens[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ps_lstclear(&new_nodes);
			free_clear_exit(tokens, head, INVALID_INPUT);
		}
		temp = ps_lstnew((int)num);
		if (!temp)
		{
			ps_lstclear(&new_nodes);
			free_clear_exit(tokens, head, ERR_MALLOC);
		}
		ps_lstadd_back(&new_nodes, temp);
		i++;
	}
	return (new_nodes);
}

t_node	*init_stack(int argc, char **argv)
{
	int		i;
	char	**tokens;
	t_node	*head;
	t_node	*new_chunk;
	t_node	*last_chunk;

	i = 1;
	head = NULL;
	last_chunk = NULL;
	while (i < argc)
	{
		tokens = ft_split(argv[i++], ' ');
		if (!tokens)
			free_clear_exit(tokens, head, ERR_MALLOC);
		else if (!tokens[0])
			free_clear_exit(tokens, head, INVALID_INPUT);
		new_chunk = parse_tokens(tokens, head);
		free_tokens(tokens);
		if (last_chunk)
			ps_lstadd_back(&last_chunk, new_chunk);
		else
			ps_lstadd_back(&head, new_chunk);
		last_chunk = new_chunk;
	}
	return (head);
}
