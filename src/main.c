/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:20:40 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/28 16:23:15 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"


/* error_exit - Affiche un message d'erreur et quitte le programme.
 *
 * Cette fonction affiche le message "Error" sur la sortie d'erreur standard
 * et termine le programme avec un code d'échec.*/
void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
/* get_argv - Analyse et stocke les arguments en liste chaînée.
 * @ac: Nombre d'arguments.
 * @av: Tableau des arguments.
 * @a: Pointeur vers la pile a à remplir.
 *
 * Si un seul argument est passé, il est scindé en plusieurs sous-chaînes,
 * sinon chaque argument est ajouté à la liste chaînée `a` en appelant
 * `init_list`.En cas d'erreur d'argument, la fonction appelle `error_exit`.*/
void	get_argv(int ac, char **av, t_list **a)
{
	char	**argv;
	int		argc;

	argv = NULL;
	argc = 0;
	if (ac == 2)
	{
		argv = ft_split(av[1], ' ');
		if (!argv[0])
			return (free_tab((void **)argv), error_exit());
		while (argv[argc])
			argc++;
		init_list(a, (argc + 1), argv, 1);
		free_tab((void **)argv);
	}
	else
		init_list(a, ac, &av[1], 0);
}

/**
 * main - Point d'entrée du programme principal.
 * @ac: Nombre d'arguments de la ligne de commande.
 * @av: Tableau des arguments de la ligne de commande.
 *
 * Cette fonction initialise les piles `a` et `b` à partir des arguments.
 * Si la pile est déjà triée, elle termine le programme. Sinon, elle procède
 * au tri avec les algorithmes `quick_sort` et `insert_sort`.
 *
 * Retourne: 0 en cas de succès, ou une terminaison forcée en cas d'erreur.
 */
int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_data	*data;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		exit(EXIT_FAILURE);
	get_argv(ac, av, &a);
	if (is_sort(&a))
		return (free_list(&a), 0);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error_exit();
	quick_sort(&a, &b, &data);
	insert_sort(&a, &b, &data);
	free_list(&a);
	free_list(&b);
	free(data);
}
