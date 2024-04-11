/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:21:35 by rachou            #+#    #+#             */
/*   Updated: 2024/04/11 13:21:33 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	target_node_b(t_stack *a, t_stack *b)
{
	t_stack	*target_node;
	t_stack	*current_b;
	long	target;

	while (a)
	{
		current_b = b;
		target = LONG_MIN;
		while (current_b)
		{
			if ((current_b->value < a->value) && (current_b->value > target))
			{
				target_node = current_b;
				target = current_b->value;
			}
			current_b = current_b->next;
		}
		if (target == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	target_node_a(t_stack *a, t_stack *b)
{
	t_stack	*target_node;
	t_stack	*current_a;
	long	target;

	while (b)
	{
		current_a = a;
		target = LONG_MAX;
		while (current_a)
		{
			if ((current_a->value > b->value) && (current_a->value > target))
			{
				target_node = current_a;
				target = current_a->value;
			}
			current_a = current_a->next;
		}
		if (target == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

static void	cost_analysis_a(t_stack *a, t_stack *b)//
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_price = a->index;
		if (!(a->median))
			a->push_price = len_a - (a->index);
		if (a->target_node->median)
			a->push_price += a->target_node->index;
		else
			a->push_price += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	init_nodes_a(t_stack *a, t_stack *b)//
{
	set_index(a);
	set_index(b);
	target_node_b(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	target_node_a(a, b);
}
