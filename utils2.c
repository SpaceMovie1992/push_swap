/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:43:07 by ahusic            #+#    #+#             */
/*   Updated: 2024/06/04 16:38:11 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_init(t_stack *stack)
{
	int		index;
	int		middle;
	t_stack	*current;

	index = 0;
	current = stack;
	middle = stack_size(stack) / 2;
	while (current != NULL)
	{
		current->index = index;
		current->over_middle = (index <= middle);
		current = current->next;
		index++;
	}
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max_node;

	if (stack == NULL)
		return (NULL);
	max_node = stack;
	while (stack->next != NULL)
	{
		stack = stack->next;
		if (stack->value > max_node->value)
			max_node = stack;
	}
	return (max_node);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_node;

	if (stack == NULL)
		return (NULL);
	min_node = stack;
	while (stack->next != NULL)
	{
		stack = stack->next;
		if (stack->value < min_node->value)
			min_node = stack;
	}
	return (min_node);
}

t_stack	*last_node(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	add_node(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (new_node == NULL)
		if_error();
	new_node->value = value;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		last = last_node(*stack);
		last->next = new_node;
		new_node->prev = last;
		new_node->next = NULL;
	}
}
