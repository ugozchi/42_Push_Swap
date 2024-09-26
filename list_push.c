/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:32:03 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/26 21:23:21 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * push(t_list **a, t_list **b):
 * Déplace le premier élément de la pile *a* vers la pile *b*. 
 * Si *b* n'est pas vide, l'élément devient le nouveau premier élément de *b* 
 * tout en conservant la structure de la liste chaînée doublement liée.
 * Utilisée dans les fonctions pa() et pb() pour transférer des éléments entre les piles pendant le tri.
 */
static void	push(t_list **a, t_list **b)
{
	t_list	*push_node;

	push_node = *a;
	if (*a == NULL)
		return ;
	*a = (*a)->next;
	if (*a)
		(*a)->previous = NULL;
	if (*b == NULL)
	{
		*b = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *b;
		push_node->next->previous = push_node;
		*b = push_node;
	}
}

void	pa(t_list **a, t_list **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
