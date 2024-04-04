/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:20:01 by rachou            #+#    #+#             */
/*   Updated: 2024/04/04 14:28:34 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)//Fait pivoter le noeud inférieur d'une pile vers le haut.
{
	t_stack	*last;//Pour stocker le pointeur vers le dernier noeud.

	if (!*stack || !(*stack)->next)//Vérifie si la pile est vide ou s'il y a un noeud.
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;//Attribue à l'attribut 'next' du noeud avant lui-même, 'NULL' le définissant effectivement comme dernier noeud actuel.
	last->next = *stack;//Attribue à son propre attribut 'next' comme noeud supérieur de la pile.
	last->prev = NULL;//Se détache du noeud qui le précède.
	*stack = last;//Complete en s'ajoutant au sommet de la pile et contient désormais le pointeur vers le noeud supérieur.
	last->next->prev = last;//Mise à jour le dernier noeud actuel de la pile.
}

void	rra(t_stack **a)
{
    rev_rotate(a);
	write(1, "rra\n", 4);
}
void	rrb(t_stack **b)
{
    rev_rotate(b);
    write(1, "rrb\n", 4);
}
void	rrr(t_stack **a, t_stack **b)
{
    rev_rotate(a);
    rev_rotate(b);
	write(1, "rrr\n", 4);
}
