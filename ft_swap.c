/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:08:39 by rachou            #+#    #+#             */
/*   Updated: 2024/04/04 14:54:00 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)//Permute les positions du noeud supérieur et du deuxième noeud d'une pile.
{
	if (!*head || !(*head)->next)//Vérifie si le noeud d'arrêt ou le deuxième noeud d'une pile existe.
		return ;
	*head = (*head)->next;//Mise à jour 'head' pour pointer vers le noeud suivant, en échangeant efficacement le premier et le deuxième noeuds.
	(*head)->prev->prev = *head;//Mise à jour le pointeur 'prev' du noeud avant la 'nouvelle tête' pour pointer vers la 'nouvelle tête'.
	(*head)->prev->next = (*head)->next;//Mise à jour le pointeur "suivant" du noeud avant la "nouvelle tête" pour ignorer "l'ancienne tête" et pointer directement vers la "nouvelle tête".
	if ((*head)->next)//Vérifie s'il y a un noeud "suivant" après la "nouvelle tête" et
		(*head)->next->prev = (*head)->prev;//Si c'est le cas, mettre à jour son pointeur 'prev' pour pointer vers la 'nouvelle tête'.
	(*head)->next = (*head)->prev;//Mise à jour le pointeur "suivant" de la "nouvelle tête" pour qu'il pointe vers "l'ancienne tête", inversant ainsi leurs positions.
	(*head)->prev = NULL;//Définit le pointeur 'prev' de la 'nouvelle tête' sur 'NULL' pour terminer l'échange.
}

void	sa(t_stack	**a)//Échange les deux premiers noeuds de la pile 'a' et imprimer l'instruction.
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)//Échange les deux premiers noeuds de la pile 'b' et imprimer l'instruction.
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)//Échange simultanément les deux premiers noeuds de la pile et imprimer l'instruction.
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
