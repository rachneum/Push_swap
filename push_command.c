/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:11:14 by rachou            #+#    #+#             */
/*   Updated: 2024/03/24 15:02:07 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_stack **dst, t_stack **src)//Fonction qui pousse un noeud supérieur, d'une pile au noeud supérieur d'une autre.
{
    t_stack *push_node;//Utilisé pour stocker le pointeur vers le noeud à pousser.

    if (!*src)//Le noeud supérieur d'une pile à pousser.
        return ;
    push_node = *src;//Le noeud supérieur à pousser est affecté à la variable 't_stack'.
    *src = (*src)->next;//Déplacer le pointeur de la pile vers le noeud suivant, qui deviendra le prochain "noeud supérieur" après que le noeud précédent soit "supprimé".
    if (*src)//Vérifie si le noeud actuel existe.
        (*src)->prev = NULL;//Définit le noeud actuel comme tête de pile.
    push_node->prev = NULL;//Détache le noeud à pousser de sa pile.
    if (!*dst)//Vérifie si l'autre pile est vide.
    {
        *dst = push_node;//S'il est vide, attribuer comme premier noeud de cette pile le noeud que nous voulons pousser.
        push_node->next = NULL;//S'assurer qu'il est également défini comme dernier noeud, par ex. correctement null terminer la pile.
    }
    else//Si l'autre pile vers laquelle nous voulons pousser n'est pas vide.
    {
        push_node->next = *dst;//Attribue le noeud à pousser, en haut du noeud supérieur actuel de la pile.
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
