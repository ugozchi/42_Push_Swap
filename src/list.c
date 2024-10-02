/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:56:55 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/28 16:22:16 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

/* ft_lstnew - Crée un nouvel élément de la liste chaînée.
 * @content: Le contenu à stocker dans le nouvel élément.
 *
 * Cette fonction alloue de la mémoire pour un nouveau nœud de la liste
 * et initialise ses champs. En cas d'échec d'allocation, elle appelle
 * error_exit().
 *
 * Retourne: Un pointeur vers le nouvel élément créé.*/
t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		error_exit();
	new_node->content = content;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

/* ft_lstadd - Ajoute un nouvel élément à la fin de la liste chaînée.
 * @lst: Pointeur vers le pointeur du premier élément de la liste.
 * @new: Le nouvel élément à ajouter à la liste.
 *
 * Cette fonction ajoute le nœud `new` à la fin de la liste `lst`.
 * Si la liste est vide, le nouvel élément devient le premier élément.*/
void	ft_lstadd(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
}

/* ft_lstlast - Renvoie le dernier élément de la liste chaînée.
 * @lst: Pointeur vers le premier élément de la liste.
 *
 * Cette fonction parcourt la liste `lst` jusqu'à atteindre
 * le dernier élément, qu'elle retourne.
 *
 * Retourne: Un pointeur vers le dernier élément de la liste, ou NULL
 * si la liste est vide.*/
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/* ft_lstsize - Calcule la taille de la liste chaînée.
 * @lst: Pointeur vers le premier élément de la liste.
 *
 * Cette fonction parcourt la liste `lst` et compte le nombre
 * d'éléments qu'elle contient.
 *
 * Retourne: Le nombre d'éléments dans la liste.*/
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
