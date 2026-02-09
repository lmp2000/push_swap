/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:44:58 by lude-jes          #+#    #+#             */
/*   Updated: 2026/02/09 17:02:06 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	t_node	*n;

	n = pop_top(a);
	if (!n)
		return ;
	push_top(b, n);
	write (1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*n;

	n = pop_top(b);
	if (!n)
		return ;
	push_top(a, n);
	write (1, "pa\n", 3);
}
