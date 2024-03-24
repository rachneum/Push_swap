/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:01:06 by rachou            #+#    #+#             */
/*   Updated: 2024/03/24 14:58:34 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **stack)//Fonction qui fait pivoter le noeud supérieur de la pile vers le bas de la pile.
{
	t_stack	*last_node;//Pour stocker un pointeur vers le dernier noeud d'une pile.

	if (!*stack || !(*stack)->next)//Vérifie si la pile est vide ou s'il y a un noeud.
		return ;
	last_node = find_last(*stack); 
	last_node->next = *stack;//Attribuer au dernier noeud son attribut 'next' comme noeud supérieur, définissant ainsi le noeud supérieur actuel comme dernier noeud.
	*stack = (*stack)->next;//Attribuer au pointeur du noeud supérieur, le noeud qui le suit (deuxième à partir du haut).
	(*stack)->prev = NULL;//Terminer la configuration du noeud supérieur actuel en le détachant de son noeud supérieur précédent.
	last_node->next->prev = last_node;//Reconnecter le pointeur précédent du deuxième noeud pour pointer vers ce qui était auparavant le dernier noeud de la pile.
	last_node->next->next = NULL;//Attribuer à l'attribut 'next' du dernier noeud actuel, 'NULL' le définissant effectivement comme dernier noeud actuel et correctement null terminant la pile.
}		

void	ra(t_stack_node **a)//Faites pivoter le noeud supérieur "a" vers le bas de la pile et imprimer l'instruction.
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)//Faire pivoter le noeud supérieur 'b' vers le bas de la pile et imprimer l'instruction.
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)//Faire pivoter simultanément les noeuds supérieurs "a" et "b" vers le bas de la pile et imprimer l'instruction.
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}