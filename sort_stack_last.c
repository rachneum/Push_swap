/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:13:28 by rachou            #+#    #+#             */
/*   Updated: 2024/04/08 15:38:20 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)//
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->median && cheapest_node->target_node->median)
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			rr(a, b);
	}
	else if (!(cheapest_node->median) && !(cheapest_node->target_node->median))
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			rrr(a, b);
	}
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	min_on_top(t_stack **a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	/*if (stack_sorted(*a))
		return ;
	if (len_a <= 3)
		sort_three(a);*/
	if (len_a-- > 3)//
		pb(b, a);
	if (len_a-- > 3)//
		pb(b, a);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	min_on_top(a);
}
