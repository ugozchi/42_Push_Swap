/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:16:07 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/26 21:18:28 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * free_av(char **av):
 * Libère la mémoire allouée pour le tableau de chaînes de caractères 'av'. 
 * Elle est utilisée pour éviter les fuites de mémoire après l'utilisation des arguments.
 * Context: utile lorsque 'av' a été alloué dynamiquement dans le programme, notamment si 
 * les arguments ont été traités via 'ft_split'.
 */
void	free_av(char **av)
{
	int	i;

	i = -1;
	while (av[i])
		free(av[i++]);
	free(av - 1);
	return ;
}
 /*
  * free_list(t_list **a):
  * Libère toute la mémoire allouée pour la liste chaînée utilisée pour représenter la pile *a*. 
  * Cette fonction s'assure que tous les nœuds sont correctement désalloués.
  * Context: nécessaire pour libérer la mémoire avant de quitter le programme ou après l'usage d'une pile.
  */
void	free_list(t_list **a)
{
	t_list	*current;
	t_list	*temp;

	if (a == NULL)
		return ;
	current = *a;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*a = NULL;
	return ;
}

/*
  * free_init(t_list **a, char **av, bool two_ac):
  * Cette fonction libère les ressources (la liste *a* et potentiellement le tableau d'arguments 'av') 
  * en cas d'erreur d'initialisation, puis affiche un message d'erreur et termine le programme.
  * Context: appelée dans des situations d'échec d'initialisation des données pour éviter des fuites 
  * de mémoire et signaler une erreur.
  */
int	free_init(t_list **a, char **av, bool two_ac)
{
	free_list(a);
	if (two_ac)
		free_av(av);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
