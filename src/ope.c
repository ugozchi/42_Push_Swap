/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:18:47 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/28 16:27:03 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

/*sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
void	ft_sb(t_list **b, int print)
{
	int		tmp;
	t_list	*lst;

	if (!b || !*b)
		return ;
	lst = *b;
	if (!lst->next)
		return ;
	tmp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = tmp;
	if (print)
		ft_putendl_fd("sb", 1);
}

/*pa (push a): Take the first element at the top of b
and put it at the top of a.
Do nothing if b is empty.*/
void	ft_pa(t_list **a, t_list **b)
{
	t_list	*first_b;

	if (!b || !*b)
		return ;
	first_b = *b;
	*b = first_b->next;
	first_b->next = *a;
	*a = first_b;
	ft_putendl_fd("pa", 1);
}

/*pb (push b): Take the first element at the top of a 
and put it at the top of b.
/Do nothing if a is empty.*/
void	ft_pb(t_list **a, t_list **b)
{
	t_list	*first_a;

	if (!a || !*a)
		return ;
	first_a = *a;
	*a = first_a->next;
	first_a->next = *b;
	*b = first_a;
	ft_putendl_fd("pb", 1);
}

/*ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.*/
void	ft_ra(t_list **a, int print)
{
	t_list	*first;
	t_list	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	last = ft_lstlast(*a);
	*a = first->next;
	last->next = first;
	first->next = NULL;
	if (print)
		ft_putendl_fd("ra", 1);
}

/*rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.*/
void	ft_rb(t_list **b, int print)
{
	t_list	*first;
	t_list	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	last = ft_lstlast(*b);
	*b = first->next;
	last->next = first;
	first->next = NULL;
	if (print)
		ft_putendl_fd("rb", 1);
}
