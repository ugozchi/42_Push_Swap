/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:52:59 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/26 21:53:37 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Trie une pile de 3 éléments dans l'ordre croissant en déterminant le plus grand élément et en le déplaçant au bon endroit.
 * Si le plus grand élément est en haut, il est déplacé en bas avec ra().
 * Si le plus grand élément est au milieu, il est déplacé en bas avec rra().
 * Si les deux premiers éléments ne sont pas dans le bon ordre, un sa() est exécuté.*/
static void	three_node_sort(t_list **a)
{
	t_list	*biggest;

	biggest = find_biggest(*a);
	if (biggest == *a)
		ra(a);
	else if (biggest == (*a)->next)
		rra(a);
	if ((*a)->nb > (*a)->next->nb)
		sa(a);
}

/*Aligne l'élément le moins cher dans la pile *b* avec sa cible dans *a* en utilisant des rotations.
 * Si l'élément de *b* est dans la première moitié de la pile, rb() est utilisé, sinon rrb().
 * De même, la cible dans *a* est alignée avec ra() ou rra().
 * Context: utilisée dans le processus de réinsertion des éléments de *b* dans *a* pour garantir un tri optimal.
 */
static void	sort_a_and_b(t_list **a, t_list **b,
		t_list *cheapest)
{
	while (*b != cheapest)
	{
		if (cheapest->mediane == true)
			rb(b);
		else
			rrb(b);
	}
	while (*a != cheapest->target)
	{
		if (cheapest->target->mediane == true)
			ra(a);
		else
			rra(a);
	}
}

/*Identifie l'élément avec le coût d'insertion le plus bas dans *b*, puis aligne cet élément avec sa cible dans *a*.
 * Utilise des rotations simultanées (rr() ou rrr()) si l'élément et sa cible sont dans la même moitié de leur pile respective.
 * Insère ensuite l'élément de *b* dans *a* avec pa().
 * Context: utilisée pour réinsérer efficacement les éléments de *b* dans *a* en minimisant les mouvements.
 */
static void	replace_in_a(t_list **a, t_list **b)
{
	t_list	*cheapest;

	cheapest = *b;
	while (cheapest)
	{
		if (cheapest->cheapest == true)
			break ;
		cheapest = cheapest->next;
	}
	if (cheapest->mediane == true && cheapest->target->mediane == true)
	{
		while (cheapest != *b && cheapest->target != *a)
			rr(a, b);
		init_algo(*a, *b);
	}
	else if (!(cheapest->mediane) && !(cheapest->target->mediane))
	{
		while (cheapest != *b && cheapest->target != *a)
			rrr(a, b);
		init_algo(*a, *b);
	}
	sort_a_and_b(a, b, cheapest);
	pa(a, b);
}

/*Met en œuvre l'algorithme de tri principal.
 * 1. Divise la pile *a* en deux avec la médiane (en envoyant les éléments les plus petits dans *b*).
 * 2. Trie les 3 éléments restants dans *a* avec three_node_sort().
 * 3. Réinsère les éléments de *b* dans *a* en utilisant replace_in_a() pour minimiser les mouvements.
 * 4. Aligne enfin le plus petit élément en haut de *a* pour garantir que *a* soit entièrement triée.
 * Context: utilisé pour le tri de piles contenant plus de 3 éléments.
 */
static void	push_algo(t_list **a, t_list **b)
{
	t_list	*smallest;

	while (count_node(*a) > 3)
		mediane_a_to_b(a, b);
	three_node_sort(a);
	while (*b)
	{
		init_algo(*a, *b);
		replace_in_a(a, b);
	}
	init_algo(*a, *b);
	smallest = find_smallest(*a);
	if (smallest->mediane == true)
	{
		while (smallest != *a)
			ra(a);
	}
	else
	{
		while (smallest != *a)
			rra(a);
	}
}
/* Point d'entrée du programme.
 * 1. Valide les arguments et initialise la pile *a*.
 * 2. Vérifie si la pile *a* est déjà triée.
 * 3. Si elle ne l'est pas, lance l'algorithme push_algo() pour trier *a* et utilise sa() ou three_node_sort() si nécessaire.
 * 4. Nettoie la mémoire avant de terminer le programme.
 * Context: gère l'exécution générale du programme de tri.
 */
int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || !av[1][0])
		return (EXIT_FAILURE);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av == NULL)
			exit(EXIT_FAILURE);
	}
	checks_and_list(av + 1, ac == 2, &a);
	if (!in_order(a))
	{
		if (count_node(a) == 2)
			sa(&a);
		else if (count_node(a) == 3)
			three_node_sort(&a);
		else
			push_algo(&a, &b);
	}
	free_list(&a);
	return (0);
}
