/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:55:50 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/28 13:23:35 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

/*free_list - Libère la mémoire utilisée par la liste chaînée.
 * @lst: Pointeur vers la liste à libérer.
 *
 * Cette fonction parcourt la liste chaînée `lst` et libère
 * chaque nœud de la liste jusqu'à ce que tous les éléments soient libérés.
 * À la fin, le pointeur vers la liste est mis à NULL.*/
void	free_list(t_list **lst)
{
	t_list	*buff;
	int		i;

	i = 0;
	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		buff = (*lst)->next;
		free(*lst);
		*lst = buff;
		i++;
	}
	*lst = NULL;
}


/*free_tab - Libère la mémoire utilisée par un tableau de pointeurs.
 * @tab: Tableau de pointeurs à libérer.
 *
 * Cette fonction parcourt un tableau de pointeurs et libère
 * chaque élément jusqu'à ce que tous les éléments soient libérés.
 * À la fin, le tableau lui-même est également libéré.*/
void	free_tab(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
