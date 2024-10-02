/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:20:09 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/28 16:31:07 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

/* * check_int - Vérifie si une chaîne représente un entier valide.
 * @av: Chaîne à vérifier.
 *
 * Cette fonction vérifie si la chaîne `av` représente un entier valide,
 * prenant en compte les signes négatifs. Si la chaîne contient un caractère non
 * valide, la fonction renvoie -1.
 * 
 * Retourne: 1 si la chaîne est un entier valide, -1 sinon.*/
int	check_int(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' && av[i + 1] != '\0')
		i++;
	if (!(av[i] >= '0' && av[i] <= '9'))
		return (-1);
	while (av[i])
	{
		if (av[i] >= '0' && av[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (1);
}

/* check_double - Vérifie s'il y a des doublons dans un tableau d'entiers.
 * @tab: Tableau d'entiers à vérifier.
 * @size: Taille du tableau.
 *
 * Cette fonction parcourt le tableau `tab` et vérifie si deux éléments
 * ont la même valeur, ce qui indiquerait la présence d'un doublon.
 * 
 * Retourne: -1 si un doublon est trouvé, 1 sinon.*/
int	check_double(long *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size - 1)
		{
			if (tab[i] == tab[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

/* free_exit - Libère la mémoire et quitte le programme en cas d'erreur.
 * @av: Tableau de chaînes à libérer.
 * @tab: Tableau d'entiers à libérer.
 * @a: Pointeur vers la pile a à libérer.
 * @flag: Indicateur pour libérer ou non le tableau `av`.
 *
 * Cette fonction libère la mémoire allouée pour `av`, `tab`, et `a`
 * en cas d'erreur, puis quitte le programme avec un message d'erreur.*/
void	free_exit(char **av, long	*tab, t_list **a, int flag)
{
	if (flag)
		free_tab((void **)av);
	return (free(tab), free_list(a), error_exit());
}

/* init_list - Initialise la liste chaînée a à partir des arguments.
 * @a: Pointeur vers la pile a.
 * @size: Taille du tableau d'arguments.
 * @av: Tableau d'arguments.
 * @flag: Indicateur pour libérer ou non le tableau `av`.
 *
 * Cette fonction vérifie les arguments pour s'assurer qu'ils sont valides (entiers
 * et sans doublons). Si tout est correct, elle les insère dans la pile `a`.
 * En cas d'erreur, elle libère les ressources et quitte le programme.*/
void	init_list(t_list **a, int size, char **av, int flag)
{
	int		i;
	long	*tab;

	i = 0;
	tab = malloc(sizeof(long) * size);
	if (!tab)
		error_exit();
	while (i < size - 1)
	{
		if (check_int(av[i]) == -1)
			return (free_exit(av, tab, a, flag));
		tab[i] = ft_atoi(av[i]);
		if (tab[i] > INT_MAX || tab[i] < INT_MIN)
			return (free_exit(av, tab, a, flag));
		ft_lstadd(a, ft_lstnew((tab[i])));
		i++;
	}
	if (check_double(tab, size) == -1)
		return (free_exit(av, tab, a, flag));
	free(tab);
}
