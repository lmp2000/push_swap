/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 01:05:22 by lude-jes          #+#    #+#             */
/*   Updated: 2026/01/29 02:12:50 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	both_positive(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	while (cost_a && cost_b)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a--)
		ra(a);
	while (cost_b--)
		rb(b);	
}

static void	both_negative(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	while (cost_a && cost_b)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	while (cost_a++)
		rra(a);
	while (cost_b++)
		rrb(b);	
}

static void	rotate_positive(t_stack *s, int cost_s)
{
	char	c;

	if (cost_s <= 0)
		return ;
	c = s->name;
	while (cost_s)
	{
		if (c == 'a')
			ra(s);
		else if (c == 'b')
			rb(s);
		cost_s--;
	}
}

static void	rotate_negative(t_stack *s, int cost_s)
{
	char	c;

	if (cost_s >= 0)
		return ;
	c = s->name;
	while (cost_s)
	{
		if (c == 'a')
			rra(s);
		else if (c == 'b')
			rrb(s);
		cost_s++;
	}
}

void	move_node_to_a(t_stack *a, t_stack *b, t_node *bnode)
{
	t_node	*target;
	int		cost_a;
	int		cost_b;
	
	if (!a || !b || !bnode || b->size == 0)
		return ;
	target = find_target_a(a, bnode->index);
	if (pos_of_node(a, target) == -1 || pos_of_node(b, bnode) == -1)
		return ;
	cost_a = rot_cost(a, pos_of_node(a, target));
	cost_b = rot_cost(b, pos_of_node(b, bnode));
	if (cost_a > 0 && cost_b > 0)
		both_positive(a, b, cost_a, cost_b);
	else if (cost_a < 0 && cost_b < 0)
		both_negative(a, b, cost_a, cost_b);
	else
	{
		rotate_positive(a, cost_a);
		rotate_negative(a, cost_a);
		rotate_positive(b, cost_b);
		rotate_negative(b, cost_b);
	}
	pa(a, b);
}