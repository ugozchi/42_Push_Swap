/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:55:13 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/26 21:30:59 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * rotate(t_list **a):
 * Effectue une rotation sur la pile *a* en déplaçant le premier élément au bas de la pile.
 * Le pointeur 'next' du dernier élément est mis à jour pour inclure l'ancien premier élément,
 * et le pointeur 'previous' du nouvel élément en haut de la pile est mis à NULL.
 * Utilisée par ra(), rb(), et rr() pour effectuer une rotation sur une ou deux piles.
 */
static void	rotate(t_list **a)
{
	t_list	*last;

	last = find_last(*a);
	last->next = (*a);
	*a = (*a)->next;
	(*a)->previous = NULL;
	last->next->previous = last;
	last->next->next = NULL;
}

void	ra(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
