/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:39:56 by lude-jes          #+#    #+#             */
/*   Updated: 2026/02/09 17:03:56 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->next = NULL;
	n->prev = NULL;
	n->index = -1;
	n->value = value;
	return (n);
}

void	free_nodes(t_stack *s)
{
	t_node	*cur;
	t_node	*next;

	if (!s)
		return ;
	cur = s->top;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	s->top = NULL;
	s->bot = NULL;
	s->size = 0;
}
