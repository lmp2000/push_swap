/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 22:29:25 by lude-jes          #+#    #+#             */
/*   Updated: 2026/02/09 17:12:26 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop_top(t_stack *s)
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

t_node	*pop_bot(t_stack *s)
{
	t_node	*n;

	if (!s || s->size == 0 || !s->bot)
		return (NULL);
	n = s->bot;
	if (s->size == 1)
	{
		s->top = NULL;
		s->bot = NULL;
		n->prev = NULL;
		s->size = 0;
	}
	else
	{
		s->bot = n->prev;
		s->bot->next = NULL;
		n->prev = NULL;
		s->size--;
	}
	n->next = NULL;
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

void	swap_top(t_stack *s)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!s || s->size < 2 || !s->top)
		return ;
	first = s->top;
	second = s->top->next;
	third = second->next;
	s->top = second;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	else
		s->bot = first;
}
