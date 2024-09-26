/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:55:00 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/26 21:44:36 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * pos_and_med(t_list *a):
 * Parcourt la pile *a* et attribue une position à chaque élément (index basé sur sa position dans la pile).
 * Marque les éléments comme appartenant à la première moitié (médiane) de la pile ou à la deuxième moitié.
 * Context: utilisée pour classer les éléments en fonction de leur position dans la pile, facilitant le calcul des coûts de déplacement.
 */
static void	pos_and_med(t_list *a)
{
	int	i;
	int	med;

	i = 0;
	if (a == NULL)
		return ;
	med = count_node(a) / 2;
	while (a)
	{
		a->position = i;
		if (i <= med)
			a->mediane = true;
		else
			a->mediane = false;
		a = a->next;
		i++;
	}
	return ;
}

/*
 * find_target(t_list *a, t_list *b):
 * Trouve l'endroit où chaque élément de la pile *b* devrait être inséré dans la pile *a* pour maintenir l'ordre croissant.
 * L'élément "cible" est celui immédiatement supérieur à l'élément de *b* dans *a*.
 * Context: utilisée pour déterminer la cible d'insertion lors du tri, chaque élément de *b* doit être réinséré dans *a* au bon endroit.
 */
static void	find_target(t_list *a, t_list *b)
{
	long	i;
	t_list	*begin;

	if (b == NULL)
		return ;
	i = LONG_MAX;
	while (b)
	{
		i = LONG_MAX;
		begin = a;
		while (begin)
		{
			if (begin->nb > b->nb && begin->nb < i)
			{
				b->target = begin;
				i = begin->nb;
			}
			begin = begin->next;
		}
		if (i == LONG_MAX)
			b->target = find_smallest(a);
		b = b->next;
	}
	return ;
}

/*
 * find_cost(t_list *a, t_list *b):
 * Calcule le coût de déplacement pour chaque élément de *b* afin de l'insérer dans la pile *a* à sa position cible.
 * Le coût est basé sur la distance de l'élément dans *b* et la distance de la cible dans *a*, optimisant ainsi les mouvements.
 * Context: utilisée pour minimiser les mouvements nécessaires lors de l'insertion d'un élément de *b* dans *a*.
 */
static void	find_cost(t_list *a, t_list *b)
{
	int	len_b;
	int	len_a;

	if (b == NULL)
		return ;
	len_b = count_node(b);
	len_a = count_node(a);
	while (b)
	{
		b->cost = b->position;
		if (b->mediane == false)
			b->cost = (len_b - (b->position));
		if (b->target->mediane == true)
			b->cost += b->target->position;
		else
			b->cost += (len_a - (b->target->position));
		b = b->next;
	}
	return ;
}

/*
 * find_cheapest(t_list *b):
 * Identifie l'élément de *b* avec le coût d'insertion le plus bas et le marque comme étant "le moins cher".
 * Cet élément sera inséré en premier dans la pile *a* car il nécessite le moins de mouvements.
 * Context: utilisée pour choisir le prochain élément à réinsérer dans *a* en fonction du coût calculé dans find_cost().
 */
static void	find_cheapest(t_list *b)
{
	t_list	*cheapest_node;
	long	i;

	if (b == NULL)
		return ;
	cheapest_node = NULL;
	i = LONG_MAX;
	while (b)
	{
		if (b->cost < i)
		{
			cheapest_node = b;
			i = b->cost;
		}
		b = b->next;
	}
	cheapest_node->cheapest = true;
	return ;
}

/*
 * init_algo(t_list *a, t_list *b):
 * Appelle une série de fonctions pour initialiser l'algorithme :
 * - Attribue des positions et marque les éléments comme médiane (pos_and_med()).
 * - Trouve les cibles pour les éléments de *b* dans *a* (find_target()).
 * - Calcule les coûts d'insertion (find_cost()).
 * - Trouve l'élément avec le coût d'insertion le plus bas (find_cheapest()).
 * Context: utilisée pour préparer et initialiser toutes les informations nécessaires avant d'insérer des éléments de *b* dans *a*.
 */
void	init_algo(t_list *a, t_list *b)
{
	pos_and_med(a);
	pos_and_med(b);
	find_target(a, b);
	find_cost(a, b);
	find_cheapest(b);
}
