/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:59:06 by lude-jes          #+#    #+#             */
/*   Updated: 2026/01/09 18:45:50 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../Libft/libft.h"

typedef struct	s_node
{
	int				value;	// the value itself
	int				index;	// the index we give it
	struct s_node	*next;	// next node
	struct s_node	*prev;	// previous node
}	t_node;

typedef struct	s_stack
{
	t_node	*top;	// first element of the stack
	t_node	*bot;	// last element of the stack
	int		size;	// number of elements
	char	name;	// stack a or stack b?
}	t_stack;

// Ops
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// Parsing
int	is_valid_int_token(char *s);
int	safe_atoi(const char *s, int *out);

// Utils
t_node	*pop_top(t_stack	*s);
t_node	*pop_bot(t_stack *s);
void	push_top(t_stack *s, t_node *n);
void	push_bot(t_stack *s, t_node *n);
void	swap_top(t_stack *s);

t_node	*new_node(int value);
void	free_nodes(t_stack *s);

# endif