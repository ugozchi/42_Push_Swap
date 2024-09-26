/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:55:38 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/26 21:26:48 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * reverse_rotate(t_list **a):
 * Déplace le dernier élément de la pile *a* en haut de la pile tout en mettant à jour 
 * les pointeurs 'next' et 'previous' pour maintenir la structure de la liste chaînée doublement liée.
 * Utilisée dans les fonctions rra(), rrb(), et rrr() pour effectuer une rotation inverse sur une ou deux piles.
 */
static void	reverse_rotate(t_list **a)
{
	t_list	*last;

	last = find_last(*a);
	last->previous->next = NULL;
	last->next = *a;
	last->previous = NULL;
	*a = last;
	last->next->previous = last;
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
