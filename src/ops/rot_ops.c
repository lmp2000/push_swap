/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:41:55 by lude-jes          #+#    #+#             */
/*   Updated: 2026/01/08 22:03:51 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node	*first;

	if (a->size < 2)
		return ;
	first = pop_top(a);
	push_bot(a, first);
	write (1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_node	*first;

	if (b->size < 2)
		return ;
	first = pop_top(b);
	push_bot(b, first);
	write (1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	t_node	*first;

	if (a->size < 2 && b->size < 2)
		return ;
	if (a->size >= 2)
	{
		first = pop_top(a);
		push_bot(a, first);
	}
	if (b->size >= 2)
	{
		first = pop_top(b);
		push_bot(b, first);
	}
	write (1, "rr\n", 3);
}