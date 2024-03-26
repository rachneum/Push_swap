/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:04:21 by rachou            #+#    #+#             */
/*   Updated: 2024/03/26 11:05:44 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	target_node(t_stack *a, t_stack *b)
{

    long    target;

    target = LONG_MAX;
    while (a)
    {
	    while (b)
        {
            if (a->value > b->value)
                a->target_node = b->value;
                target = b->value:
            if ((a->value > b->value) && a->target_node < b->value)
                a->target_node = b->value;
            b = b->next;
        }
        if (target == INT_MAX)
            a->target_node = find_max(b);
        else


        a = a->next;
    }
}

void    push_cost(t_stack *a, t_stack *b)
{

}