/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:07:32 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/28 13:14:45 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"


/*get_index - Assigne un index croissant à chaque élément de la pile.
 * @stack: Pointeur vers la pile à indexer.
 *
 * Cette fonction parcourt la liste chaînée `stack` et assigne
 * un index croissant (commençant à 0) à chaque élément.*/
void	get_index(t_list **stack)
{
	t_list	*current;
	int		i;

	current = *stack;
	i = 0;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
}

/*ft_abs - Retourne la valeur absolue d'un entier.
 * @n: Entier dont on souhaite obtenir la valeur absolue.
 *
 * Cette fonction retourne la valeur absolue du nombre `n`.
 * 
 * Retourne: La valeur absolue de l'entier `n`.*/
int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

/*get_total - Calcule le coût total de déplacement d'un élément entre deux
 piles.
 * @cost_a: Coût associé à la pile a.
 * @cost_b: Coût associé à la pile b.
 *
 * Cette fonction calcule le coût total pour déplacer un élément
 * en tenant compte des coûts dans les piles `a` et `b`. Si les deux coûts
 * sont positifs ou négatifs, elle renvoie le coût le plus élevé. 
 * Sinon, elle additionne leurs valeurs absolues.
 *	
 * Retourne: Le coût total calculé.*/
int	get_total(int cost_a, int cost_b)
{
	int	total;

	total = 0;
	if (cost_a > 0 && cost_b > 0)
	{
		if (cost_a > cost_b)
			total = cost_a;
		else
			total = cost_b;
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		if (ft_abs(cost_a) > ft_abs(cost_b))
			total = ft_abs(cost_a);
		else
			total = ft_abs(cost_b);
	}
	else
		total = ft_abs(cost_a) + ft_abs(cost_b);
	return (total);
}
