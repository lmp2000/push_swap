/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 21:57:26 by lude-jes          #+#    #+#             */
/*   Updated: 2026/01/24 17:25:55 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	is_duplicate(t_stack *a, int value)
{
	t_node	*ptr;

	if (!a)
		return (0);
	ptr = a->top;
	while (ptr)
	{
		if (ptr->value == value)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

static int	process_tokens(t_stack *a, char **tokens)
{
	t_node	*n;
	int		c;
	int		i;
	
	i = 0;
	while (tokens[i])
	{
		if (!is_valid_token(tokens[i]))
			break ;
		if (!safe_atoi(tokens[i], &c))
			break ;
		if (is_duplicate(a, c))
			break ;
		n = new_node(c);
		if (!n)
			break ;
		push_bot(a, n);
		i++;
	}
	return (tokens[i] == NULL);
}

static int	parse_argv_string(t_stack *a, char *arg)
{
	char	**tokens;
	int		ok;
	
	if (!a)
		return (0);
	if (!arg || arg[0] == '\0')
		return (0);
	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
	{
		free_split(tokens);
		return (0);
	}
	ok = process_tokens(a, tokens);
	free_split(tokens);
	return (ok);
}

int	parse_input(int argc, char **argv, t_stack *a)
{
	int	i;
	
	i = 1;
	if (argc < 2)
		return (1);
	while (i < argc)
	{
		if (!parse_argv_string(a, argv[i]))
		{
			free_nodes(a);
			return (0);
		}
		i++;
	}
	return (1);
}
