/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:04:21 by rachou            #+#    #+#             */
/*   Updated: 2024/03/26 13:06:25 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	target_node_b(t_stack *a, t_stack *b)//Fonction qui me permet de trouver les noeuds target dans ma stack 'b' pour les noeuds de la stack 'a'.
{
    t_stack *current_b;//Permet de me servir de ma stack 'b' sans la modifier (c'est une sorte de copie)
    long    target;

    while (a)
    {
        current_b = b;
        target = LONG_MAX;
	    while (current_b)
        {
            if (a->value > current_b->value)
                a->target_node = current_b->value;
                target = current_b->value;
            if ((a->value > current_b->value) && (a->target_node < current_b->value))
                a->target_node = current_b->value;
            current_b = current_b->next;
        }
        if (target == LONG_MAX)
            a->target_node = find_max(b);//Dans le cas où mon noeud 'a' ne trouve pas un noeud target le plus proche petit, j'irai trouver le plus proche grand à la place.
        else


        a = a->next;
    }
}

int	target_node_a(t_stack *a, t_stack *b)//Fonction qui me permet de trouver les noeuds target dans ma stack 'a' pour les noeuds de la stack 'b'.
{
    t_stack *current_a;//Permet de me servir de ma stack 'a' sans la modifier (c'est une sorte de copie)
    long    target;

    while (b)
    {
        current_a = a;
        target = LONG_MAX;
	    while (current_a)
        {
            if (b->value > current_a->value)
                b->target_node = current_a->value;
                target = current_a->value;
            if ((b->value > current_a->value) && (b->target_node < current_a->value))
                b->target_node = current_a->value;
            current_a = current_a->next;
        }
        if (target == LONG_MAX)
            b->target_node = find_max(a);//Dans le cas où mon noeud 'b' ne trouve pas un noeud target le plus proche petit, j'irai trouver le plus proche grand à la place.
        else


        b = b->next;
    }
}

void    push_cost(t_stack *a, t_stack *b)
{

}