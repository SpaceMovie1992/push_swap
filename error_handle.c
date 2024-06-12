/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:38:27 by ahusic            #+#    #+#             */
/*   Updated: 2024/06/04 17:22:49 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack *stack, bool error)
{
	t_stack	*tmp;

	if (stack)
	{
		while (stack)
		{
			tmp = stack->next;
			free(stack);
			stack = tmp;
		}
	}
	if (error)
		if_error();
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
