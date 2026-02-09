/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:24:10 by lude-jes          #+#    #+#             */
/*   Updated: 2026/02/09 17:11:55 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_cheapest_bnode(t_stack *a, t_stack *b)
{
	t_node	*n;
	t_node	*cheapest;
	int		c;
	int		best_c;

	if (!a || !b)
		return (NULL);
	n = b->top;
	cheapest = NULL;
	best_c = 0;
	while (n)
	{
		c = total_cost_for_node(a, b, n);
		if (c != -1 && (!cheapest || best_c > c))
		{
			cheapest = n;
			best_c = c;
		}
		n = n->next;
	}
	return (cheapest);
}

static void	rotate_pos(t_stack *s, int pos)
{
	if (pos <= 0)
		return ;
	while (pos)
	{
		ra(s);
		pos--;
	}
}

static void	rotate_neg(t_stack *s, int pos)
{
	if (pos <= 0)
		return ;
	while (pos)
	{
		rra(s);
		pos--;
	}
}

static void	push_to_b(t_stack *a, t_stack *b, int pivot)
{
	pb(a, b);
	if (b->top && b->top->index < pivot)
		rb(b);
}

void	turk_sort(t_stack *a, t_stack *b)
{
	t_node	*cheapest;
	int		pos;
	int		pivot;

	if (is_sorted(a) || a->size <= 5)
		return ;
	pivot = a->size / 2;
	while (a->size > 3)
		push_to_b(a, b, pivot);
	sort_3(a);
	while (b->size > 0)
	{
		cheapest = find_cheapest_bnode(a, b);
		move_node_to_a(a, b, cheapest);
	}
	cheapest = find_min(a);
	pos = pos_of_node(a, cheapest);
	if (pos <= a->size / 2)
		rotate_pos(a, pos);
	else
		rotate_neg(a, a->size - pos);
}
