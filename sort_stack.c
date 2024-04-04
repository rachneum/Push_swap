/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:59:59 by rachou            #+#    #+#             */
/*   Updated: 2024/04/04 09:38:36 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"s

bool    stack_sorted(t_stack *stack)
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

void    sort_three(t_stack **a)
{
    t_stack *biggest_node;
    t_stack *smallest_node;

    if (!a)
        return ;
    if (stack_len(a) == 3)
    {
        biggest_node = find_max(a);
        smallest_node = find_min(a);
        while (a)
        {
            if (a->value == biggest_node)
                ra(a);
            else if (a->next->value == biggest_node)
				rra(a);
			else if (a->value > a->next->value)
				sa(a);		
        }
    }
}
