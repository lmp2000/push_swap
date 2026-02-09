/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:25:28 by lude-jes          #+#    #+#             */
/*   Updated: 2026/02/09 17:03:11 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	if (a->size < 2)
		return ;
	swap_top(a);
	write (1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (b->size < 2)
		return ;
	swap_top(b);
	write (1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	if (a->size < 2 && b->size < 2)
		return ;
	swap_top(a);
	swap_top(b);
	write (1, "ss\n", 3);
}
