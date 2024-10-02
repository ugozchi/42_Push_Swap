/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:04:59 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/28 16:28:00 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

/*sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
void	ft_sa(t_list **a, int print)
{
	int		tmp;
	t_list	*lst;

	if (!a || !*a)
		return ;
	lst = *a;
	if (!lst->next)
		return ;
	tmp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = tmp;
	if (print)
		ft_putendl_fd("sa", 1);
}

/*rr : ra and rb at the same time.*/
void	ft_rr(t_list **a, t_list **b, int print)
{
	ft_rb(a, 0);
	ft_rb(b, 0);
	if (print)
		ft_putendl_fd("rr", 1);
}

/*rrr : rra and rrb at the same time.*/
void	ft_rrr(t_list **a, t_list **b, int print)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	if (print)
		ft_putendl_fd("rrr", 1);
}

/*rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.*/
void	ft_rra(t_list **a, int print)
{
	t_list	*prev;
	t_list	*last;

	prev = NULL;
	last = *a;
	if (!a || !*a || !(*a)->next)
		return ;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *a;
	*a = last;
	if (print)
		ft_putendl_fd("rra", 1);
}

/*rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.*/
void	ft_rrb(t_list **b, int print)
{
	t_list	*prev;
	t_list	*last;

	prev = NULL;
	last = *b;
	if (!b || !*b || !(*b)->next)
		return ;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *b;
	*b = last;
	if (print)
		ft_putendl_fd("rrb", 1);
}
