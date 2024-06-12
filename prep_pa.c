/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:13:51 by ahusic            #+#    #+#             */
/*   Updated: 2024/06/05 19:19:44 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;

	temp = stack_b;
	while (stack_b)
	{
		stack_b->num_moves = 0;
		if (stack_b->over_middle)
			stack_b->num_moves += stack_b->index;
		else
			stack_b->num_moves += stack_size(temp) - stack_b->index;
		if (stack_b->target->over_middle)
			stack_b->num_moves += stack_b->target->index;
		else
			stack_b->num_moves += stack_size(stack_a) - stack_b->target->index;
		stack_b = stack_b->next;
	}
}

void	target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;
	t_stack	*target_node;
	int		target_value;

	if (!stack_b)
		return ;
	while (stack_b)
	{
		temp = stack_a;
		target_value = INT_MAX;
		while (temp)
		{
			if (temp->value > stack_b->value && temp->value < target_value)
			{
				target_value = temp->value;
				target_node = temp;
			}
			temp = temp->next;
		}
		if (target_value == INT_MAX)
			stack_b->target = find_min(stack_a);
		else
			stack_b->target = target_node;
		stack_b = stack_b->next;
	}
}

void	pa_prep(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (cheapest != *stack_b)
	{
		if (cheapest->over_middle)
			rb(stack_b, SINGLE_OP);
		else
			rrb(stack_b, SINGLE_OP);
	}
	while (cheapest->target != *stack_a)
	{
		if (cheapest->target->over_middle)
			ra(stack_a, SINGLE_OP);
		else
			rra(stack_a, SINGLE_OP);
	}
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*stack_b);
	if (cheapest->over_middle && cheapest->target->over_middle)
	{
		while (cheapest != *stack_b && cheapest->target != *stack_a)
			rr(stack_a, stack_b, DOUBLE_OP);
		index_init(*stack_a);
		index_init(*stack_b);
	}
	if (!cheapest->over_middle && !cheapest->target->over_middle)
	{
		while (cheapest != *stack_b && cheapest->target != *stack_a)
			rrr(stack_a, stack_b, DOUBLE_OP);
		index_init(*stack_a);
		index_init(*stack_b);
	}
	pa_prep(stack_a, stack_b, cheapest);
	pa(stack_a, stack_b);
}

