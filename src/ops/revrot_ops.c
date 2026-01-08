/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 22:13:40 by lude-jes          #+#    #+#             */
/*   Updated: 2026/01/08 22:22:56 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node	*last;
	
	if (a->size < 2)
		return ;
	last = pop_bot(a);
	push_top(a, last);
	write (1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_node *last;

	if (b->size < 2)
		return ;
	last = pop_bot(b);
	push_top(b, last);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	t_node	*last;

	if (a->size < 2 && b->size < 2)
		return ;
	if (a->size >= 2)
	{
		last = pop_bot(a);
		push_top(a, last);
	}
	if (b->size >= 2)
	{
		last = pop_bot(b);
		push_top(b, last);
	}
	write (1, "rrr\n", 4);
}