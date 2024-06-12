/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:14:34 by ahusic            #+#    #+#             */
/*   Updated: 2024/06/05 19:22:05 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;

	temp = stack_a;
	while (stack_a)
	{
		stack_a->num_moves = 0;
		if (stack_a->over_middle)
			stack_a->num_moves += stack_a->index;
		else
			stack_a->num_moves += stack_size(temp) - stack_a->index;
		if (stack_a->target->over_middle)
			stack_a->num_moves += stack_a->target->index;
		else
			stack_a->num_moves += stack_size(stack_b) - stack_a->target->index;
		stack_a = stack_a->next;
	}
}

void	target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;
	t_stack	*target_node;
	int		target_value;

	if (!stack_a)
		return ;
	while (stack_a)
	{
		temp = stack_b;
		target_value = INT_MIN;
		while (temp)
		{
			if (temp->value < stack_a->value && temp->value > target_value)
			{
				target_value = temp->value;
				target_node = temp;
			}
			temp = temp->next;
		}
		if (target_value == INT_MIN)
			stack_a->target = find_max(stack_b);
		else
			stack_a->target = target_node;
		stack_a = stack_a->next;
	}
}

void	pb_prep(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (cheapest != *stack_a)
	{
		if (cheapest->over_middle)
			ra(stack_a, SINGLE_OP);
		else
			rra(stack_a, SINGLE_OP);
	}
	while (cheapest->target != *stack_b)
	{
		if (cheapest->target->over_middle)
			rb(stack_b, SINGLE_OP);
		else
			rrb(stack_b, SINGLE_OP);
	}
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*stack_a);
	if (cheapest->over_middle && cheapest->target->over_middle)
	{
		while (cheapest != *stack_a && cheapest->target != *stack_b)
			rr(stack_a, stack_b, DOUBLE_OP);
		index_init(*stack_a);
		index_init(*stack_b);
	}
	if (!cheapest->over_middle && !cheapest->target->over_middle)
	{
		while (cheapest != *stack_a && cheapest->target != *stack_b)
			rrr(stack_a, stack_b, DOUBLE_OP);
		index_init(*stack_a);
		index_init(*stack_b);
	}
	pb_prep(stack_a, stack_b, cheapest);
	pb(stack_a, stack_b);
}
