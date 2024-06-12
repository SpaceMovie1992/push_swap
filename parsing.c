/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:08:36 by ahusic            #+#    #+#             */
/*   Updated: 2024/06/11 16:46:47 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	dup_check(t_stack *stack)
{
	t_stack	*check;
	t_stack	*current;

	if (!stack)
		free_stack(stack, true);
	current = stack;
	while (current != NULL)
	{
		check = current->next;
		while (check != NULL)
		{
			if (current->value == check->value)
				free_stack(stack, true);
			check = check->next;
		}
		current = current->next;
	}
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		free_stack(stack, true);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*arg_parse(int argc, char **argv, bool *error)
{
	t_stack	*a;
	char	**parsed;
	int		i;
	int		j;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		parsed = ft_split(argv[i], ' ');
		if (!*parsed)
			*error = true;
		j = 0;
		while (parsed[j])
		{
			add_node(&a, atoi2(parsed[j], error));
			j++;
		}
		free_str(parsed);
		i++;
	}
	if (*error)
		free_stack(a, true);
	return (a);
}
