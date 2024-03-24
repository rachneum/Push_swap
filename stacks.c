/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:58:54 by rachou            #+#    #+#             */
/*   Updated: 2024/03/24 15:02:47 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long ft_atol(const char *str)//Définit une fonction qui convertit chaque chaîne en une valeur longue.
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

static void append(t_stack **stack, int nb)//Fonction qui recherche le dernier noeud à ajouter à la liste chaînée.
{
    t_stack *new_node;//Pour stocker un pointeur vers le nouveau noeud à créer avec la valeur 'n'.
    t_stack *last_node;//Pour stocker un pointeur vers le dernier noeud actuel de la pile.

    if (!stack)
        return ;
    new_node = malloc(sizeof(t_stack));//Alloue de la mémoire pour le nouveau noeud.
    if (!new_node)
        return ;
    new_node->next = NULL;//Définit le pointeur suivant du nouveau noeud sur NULL car ce sera le dernier noeud de la liste.
    new_node->value = nb;//Définit les données "suivantes" du nouveau neoud sur la valeur "n".
    if (!(*stack))//Vérifie si la pile est vide ou pointe actuellement vers NULL, indiquant qu'un premier noeud doit être trouvé.
    {
        *stack = new_node;//S'il est vide, mettre à jour le pointeur *stack pour pointer vers le noeud, ce qui en fait le nouveau tête de la liste chaînée.
        new_node->prev = NULL;//Définit le pointeur précédent du noeud principal sur NULL car il s'agit du premier noeud.
    }
    else//Si la pile n'est pas vide, ca signifie qu'il y a des noeuds existants dans la liste chaînée.
    {
        last_node = find_last_node(*stack);//Trouver le dernier noeud.
        last_node->next = new_node;//Ajouter le nouveau noeud au dernier noeud.
        new_node->prev = last_node;//Mettre à jour le pointeur précédent du nouveau noeud et compléter l'ajout.
    }
}

void    init_stack_a(t_stack **a, char **argv)
{
    long    nb;
    int     i;

    i = 0;
    while (argv[i])
    {
        if(error_syntax(argv[i]))
            free_errors(a);
        nb = ft_atol(argv[i]);
        if (nb > INT_MAX || nb < INT_MIN)//Vérifie overflow.
            free_errors(a);
        if (error_duplicate(*a, nb))
            free_errors(a);
        append(a, nb);//S'il n'y a pas d'erreur, ajouter le noeud à la liste chaînée en prenant un pointeur pour empiler "a", créer un nouveau nœud et attribuer "nb" à ce nouveau noeud.
        i++;
    }
}
void	index_stack(t_stack **stack)
{
	t_stack	*head;
	int		idx;

	idx = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = idx++;
		head = get_next_min(stack);
	}
}
