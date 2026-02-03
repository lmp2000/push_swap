/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:12:42 by lude-jes          #+#    #+#             */
/*   Updated: 2026/02/03 23:02:01 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*n;
	
	if (a == NULL)
		return (0);
	if (a->size < 2)
		return (1);
	n = a->top;
	while (n && n->next)
	{
		if (n->index > n->next->index)
			return (0);
		n = n->next;
	}
	return (1);
}

void	sort_2(t_stack *a)
{
	t_node	*n;
	
	if (a == NULL || a->size != 2)
		return ;
	n = a->top;
	if (n->index > n->next->index)
		sa(a);
	return ;
}

void	sort_3(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;
	
	if (a == NULL || a->size != 3)
		return ;
	top = a->top->index;
	mid = a->top->next->index;
	bot = a->bot->index;
	if (top > mid && top > bot)
		ra(a);
	else if (mid > top && mid > bot)
		rra(a);
	if (a->top->index > a->top->next->index)
		sa(a);
	return ;
}

void	sort_4_5(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size < 4 || a->size > 5)
		return ;
	rotate_to_top(a, index_pos(a, 0));
	pb(a, b);
	if (a->size == 3)
	{
		sort_3(a);
		pa(a, b);
	}
	else
	{
		rotate_to_top(a, index_pos(a, 1));
		pb(a, b);
		sort_3(a);
		pa(a, b);
		pa(a, b);
	}
	return ;
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (!a || a->size < 2 || a->size > 5)
		return ;
	if (is_sorted(a))
		return ;
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if ((a->size == 4 || a->size == 5) && b)
		sort_4_5(a, b);
	return ;
}