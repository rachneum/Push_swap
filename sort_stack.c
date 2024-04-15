/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:54:59 by rachou            #+#    #+#             */
/*   Updated: 2024/04/15 11:56:15 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	min_on_top(t_stack **a)
{
	if (!a || !*a)
		return ;
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	if (!a || !(*a) || !(*a)->next)
		return ;
	biggest_node = find_max(*a);
	if (*a == biggest_node)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
