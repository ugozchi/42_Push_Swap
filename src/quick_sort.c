/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:05:17 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/28 16:34:02 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

/* get_tab - Convertit les éléments de la pile en un tableau d'entiers.
 * @size: Taille de la pile.
 * @arr: Pointeur vers le tableau d'entiers à remplir.
 * @stack: Pointeur vers la pile à convertir.
 *
 * Cette fonction parcourt la pile `stack` et copie les valeurs de chaque
 * élément dans le tableau `arr`, qui est alloué dynamiquement.*/
void	get_tab(int size, int **arr, t_list **stack)
{
	int		i;
	t_list	*current;

	i = 0;
	current = *stack;
	*arr = malloc(size * sizeof(int));
	if (!*arr)
		error_exit();
	while (i < size)
	{
		(*arr)[i] = current->content;
		current = current->next;
		i++;
	}
}

/* bubble_sort - Trie un tableau d'entiers en utilisant l'algorithme du
   tri à bulles.
 * @size: Taille du tableau.
 * @arr: Pointeur vers le tableau d'entiers à trier.
 *
 * Cette fonction trie un tableau d'entiers `arr` en ordre croissant
 * en utilisant l'algorithme du tri à bulles.*/
void	bubble_sort(int size, int **arr)
{
	int	i;
	int	j;
	int	temp;

	temp = 0;
	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if ((*arr)[i] > (*arr)[j])
			{
				temp = (*arr)[i];
				(*arr)[i] = (*arr)[j];
				(*arr)[j] = temp;
			}
			j++;
		}
		i++;
	}
}

/* get_piv - Calcule la médiane de la pile pour l'utiliser comme pivot.
 * @stack: Pointeur vers la pile à analyser.
 * @data: Pointeur vers la structure de données contenant la médiane.
 * @size: Taille de la pile.
 *
 * Cette fonction convertit la pile en un tableau, trie le tableau,
 * puis récupère la médiane (pivot) pour l'algorithme de tri rapide.*/
void	get_piv(t_list **stack, t_data **data, int size)
{
	int	*arr;

	arr = NULL;
	get_tab(size, &arr, stack);
	bubble_sort(size, &arr);
	(*data)->med = arr[size / 2];
	free(arr);
}

/* still_push - Vérifie s'il reste des éléments à pousser dans la pile b.
 * @a: Pointeur vers la pile a.
 * @med: Valeur de la médiane utilisée comme pivot.
 *
 * Cette fonction parcourt la pile `a` et vérifie s'il existe encore des éléments
 * dont la valeur est inférieure à la médiane (pivot). Si oui, elle retourne 1.
 * 
 * Retourne: 1 s'il reste des éléments à pousser, 0 sinon.*/
int	still_push(t_list **a, int med)
{
	t_list	*stack_a;

	stack_a = *a;
	while (stack_a)
	{
		if (stack_a->content < med)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

/* quick_sort - Trie une pile en utilisant l'algorithme de tri rapide (quick sort).
 * @a: Pointeur vers la pile a (pile principale).
 * @b: Pointeur vers la pile b (pile auxiliaire).
 * @data: Pointeur vers la structure contenant la médiane et autres données.
 *
 * Cette fonction applique l'algorithme du tri rapide sur la pile `a`.
 * Elle utilise la médiane comme pivot pour déplacer les éléments de la pile a
 * vers la pile b. Une fois triée, elle appelle `small_sort` si la pile a
 * contient 3 éléments ou moins.*/
void	quick_sort(t_list **a, t_list **b, t_data **data)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(*a);
	get_piv(a, data, size);
	if (size <= 3)
		return (small_sort(a));
	while (i <= size)
	{
		if ((*a)->content < (*data)->med)
			ft_pb(a, b);
		else if (is_sort(a) || !still_push(a, (*data)->med))
			break ;
		else
			ft_ra(a, 1);
		i++;
	}
	quick_sort(a, b, data);
}
