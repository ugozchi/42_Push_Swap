/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_mov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 01:16:56 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/28 13:22:14 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

/*do_rr - Effectue une rotation simultanée des piles a et b (ra et rb).

 * @a: Pointeur vers la pile a.
 * @b: Pointeur vers la pile b.
 * @data: Pointeur vers la structure de données contenant les informations de
 * mouvements.
 *
 * Cette fonction exécute des rotations simultanées sur les piles `a` et `b`
 * tant que les mouvements nécessaires dans les deux piles sont positifs.*/
void	do_rr(t_list **a, t_list **b, t_data **data)
{
	while ((*data)->mov_a > 0 && (*data)->mov_b > 0)
	{
		(*data)->mov_a--;
		(*data)->mov_b--;
		ft_rr(a, b, 1);
	}
}

/**
 * do_rrr - Effectue une rotation inverse simultanée des piles a et b
 * (rra et rrb).
 * 
 * @a: Pointeur vers la pile a.
 * @b: Pointeur vers la pile b.
 * @data: Pointeur vers la structure de données contenant les informations
 * de mouvements.
 *
 * Cette fonction exécute des rotations inverses simultanées sur les piles
 * `a` et `b` tant que les mouvements nécessaires dans les deux piles sont
 * négatifs.*/
void	do_rrr(t_list **a, t_list **b, t_data **data)
{
	while ((*data)->mov_a < 0 && (*data)->mov_b < 0)
	{
		(*data)->mov_a++;
		(*data)->mov_b++;
		ft_rrr(a, b, 1);
	}
}

/*rotate_a - Effectue les rotations nécessaires sur la pile a.
 * @a: Pointeur vers la pile a.
 * @data: Pointeur vers la structure de données contenant les informations
 * de mouvements.
 *
 * Cette fonction effectue des rotations sur la pile `a` en fonction de
 * la valeur de `mov_a`. Si `mov_a` est positif, elle effectue des rotations
 * (ra), sinon elle effectue des rotations inverses (rra).*/
void	rotate_a(t_list **a, t_data **data)
{
	while ((*data)->mov_a)
	{
		if ((*data)->mov_a > 0)
		{
			ft_ra(a, 1);
			(*data)->mov_a--;
		}
		if ((*data)->mov_a < 0)
		{
			ft_rra(a, 1);
			(*data)->mov_a++;
		}
	}
}

/*rotate_b - Effectue les rotations nécessaires sur la pile b.
 * @b: Pointeur vers la pile b.
 * @data: Pointeur vers la structure de données contenant les informations
 * de mouvements.
 *
 * Cette fonction effectue des rotations sur la pile `b` en fonction de la
 * valeur de `mov_b`. Si `mov_b` est positif, elle effectue des rotations
 * (rb), sinon elle effectue des rotations inverses (rrb).*/
void	rotate_b(t_list **b, t_data **data)
{
	while ((*data)->mov_b)
	{
		if ((*data)->mov_b > 0)
		{
			ft_rb(b, 1);
			(*data)->mov_b--;
		}
		if ((*data)->mov_b < 0)
		{
			ft_rrb(b, 1);
			(*data)->mov_b++;
		}
	}
}

/*do_mov - Effectue les mouvements calculés sur les piles a et b.
 * @a: Pointeur vers la pile a.
 * @b: Pointeur vers la pile b.
 * @data: Pointeur vers la structure de données contenant les informations
 * de mouvements.
 *
 * Cette fonction effectue les mouvements nécessaires sur les piles `a` et `b`.
 * Si les mouvements sont dans la même direction (positifs ou négatifs),
 * elle appelle les fonctions pour des rotations simultanées (do_rr ou do_rrr).
 * Elle effectue ensuite les rotations restantes sur chaque pile.*/
void	do_mov(t_list **a, t_list **b, t_data **data)
{
	if ((*data)->mov_a < 0 && (*data)->mov_b < 0)
		do_rrr(a, b, data);
	else if ((*data)->mov_a > 0 && (*data)->mov_b > 0)
		do_rr(a, b, data);
	rotate_a(a, data);
	rotate_b(b, data);
}
