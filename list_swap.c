/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:23:05 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/26 21:33:46 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * swap(t_list **a):
 * Échange les deux premiers éléments de la pile *a* en ajustant les pointeurs 'next' et 'previous' 
 * pour que le deuxième élément devienne le premier et vice versa. 
 * Si la pile ne contient qu'un seul élément ou est vide, l'opération n'a pas lieu.
 * Utilisée par sa(), sb(), et ss() pour effectuer des échanges dans les piles.
 */
static void	swap(t_list **a)
{
	*a = (*a)->next;
	(*a)->previous->previous = *a;
	(*a)->previous->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->previous = (*a)->previous;
	(*a)->next = (*a)->previous;
	(*a)->previous = NULL;
}

void	sa(t_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
