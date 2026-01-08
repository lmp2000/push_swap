/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 22:29:25 by lude-jes          #+#    #+#             */
/*   Updated: 2026/01/08 00:11:42 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop_top(t_stack	*s)
{
	t_node	*n;

	if (!s || s->size == 0 || !s->top)
		return (NULL);

	n = s->top;
	if (s->size == 1)
	{
		s->top = NULL;
		s->bot = NULL;
		s->size = 0;
	}
	else
	{
		s->top = n->next;
		s->top->prev = NULL;
		n->next = NULL;
		s->size--;
	}
	n->prev = NULL;
	return (n);
}

void	push_top(t_stack *s, t_node *n)
{
	if (!s || !n)
		return ;
	n->prev = NULL;
	if (s->size == 0)
	{
		n->next = NULL;
		s->top = n;
		s->bot = n;
		s->size = 1;
	}
	else
	{
		s->top->prev = n;
		n->next = s->top;
		s->top = n;
		s->size++;
	}
}

void	push_bot(t_stack *s, t_node *n)
{
	if (!s || !n)
		return ;
	n->next = NULL;
	if (s->size == 0)
	{
		n->prev = NULL;
		s->top = n;
		s->bot = n;
		s->size = 1;
	}
	else
	{
		s->bot->next = n;
		n->prev = s->bot;
		s->bot = n;
		s->size++;
	}
}