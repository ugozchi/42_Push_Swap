/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 02:00:02 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/28 13:30:38 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

/* best_rot - Détermine si la rotation de la pile a doit se faire vers le haut
ou le bas.
 * @a: Pointeur vers la pile a.
 *
 * Cette fonction parcourt la pile `a` et vérifie où se trouve la première
 * rupture de l'ordre croissant. Si cette rupture se trouve dans la première
 * moitié de la pile, elle retourne 1 (rotation vers le haut), sinon elle
 * retourne 0 (rotation vers le bas).
 * 
 * Retourne: 1 si la rotation doit se faire vers le haut, 0 sinon.*/
int	best_rot(t_list **a)
{
	t_list	*stack_a;
	int		size;
	int		half_size;
	int		i;

	stack_a = *a;
	size = ft_lstsize(stack_a);
	half_size = size / 2;
	i = 0;
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			break ;
		stack_a = stack_a->next;
		i++;
	}
	if (i <= half_size)
		return (1);
	else
		return (0);
}

/* is_sort - Vérifie si la pile a est triée dans l'ordre croissant.
 * @a: Pointeur vers la pile a.
 *
 * Cette fonction parcourt la pile `a` et vérifie si les éléments sont
 * triés dans l'ordre croissant.
 * 
 * Retourne: 1 si la pile est triée, 0 sinon.*/
int	is_sort(t_list **a)
{
	t_list	*stack_a;
	int		tmp;

	stack_a = *a;
	tmp = stack_a->content;
	while (stack_a->next)
	{
		if (tmp > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
		tmp = stack_a->content;
	}
	return (1);
}

/* end_rot - Effectue la rotation finale de la pile a pour la trier
 complètement.
 * @a: Pointeur vers la pile a.
 *
 * Cette fonction vérifie la meilleure direction de rotation (haut ou bas) en
 * utilisant `best_rot`, puis effectue les rotations nécessaires jusqu'à ce
 * que la pile soit complètement triée.*/
void	end_rot(t_list **a)
{
	t_list	*stack_a;
	int		best_r;

	stack_a = *a;
	best_r = best_rot(&stack_a);
	if (best_r == 1)
	{
		while (!is_sort(&stack_a))
			ft_ra(&stack_a, 1);
	}
	else
	{
		while (!is_sort(&stack_a))
			ft_rra(&stack_a, 1);
	}
	*a = stack_a;
}

/* can_push - Vérifie si l'élément de la pile b peut être poussé vers la
  pile a.
 * @stack_a: Pointeur vers la pile a.
 * @stack_b: Pointeur vers la pile b.
 *
 * Cette fonction vérifie si l'élément au sommet de la pile `b` peut être
 * inséré correctement dans la pile `a`, en respectant l'ordre croissant
 * de `a`.
 * 
 * Retourne: 1 si l'élément peut être poussé, 0 sinon.*/
int	can_push(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if ((*stack_b)->content < last->content
		&& (*stack_b)->content < (*stack_a)->content && is_sort(stack_a))
		return (1);
	else if ((*stack_b)->content > last->content
		&& (*stack_b)->content < (*stack_a)->content && !is_sort(stack_a))
		return (1);
	else
		return (0);
}

/* insert_sort - Effectue l'insertion des éléments de la pile b dans la pile
 a en utilisant un tri par insertion.
 * @a: Pointeur vers la pile a.
 * @b: Pointeur vers la pile b.
 * @data: Pointeur vers la structure de données contenant les informations
 * de coût.
 *
 * Cette fonction insère les éléments de la pile `b` dans la pile `a` en
 * respectant l'ordre croissant des éléments de `a`, en utilisant un algorithme
 * de tri par insertion. Elle ajuste également les rotations nécessaires pour
 * maintenir l'ordre.*/
void	insert_sort(t_list **a, t_list **b, t_data **data)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = *a;
	stack_b = *b;
	while (stack_b)
	{
		if (can_push(&stack_a, &stack_b))
			ft_pa(&stack_a, &stack_b);
		else
		{
			count_move(&stack_a, &stack_b, data);
			cost_move(&stack_a, &stack_b);
			best_move(&stack_b, data);
			do_mov(&stack_a, &stack_b, data);
		}
	}
	end_rot(&stack_a);
	*a = stack_a;
	*b = stack_b;
}
