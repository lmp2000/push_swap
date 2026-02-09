/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:50:59 by lude-jes          #+#    #+#             */
/*   Updated: 2026/02/09 17:11:34 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_stack *a)
{
	t_node	*min;
	t_node	*ptr;

	min = a->top;
	ptr = min;
	while (ptr)
	{
		if (ptr->index < min->index)
			min = ptr;
		ptr = ptr->next;
	}
	return (min);
}

t_node	*find_target_a(t_stack *a, int b_index)
{
	t_node	*target;
	t_node	*ptr;

	if (a == NULL || a->size == 0)
		return (NULL);
	ptr = a->top;
	target = NULL;
	while (ptr)
	{
		if (ptr->index > b_index)
		{
			if (target)
			{
				if (target->index > ptr->index)
					target = ptr;
			}
			else
				target = ptr;
		}
		ptr = ptr->next;
	}
	if (target)
		return (target);
	return (find_min(a));
}
