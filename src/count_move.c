/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:08:33 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/28 13:17:57 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

/*count_a - Trouve l'index de la position cible pour un élément de la pile b 
dans la pile a.
 * @a: Pointeur vers la pile a.
 * @node_b: Élément de la pile b pour lequel on cherche la position cible.
 *
 * Cette fonction parcourt la pile `a` et trouve l'endroit où l'élément
 * `node_b` de la pile b devrait être inséré. La position cible est déterminée
 * en fonction du contenu des éléments (ordre croissant).
 *
 * Retourne: L'index de la position cible dans la pile a.*/
int	count_a(t_list **a, t_list *node_b)
{
	t_list	*stack_a;
	int		can_push;
	int		target_index;

	stack_a = *a;
	can_push = INT_MAX;
	target_index = -1;
	while (stack_a)
	{
		if (can_push > stack_a->content && stack_a->content > node_b->content)
		{
			can_push = stack_a->content;
			target_index = stack_a->index;
		}
		stack_a = stack_a->next;
	}
	return (target_index);
}

/*count_move - Calcule le coût de déplacement pour chaque élément de la 
	pile b vers la pile a.
	
 * @a: Pointeur vers la pile a.
 * @b: Pointeur vers la pile b.
 * @data: Pointeur vers la structure de données contenant les informations 
 * de coûts.
 *
 * Cette fonction calcule les mouvements nécessaires pour chaque élément de
 * la pile `b` afin de l'insérer dans la pile `a`, en tenant compte du coût
 * pour la pile `a` et de l'index de l'élément dans `b`.*/
void	count_move(t_list **a, t_list **b, t_data **data)
{
	t_list	*stack_b;
	t_list	*stack_a;
	int		co_a;

	stack_b = *b;
	stack_a = *a;
	get_index(&stack_a);
	get_index(&stack_b);
	(*data)->mov_a = 0;
	(*data)->mov_b = 0;
	(*data)->best = 1000;
	while (stack_b)
	{
		co_a = count_a(a, stack_b);
		stack_b->cost_a = co_a;
		stack_b->cost_b = stack_b->index;
		stack_b = stack_b->next;
	}
}

/*cost_move - Calcule les coûts de rotation nécessaires pour chaque
élément de la pile b.

 * @a: Pointeur vers la pile a.
 * @b: Pointeur vers la pile b.
 *
 * Cette fonction ajuste les coûts de rotation pour chaque élément de la
 * pile `b` en fonction de sa position dans la pile. Si l'élément est dans
 * la première moitié de la pile, le coût est positif, sinon il est négatif
 * (pour une rotation inverse).*/
void	cost_move(t_list **a, t_list **b)
{
	int		size_a;
	int		size_b;
	t_list	*stack_b;

	stack_b = *b;
	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	while (stack_b)
	{
		if (stack_b->cost_b > size_b / 2)
			stack_b->cost_b = (size_b - stack_b->cost_b) * -1;
		else
			stack_b->cost_b = stack_b->cost_b;
		if (stack_b->cost_a > size_a / 2)
			stack_b->cost_a = (size_a - stack_b->cost_a) * -1;
		else
			stack_b->cost_a = stack_b->cost_a;
		stack_b = stack_b->next;
	}
}

/*best_move - Trouve le meilleur mouvement à effectuer en fonction des coûts.
 * @b: Pointeur vers la pile b.
 * @data: Pointeur vers la structure contenant les données de coût.
 *
 * Cette fonction parcourt la pile `b` et détermine le mouvement le plus
 * optimal (celui qui minimise le coût total) pour insérer un élément
 * dans la pile `a`.*/
void	best_move(t_list **b, t_data **data)
{
	t_list	*stack_b;
	int		total_cost;

	total_cost = 0;
	stack_b = *b;
	while (stack_b)
	{
		total_cost = get_total(stack_b->cost_a, stack_b->cost_b);
		if (total_cost != 0 && total_cost < (*data)->best)
		{
			(*data)->best = total_cost;
			(*data)->mov_a = stack_b->cost_a;
			(*data)->mov_b = stack_b->cost_b;
		}
		stack_b = stack_b->next;
	}
}
