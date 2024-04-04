/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:53:22 by rachou            #+#    #+#             */
/*   Updated: 2024/04/04 13:37:05 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_error(char *str_nb)//Me permet de gérer les erreurs de syntaxe et renvoie "1" pour "erreur" si l'une des conditions suivantes est remplie.
{
	if (!(*str_nb == '+' || *str_nb == '-' || (*str_nb >= '0' && *str_nb <= '9')))//Vérifie si le premier caractère de la chaîne d'entrée ne contient pas de signe ou de chiffre.
		return (1);
	if ((*str_nb == '+' || *str_nb == '-') && !(str_nb[1] >= '0' && str_nb[1] <= '9'))//Vérifie si le premier caractère de la chaîne d'entrée contient un signe, mais que le deuxième caractère ne contient pas de chiffre.
		return (1);
	while (*++str_nb)//Si les conditions d'erreur ci-dessus sont passées, pré-incrémenter pour pointer vers le caractère suivant de la chaîne et boucler jusqu'à ce que la fin de la chaîne soit atteinte.
	{
		if (!(*str_nb >= '0' && *str_nb <= '9'))//Vérifie si le caractère suivant de la chaîne n'est pas un chiffre.
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack *a, int nb)//Fonction qui vérifie les numéros d'entrée en double dans la pile 'a'.
{
	if(!a)
		return (0);
	while (a)
	{
		if (a->value == nb)//Vérifie si la valeur du nœud actuel est égale à "nb".
			return (1);
		a = a->next;//Passer au nœud suivant pour vérifier les doublons.
	}
	return (0);
}

void	free_stack(t_stack **stack)//Définit une fonction pour libérer une pile si il y a des erreurs.
{
	t_stack	*tmp;//Pour stocker le noeud suivant dans la pile avant que le noeud actuel ne soit libéré, prcq une fois qu'un noeud est libéré, je ne pourrai pas accéder à son prochain pointeur.
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)//Tant qu'un nœud existe dans la pile.
	{
		tmp = current->next;//Attribue à 'tmp' le pointeur vers le noeud suivant.
		//current->value = 0;
		free(current);//Libère le noeud actuel, libérant la mémoire occupée par ce noeud.
		current = tmp;//Attribuer 'tmp' comme premier noeud actuel.
	}
	*stack = NULL;
}

void	free_errors(t_stack **a)//Définir une fonction qui, en cas d'erreur unique, libère la pile et imprime un message d'erreur.
{
	free_stack(a);
	write(1, "Error\n", 6);
	exit(1);//Permet de mettre fin immédiatement au programme.
}
