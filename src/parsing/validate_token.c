/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:26:36 by lude-jes          #+#    #+#             */
/*   Updated: 2026/01/21 18:11:04 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_token(char *s)
{
	if (!s || !*s)
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (0);
		s++;
	}
	return (1);
}

int	safe_atoi(const char *s, int *out)
{
	long	box;
	long	limit;
	int		sign;
	int		digit;
	
	if (!s || !out)
		return (0);
	box = 0;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	limit = (sign == 1) ? (long)INT_MAX : -(long)INT_MIN;
	while (*s)
	{
		digit = *s - '0';
		if (box > (limit - digit) / 10)		// box * 10 + digit > limit?
			return (0);
		box = box * 10 + digit;
		s++;
	}
	*out = (int)(box * sign);
	return (1);
}