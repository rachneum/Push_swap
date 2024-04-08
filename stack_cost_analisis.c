/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cost_analisis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:29:37 by rachou            #+#    #+#             */
/*   Updated: 2024/04/08 14:30:34 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int	i;
	int	median;

    if (!stack)
        return ;
	i = 0;
	median = (stack_len(stack) / 2);
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->median = true;
		else
			stack->median = false;
		stack = stack->next;
		i++;
	}
}

void	set_cheapest(t_stack *stack)//
{
	long			cheapest_value;
	t_stack			*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = stack->push_price;
	cheapest_node = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->push_price < cheapest_value)
		{
			cheapest_value = stack->push_price;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

t_stack	*get_cheapest(t_stack *stack)//
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
