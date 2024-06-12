/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:20:06 by ahusic            #+#    #+#             */
/*   Updated: 2024/06/11 16:47:40 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(const char *str, bool *error)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			*error = true;
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_signs(const char *str, bool *error)
{
	if (*str == '-' && (*(str + 1) == '0' || *(str + 1) == '\0'))
		*error = true;
	else if (*str == '-' && !is_digit(++str, error))
		*error = true;
	else if (*str == '+')
		*error = true;
	if (!*error)
		check_signs(str + 1, error);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int	atoi2(const char *str, bool *error)
{
	int		sign;
	long	number;

	sign = 1;
	number = 0;
	check_signs(str, error);
	if (*str == '-' && !*error)
	{
		sign = -1;
		str++;
	}
	is_digit(str, error);
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	if (number * sign > INT_MAX || number * sign < INT_MIN)
		*error = true;
	str++;
	return (number * sign);
}
