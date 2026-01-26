/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:00:31 by lude-jes          #+#    #+#             */
/*   Updated: 2026/01/26 22:19:29 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_pos(t_stack *a, int target)
{
	t_node	*n;
	int		counter;
	
	if (a == NULL)
		return (-1);
	n = a->top;
	counter = 0;
	while (n)
	{
		if (n->index == target)
			return (counter);
		counter++;
		n = n->next;
	}
	return (-1);
}

static void	rotate_forward(t_stack *a, int times)
{
	while (times)
	{
		if (a->name == 'a')
			ra(a);
		else if (a->name == 'b')
			rb(a);
		times--;
	}
}
static void	rotate_reverse(t_stack *a, int times)
{
	while (times)
	{
		if (a->name == 'a')
			rra(a);
		else if (a->name == 'b')
			rrb(a);
		times--;
	}
}

void	rotate_to_top(t_stack *a, int pos)
{
	int	forward;
	int	reverse;
	
	if (a == NULL || a->size < 2 || pos <= 0)
		return ;
	if (pos >= a->size)
		return ;
	forward = pos;
	reverse = a->size - pos;
	if (forward <= reverse)
		rotate_forward(a, forward);
	else
		rotate_reverse(a, reverse);
	return ;
}