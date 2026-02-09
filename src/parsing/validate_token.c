/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:26:36 by lude-jes          #+#    #+#             */
/*   Updated: 2026/02/09 18:33:14 by lude-jes         ###   ########.fr       */
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

static int	sign_handler(char **s)
{
	int		sign;

	sign = 1;
	if (**s == '+' || **s == '-')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
	}
	return (sign);
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
	sign = sign_handler((char **)&s);
	if (sign == 1)
		limit = (long)INT_MAX;
	else
		limit = -(long)INT_MIN;
	while (*s)
	{
		digit = *s - '0';
		if (box > (limit - digit) / 10)
			return (0);
		box = box * 10 + digit;
		s++;
	}
	*out = (int)(box * sign);
	return (1);
}
