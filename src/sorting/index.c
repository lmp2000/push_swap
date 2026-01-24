/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:41:16 by lude-jes          #+#    #+#             */
/*   Updated: 2026/01/24 21:39:28 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *stack_to_array(t_stack *a)
{
	int		*array;
	int		i;
	int		size;
	t_node	*n;
	
	i = 0;
	if (!a || a->size == 0)
		return (NULL);
	size = a->size;
	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	n = a->top;
	while (n)
	{
		array[i] = n->value;
		n = n->next;
		i++;
	}
	return (array);
}

static void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_int_array(int *arr, int size)
{
	int	i;
	int	j;

	if (arr == NULL || size < 2)
		return ;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
				swap_int(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

int	find_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	assign_indexes(t_stack *a)
{
	int		*arr;
	t_node	*n;
	
	if (!a || a->size < 2)
		return (1);
	n = a->top;
	arr = stack_to_array(a);
	if (!arr)
		return (0);	
	sort_int_array(arr, a->size);
	while (n)
	{
		n->index = find_index(arr, a->size, n->value);
		if (n->index == -1)
		{
			free (arr);
			return (0);
		}
		n = n->next;
	}
	free (arr);
	return (1);
}