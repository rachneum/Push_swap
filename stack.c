/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:31:04 by rachou            #+#    #+#             */
/*   Updated: 2024/04/05 15:42:32 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long ft_atol(const char *str)//Convertit chaque chaîne en une valeur longue.
{
    long	rlt;
	char	sign;

	rlt = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		rlt = rlt * 10 + *str - 48;
		str++;
	}
	return (rlt * sign);
}

static void append(t_stack **stack, int nb)//Recherche le dernier noeud à ajouter à la liste chaînée.
{
    t_stack *new_node;//Pour stocker un pointeur vers le nouveau noeud à créer avec la valeur 'n'.
    t_stack *last_node;//Pour stocker un pointeur vers le dernier noeud actuel de la pile.

    if (!stack)
        return ;
    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return ;
    new_node->next = NULL;//Définit le pointeur suivant du nouveau noeud sur NULL car ce sera le dernier noeud de la liste.
    new_node->value = nb;//Définit les données "suivantes" du nouveau neoud sur la valeur "n".
    if (!(*stack))//Vérifie si la pile est vide ou pointe actuellement vers NULL, indiquant qu'un premier noeud doit être trouvé.
    {
        *stack = new_node;//Si il est vide, mettre à jour le pointeur *stack pour pointer vers le noeud, ce qui en fait le nouveau tête de la liste chaînée.
        new_node->prev = NULL;//Définit le pointeur précédent du noeud principal sur NULL car il s'agit du premier noeud.
    }
    else//Si la pile n'est pas vide, ca signifie qu'il y a des noeuds existants dans la liste chaînée.
    {
        last_node = find_last_node(*stack);//Trouver le dernier noeud.
        last_node->next = new_node;//Ajouter le nouveau noeud au dernier noeud.
        new_node->prev = last_node;//Mettre à jour le pointeur précédent du nouveau noeud et compléter l'ajout.
    }
}

void    stack_init(t_stack **a, char **argv)//Lance la pile 'a' en gérant toutes les erreurs et en ajoutant les noeuds requis pour compléter une pile
{
    long    nb;
    int     i;

    i = 0;
    while (argv[i])
    {
        if(syntax_error(argv[i]))
            free_errors(a);
        nb = ft_atol(argv[i]);
        if (nb > LONG_MAX || nb < LONG_MIN)//Vérifie overflow.
            free_errors(a);
        if (error_duplicate(*a, nb))
            free_errors(a);
        append(a, nb);//Si il n'y a pas d'erreur, ajoute le noeud à la liste chaînée en prenant un pointeur pour empiler "a", crée un nouveau noeud et attribuer "nb" à ce nouveau noeud.
        i++;
    }
}
