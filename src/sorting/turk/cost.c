/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:06:44 by lude-jes          #+#    #+#             */
/*   Updated: 2026/01/29 00:58:49 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int pos_of_node(t_stack *s, t_node *node)
{
	t_node	*ptr;
	int		counter;
	
	if (s == NULL || node == NULL)
		return (-1);
	counter = 0;
	ptr = s->top;
	while (ptr)
	{
		if (ptr == node)
			return (counter);
		counter++;
		ptr = ptr->next;
	}
	return (-1);
}

int 	rot_cost(t_stack *s, int pos)
{
	int	forward_cost;
	int	reverse_cost;
	
	if (s == NULL || s->size < 2 || pos == 0)
		return (0);
	forward_cost = pos;
	reverse_cost = pos - s->size;
	if (forward_cost <= reverse_cost * -1)
		return (forward_cost);
	else
		return (reverse_cost);
}

static int	ft_absolute(int c)
{
	if (c < 0)
		c *= -1;
	return (c);
}

int	combined_cost(int cost_a, int cost_b)
{
	int	total;
	
	if (cost_a < 0 && cost_b < 0)
	{
		if (cost_a <= cost_b)
			total = ft_absolute(cost_a);
		else
			total = ft_absolute(cost_b);
	}
	else if (cost_a > 0 && cost_b > 0)
	{
		if (cost_a >= cost_b)
			total = cost_a;
		else
			total = cost_b;
	}
	else
		total = ft_absolute(cost_a) + ft_absolute(cost_b);
	return (total);
}

int 	total_cost_for_node(t_stack *a, t_stack *b, t_node *bnode)
{
	t_node	*target;
	int		temp;
	int		cost_a;
	int		cost_b;

	if (!a || !b || !bnode)
		return (-1);
	target = find_target_a(a, bnode->index);
	if (!target)
    	return (-1);
	temp = pos_of_node(a, target);
	if (temp < 0)
		return (-1);
	cost_a = rot_cost(a, temp);
	temp = pos_of_node(b, bnode);
	if (temp < 0)
		return (-1);
	cost_b = rot_cost(b, temp);
	return (combined_cost(cost_a, cost_b));
}