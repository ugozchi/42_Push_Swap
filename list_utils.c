/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:09:28 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/26 21:35:24 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * in_order(t_list *a):
 * Vérifie si les éléments de la pile *a* sont dans l'ordre croissant. 
 * Parcourt la pile et compare chaque élément avec le suivant.
 * Renvoie true si la pile est ordonnée, false sinon.
 * Utilisée pour vérifier si la pile est déjà triée.
 */
bool	in_order(t_list *a)
{
	if (a == NULL)
		return (true);
	while (a->next)
	{
		if (a->nb > a->next->nb)
			return (false);
		a = a->next;
	}
	return (true);
}

/*
 * count_node(t_list *a):
 * Compte le nombre total d'éléments dans la pile *a*.
 * Parcourt la pile en incrémentant un compteur pour chaque élément.
 * Renvoie le nombre total de nœuds dans la liste chaînée.
 * Utilisée pour évaluer la taille de la pile pendant les opérations de tri.
 */
int	count_node(t_list *a)
{
	int	count;

	if (a == NULL)
		return (0);
	count = 0;
	while (a)
	{
		a = a->next;
		count++;
	}
	return (count);
}

/*
 * find_biggest(t_list *a):
 * Trouve et renvoie un pointeur vers le nœud contenant la plus grande valeur dans la pile *a*.
 * Parcourt la pile en comparant chaque élément pour trouver le plus grand.
 * Renvoie un pointeur vers l'élément le plus grand, ou NULL si la pile est vide.
 */
t_list	*find_biggest(t_list *a)
{
	t_list	*biggest;
	int		i;

	if (a == NULL)
		return (NULL);
	biggest = NULL;
	i = INT_MIN;
	while (a)
	{
		if (i < a->nb)
		{
			biggest = a;
			i = a->nb;
		}
		a = a->next;
	}
	return (biggest);
}

/*
 * find_smallest(t_list *a):
 * Trouve et renvoie un pointeur vers le nœud contenant la plus petite valeur dans la pile *a*.
 * Parcourt la pile en comparant chaque élément pour trouver le plus petit.
 * Renvoie un pointeur vers l'élément le plus petit, ou NULL si la pile est vide.
 */
t_list	*find_smallest(t_list *a)
{
	t_list	*smallest;
	int		i;

	if (a == NULL)
		return (NULL);
	smallest = NULL;
	i = INT_MAX;
	while (a)
	{
		if (i > a->nb)
		{
			smallest = a;
			i = a->nb;
		}
		a = a->next;
	}
	return (smallest);
}

/*
 * find_last(t_list *a):
 * Trouve et renvoie un pointeur vers le dernier élément de la pile *a*.
 * Parcourt la pile jusqu'à ce que l'élément sans suivant (next == NULL) soit trouvé.
 * Renvoie un pointeur vers cet élément, ou NULL si la pile est vide.
 */
t_list	*find_last(t_list *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}
