/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:35:52 by rachou            #+#    #+#             */
/*   Updated: 2024/04/04 16:12:56 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dst, t_stack **src)//Pousse un noeud supérieur d'une pile au noeud supérieur d'une autre.
{
	t_stack	*push_node;//Utilisé pour stocker le pointeur vers le noeud à pousser.

	if (!*src)//Le noeud supérieur d'une pile à pousser.
		return ;
	push_node = *src;
	*src = (*src)->next;//Déplacer le pointeur de la pile vers le noeud suivant, qui deviendra le prochain "noeud supérieur" après que le noeud précédent soit "supprimé".
	if (*src)
		(*src)->prev = NULL;//Définit le noeud actuel comme tête de pile.
	push_node->prev = NULL;//Détache le noeud à pousser de sa pile.
	if (!*dst)
	{
		*dst = push_node;//Si la pile est vide, attribuer comme premier noeud de cette pile le noeud que je veux pousser.
		push_node->next = NULL; //S'assurer qu'il est également défini comme dernier noeud.
	}
	else//Si l'autre pile vers laquelle je veux pousser n'est pas vide.
	{
		push_node->next = *dst;//Attribue le noeud à pousser en haut du noeud supérieur actuel de la pile.
		push_node->next->prev = push_node;//Attribuer à l'attribut 'prev' du "deuxième noeud", le noeud poussé comme noeud supérieur actuel.
		*dst = push_node;//Terminer l'ajout du noeud, le pointeur vers le noeud supérieur de la pile pointe maintenant vers mon noeud récemment poussé.
	}
}

void    pa(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}

void    pb(t_stack **b, t_stack **a)
{
    push(b, a);
    write(1, "pb\n", 3);
}
