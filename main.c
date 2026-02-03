/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 20:07:51 by lude-jes          #+#    #+#             */
/*   Updated: 2026/02/03 22:00:35 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	return_error(t_stack *a, t_stack *b)
{
	free_nodes(a);
	free_nodes(b);
	write (2, "Error\n", 6);
}

static void	init_stacks(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->bot = NULL;
	a->size = 0;
	a->name = 'a';
	b->top = NULL;
	b->bot = NULL;
	b->size = 0;
	b->name = 'b';
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	
	if (ac < 2)
		return (0);
	init_stacks(&a, &b);
	if (parse_input(ac, av, &a) == 0 || assign_indexes(&a) == 0)
	{
		return_error(&a, &b);
		return (1);
	}
	if (!is_sorted(&a))
	{
		if (a.size <= 5)
			sort_small(&a, &b);
		else
			turk_sort(&a, &b);
	}
	free_nodes(&a);
	free_nodes(&b);
	return (0);
}