/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:34:26 by ahusic            #+#    #+#             */
/*   Updated: 2024/06/05 19:09:00 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_cheapest(t_stack *stack)
{
	t_stack	*cheapest;

	cheapest = stack;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->num_moves < cheapest->num_moves)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void	sort_3(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && a > c)
		ra(stack, true);
	else if (b > a && b > c)
		rra(stack, true);
	a = (*stack)->value;
	b = (*stack)->next->value;
	if (a > b)
		sa(*stack, true);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_size(*stack_a) > 3)
	{
		index_init(*stack_a);
		if (find_min(*stack_a)->over_middle)
		{
			while (find_min(*stack_a)->index != (*stack_a)->index)
				ra(stack_a, SINGLE_OP);
		}
		else
		{
			while (find_min(*stack_a)->index != (*stack_a)->index)
				rra(stack_a, SINGLE_OP);
		}
		pb(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		sort_3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	final_sort(t_stack **stack_a)
{
	t_stack	*minimum;

	minimum = find_min(*stack_a);
	index_init(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	while (minimum != *stack_a)
	{
		if (minimum->over_middle)
			ra(stack_a, true);
		else
			rra(stack_a, true);
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) > 3)
		pb(stack_a, stack_b);
	if (stack_size(*stack_a) > 3)
		pb(stack_a, stack_b);
	while (stack_size(*stack_a) > 1 && !is_sorted(*stack_a))
	{
		index_init(*stack_a);
		index_init(*stack_b);
		target_b(*stack_a, *stack_b);
		pb_cost(*stack_a, *stack_b);
		push_to_b(stack_a, stack_b);
	}
	while (*stack_b)
	{
		index_init(*stack_a);
		index_init(*stack_b);
		target_a(*stack_a, *stack_b);
		pa_cost(*stack_a, *stack_b);
		push_to_a(stack_a, stack_b);
	}
	final_sort(stack_a);
}
