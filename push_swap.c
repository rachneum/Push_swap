/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:04:21 by rachou            #+#    #+#             */
/*   Updated: 2024/03/26 15:19:49 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	target_node_b(t_stack *a, t_stack *b)//Fonction qui me permet de trouver les noeuds target dans ma stack 'b' pour les noeuds de la stack 'a'.
{
    t_stack *current_b;//Permet de me servir de ma stack 'b' sans la modifier (c'est une sorte de copie)
    t_stack *current_target_node;
    long    target;

    while (a)
    {
        current_b = b;
        current_target_node = target_node;
        target = LONG_MIN;
	    while (current_b)
        {
            if ((a->value > current_b->value) && (target < current_b->value))
            {
                a->current_target_node = current_b->value;
                target = current_b->value;
            }
            current_b = current_b->next;
        }
        if (target == LONG_MIN)
            a->current_target_node = find_max(b);//Dans le cas où mon noeud 'a' ne trouve pas un noeud target le plus proche petit, j'irai trouver le plus proche grand à la place.
        else


        a = a->next;
    }
}

int	target_node_a(t_stack *a, t_stack *b)//Fonction qui me permet de trouver les noeuds target dans ma stack 'a' pour les noeuds de la stack 'b'.
{
    t_stack *current_a;//Permet de me servir de ma stack 'a' sans la modifier (c'est une sorte de copie)
    t_stack *current_target_node;
    long    target;

    while (b)
    {
        current_a = a;
        current_target_node = target_node;
        target = LONG_MAX;
	    while (current_a)
        {
            if ((b->value < current_a->value) && (target > current_a->value))
            {
                b->current_target_node = current_a->value;
                target = current_a->value;
            }
            current_a = current_a->next;
        }
        if (target == LONG_MAX)
            b->current_target_node = find_min(a);//Dans le cas où mon noeud 'b' ne trouve pas un noeud target le plus proche grand, j'irai trouver le plus proche petit à la place.
        else

        b = b->next;
    }
}

void    push_cost(t_stack *a, t_stack *b)
{

}