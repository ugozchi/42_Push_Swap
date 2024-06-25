/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:50:49 by uzanchi           #+#    #+#             */
/*   Updated: 2024/06/03 13:13:11 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sa (swap a) : Intervertit les 2 premiers élements au sommet de la pile a. Ne fait rien s'il n'y en a qu'un ou aucun*/

int	sa_command(int *array_a, int *array_b)
{
	if (!array_a[0] || !array_b[1])
		return (0);
}

/*sb (swap b) : Intervertit les 2 premiers élements au sommet de la pile b. Ne fait rien s'il n'y en a qu'un ou aucun*/

int	sb_command(int *array_a, int *array_b)
{
	if (!array_a[0] || !array[1])
		return (0);
}

/*ss : sa et sb en même temps*/

int	ss_command(int *array_a, int *array_b)
{
	sa_command(array_a, array_b);
	sb_command(array_a, array_b);
}

/*pa (push a) : Prend le premier élement au sommet de b et le met sur a. Ne fait rien si b est vide*/

int	pa_command(int *array_a, int *array_b)
{
	if (!array_b)
		return (0);
}

/*pb (push b) : Prend le premier élement au sommet de a et le met sur b. Ne fait rien si a est vide*/

int	pb_command(int *array_a, int *array_b)
{
	if (!array_a)
		return (0);
}

/*ra (rotate a) : Décale d'une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier*/

int	ra_command(int *array_a, int *array_b)
{
	
}

/*rb (rotate b) : Décale d'une position vers le haut tous les élements de la pile b. Le premier éléments devient le dernier*/

int	rb_command(int *array_a, int *array_b)
{

}

/*rr : ra et rb en même temps*/

int	rr_command(int *array_a, int *array_b)
{
	ra_command(array_a, array_b);
	rb_command(array_a, array_b);
}

/*rra (reverser rotate a) : Décale d'une position vers le bas tous les élements de la pile a. Le dernier élement devient le premier*/

int	rra_command
