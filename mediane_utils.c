/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 01:32:22 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/26 21:37:52 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * sort_tab(int len_a, int **tab):
 * Trie un tableau d'entiers de taille len_a dans l'ordre croissant.
 * Utilise un tri par comparaison élémentaire (tri à bulles) pour organiser les valeurs.
 * Context: utilisée pour trier un tableau temporaire afin de calculer la médiane des éléments de la pile *a*.
 */
static void	sort_tab(int len_a, int **tab)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < len_a - 1)
	{
		j = i + 1;
		while (j < len_a)
		{
			if ((*tab)[i] > (*tab)[j])
			{
				temp = (*tab)[i];
				(*tab)[i] = (*tab)[j];
				(*tab)[j] = temp;
			}
			j++;
		}
		i++;
	}
}

/*
 * get_tab(int len_a, int **tab, t_list *a):
 * Remplit un tableau d'entiers en copiant les valeurs de la pile *a* dans ce tableau.
 * Alloue dynamiquement de la mémoire pour le tableau de taille len_a.
 * Context: utilisée pour obtenir un tableau d'entiers représentant la pile *a* avant de le trier pour calculer la médiane.
 */
static void	get_tab(int len_a, int **tab, t_list *a)
{
	int		i;
	t_list	*current;

	i = 0;
	current = a;
	*tab = malloc(len_a * sizeof(int));
	if (*tab == NULL)
		return ;
	while (i < len_a)
	{
		(*tab)[i] = current->nb;
		current = current->next;
		i++;
	}
}

/*
 * get_mediane(t_list *a, int len_a):
 * Calcule et renvoie la médiane des valeurs contenues dans la pile *a*.
 * Convertit la pile *a* en tableau, trie ce tableau avec sort_tab(), et récupère la valeur médiane.
 * Context: utilisée pour diviser la pile *a* en fonction de la médiane afin de transférer les éléments vers *b* dans mediane_a_to_b().
 */
static int	get_mediane(t_list *a, int len_a)
{
	int	*tab;
	int	med;

	tab = NULL;
	get_tab(len_a, &tab, a);
	if (tab == NULL)
		exit(EXIT_FAILURE);
	sort_tab(len_a, &tab);
	med = tab[len_a / 2];
	free(tab);
	return (med);
}

/*
 * mediane_a_to_b(t_list **a, t_list **b):
 * Transfère les éléments de la pile *a* vers la pile *b* en fonction de la médiane.
 * Les éléments inférieurs ou égaux à la médiane sont déplacés vers *b* via l'opération pb().
 * Context: utilisée dans l'algorithme pour diviser la pile *a* en deux, les éléments les plus petits étant envoyés vers *b*.
 */
void	mediane_a_to_b(t_list **a, t_list **b)
{
	int	mid;
	int	med;

	med = get_mediane(*a, count_node(*a));
	mid = count_node(*a) / 2;
	while (mid > 0)
	{
		if ((*a)->nb <= med)
		{
			mid--;
			med = get_mediane(*a, count_node(*a));
			pb(a, b);
		}
		else
			ra(a);
	}
	return ;
}
