/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:10:32 by rachou            #+#    #+#             */
/*   Updated: 2024/03/25 10:20:32 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)//Définit une fonction qui fait pivoter le noeud inférieur d'une pile vers le haut.
{
	t_stack	*last;//Pour stocker le pointeur vers le dernier noeud.

	if (!*stack || !(*stack)->next)//Vérifie si la pile est vide ou s'il y a un noeud.
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;//Attribuer à l'attribut 'next' du noeud avant lui-même, 'NULL' le définissant effectivement comme dernier noeud actuel.
	last->next = *stack;//Attribuer à son propre attribut 'next' comme noeud supérieur de la pile.
	last->prev = NULL;//Se détache du noeud qui le précède.
	*stack = last;//Complete en s'ajoutant au sommet de la pile et contient désormais le pointeur vers le noeud supérieur.
	last->next->prev = last;//Mise à jour le dernier noeud actuel de la pile.
}

void    rra(t_stack **a)
{
    rev_rotate(a);
	write(1, "rra\n", 4);
}
void    rrb(t_stack **b)
{
    rev_rotate(b);
	write(1, "rrb\n", 4);
}
void    rrr(t_stack **a, t_stack **b)
{
    rev_rotate(a);
    rev_rotate(b);
	write(1, "rrr\n", 4);
    
}
