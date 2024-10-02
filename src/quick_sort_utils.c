/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:15:02 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/28 16:31:58 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

/* max_content - Trouve l'élément ayant la valeur maximale dans la pile.
 * @lst: Pointeur vers la pile à analyser.
 *
 * Cette fonction parcourt la liste `lst` et retourne un pointeur vers
 * l'élément ayant la plus grande valeur.
 * 
 * Retourne: Un pointeur vers l'élément ayant la valeur maximale.*/
void	*max_content(t_list *lst)
{
	t_list	*max_node;

	if (!lst)
		return (NULL);
	max_node = lst;
	while (lst)
	{
		if (lst->content > max_node->content)
			max_node = lst;
		lst = lst->next;
	}
	return (max_node);
}

/* small_sort - Trie une petite pile a (de taille <= 3).
 * @a: Pointeur vers la pile a à trier.
 *
 * Cette fonction trie une pile `a` contenant trois éléments ou moins
 * en utilisant un algorithme simple. Si l'élément ayant la plus grande
 * valeur est en tête ou en deuxième position, des rotations ou des échanges
 * sont effectués pour trier la pile.*/
void	small_sort(t_list **a)
{
	t_list	*max;

	max = max_content(*a);
	if (max == *a)
		ft_ra(a, 1);
	else if (max == (*a)->next)
		ft_rra(a, 1);
	if ((*a)->content > (*a)->next->content)
		ft_sa(a, 1);
}
