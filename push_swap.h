/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:59:06 by lude-jes          #+#    #+#             */
/*   Updated: 2026/02/03 22:09:07 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>

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

// Sorting
int 	*stack_to_array(t_stack *a);
void	sort_int_array(int *arr, int size);
int		find_index(int *arr, int size, int value);
int		assign_indexes(t_stack *a);

int 	is_sorted(t_stack *a);
void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	sort_4_5(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);

int		index_pos(t_stack *a, int target);
void	rotate_to_top(t_stack *a, int pos);

// Turk
t_node	*find_min(t_stack *a);
t_node	*find_target_a(t_stack *a, int b_index);
int 	pos_of_node(t_stack *s, t_node *node);
int 	rot_cost(t_stack *s, int pos);
int		combined_cost(int cost_a, int cost_b);
int 	total_cost_for_node(t_stack *a, t_stack *b, t_node *bnode);
void	move_node_to_a(t_stack *a, t_stack *b, t_node *bnode);
t_node	*find_cheapest_bnode(t_stack *a, t_stack *b);
void	turk_sort(t_stack *a, t_stack *b);

// Parsing
int	is_valid_int_token(char *s);
int	safe_atoi(const char *s, int *out);

int	parse_input(int argc, char **argv, t_stack *a); // public parsing API

// Utils
t_node	*pop_top(t_stack	*s);
t_node	*pop_bot(t_stack *s);
void	push_top(t_stack *s, t_node *n);
void	push_bot(t_stack *s, t_node *n);
void	swap_top(t_stack *s);
char	**ft_split(char const *s, char c);

t_node	*new_node(int value);
void	free_nodes(t_stack *s);

# endif