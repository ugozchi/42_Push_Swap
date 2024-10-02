/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakerken <sakerken@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:24:05 by sakerken          #+#    #+#             */
/*   Updated: 2024/09/25 16:41:00 by sakerken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <stdlib.h>
# include <unistd.h>
# include <ulimit.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_list
{
	struct s_list	*prev;
	struct s_list	*next;
	int				index;
	int				content;
	int				cost_a;
	int				cost_b;
}	t_list;

typedef struct s_data
{
	int	med;
	int	best;
	int	cost_a;
	int	cost_b;
	int	mov_a;
	int	mov_b;
}	t_data;

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int num);
void	ft_lstadd(t_list **lst, t_list *new);
void	ft_pa(t_list **a, t_list **b);
void	ft_pb(t_list **a, t_list **b);
void	ft_sb(t_list **b, int print);
void	ft_sa(t_list **a, int print);
void	ft_ra(t_list **a, int print);
void	ft_rb(t_list **b, int print);
void	ft_rra(t_list **a, int print);
void	ft_rrb(t_list **b, int print);
void	ft_rr(t_list **a, t_list **b, int print);
void	ft_rrr(t_list **a, t_list **b, int print);
int		ft_lstsize(t_list *lst);
void	quick_sort(t_list **a, t_list **b, t_data **data);
void	insert_sort(t_list **a, t_list **b, t_data **data);
void	get_piv(t_list **stack, t_data **data, int size);
int		is_sort(t_list **a);
int		can_push(t_list **stack_a, t_list **stack_b);
void	do_mov(t_list **a, t_list **b, t_data **data);
void	error_exit(void);
void	count_move(t_list **a, t_list **b, t_data **data);
void	cost_move(t_list **a, t_list **b);
void	best_move(t_list **b, t_data **data);
int		ft_abs(int n);
int		get_total(int cost_a, int cost_b);
void	get_index(t_list **stack);
void	free_list(t_list **lst);
void	free_tab(void **tab);
void	small_sort(t_list **a);
void	*max_content(t_list *lst);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putendl_fd(char *s, int fd);
long	ft_atoi(const char *nptr);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
void	init_list(t_list **a, int size, char **av, int flag);
void	check_exit(char **av, long	*tab, t_list **a, int flag);

#endif
