/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:44:58 by lude-jes          #+#    #+#             */
/*   Updated: 2026/01/08 17:06:51 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	t_node	*n;

	n = pop_top(a);
	if (!n)				// In case stack a is empty
		return ;
	push_top(b, n);
	write (1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*n;

	n = pop_top(b);
	if (!n)
		return ;		// In case stack b is empty
	push_top(a, n);
	write (1, "pa\n", 3);
}