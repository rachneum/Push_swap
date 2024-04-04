/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:04:21 by rachou            #+#    #+#             */
/*   Updated: 2024/04/03 14:49:13 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void target_node_b(t_stack *a, t_stack *b)//Fonction qui me permet de trouver les noeuds target dans ma stack 'b' pour les noeuds de la stack 'a'.
{
    t_stack *target_node;
    t_stack *current_b;//Permet de me servir de ma stack 'b' sans la modifier (c'est une sorte de copie)
    long    target;

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
            a->target_node = find_max(b);//Dans le cas où mon noeud 'a' ne trouve pas un noeud target le plus proche petit, j'irai trouver le plus proche grand à la place.
        else
            a->target_node = target_node;
        a = a->next;
    }
}

static void target_node_a(t_stack *a, t_stack *b)//Fonction qui me permet de trouver les noeuds target dans ma stack 'a' pour les noeuds de la stack 'b'.
{
    t_stack *target_node;
    t_stack *current_a;//Permet de me servir de ma stack 'a' sans la modifier (c'est une sorte de copie)
    long    target;

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
            b->target_node = find_min(a);//Dans le cas où mon noeud 'b' ne trouve pas un noeud target le plus proche grand, j'irai trouver le plus proche petit à la place.
        else
            b->target_node = target_node;
        b = b->next;
    }
}

static void	push_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}
