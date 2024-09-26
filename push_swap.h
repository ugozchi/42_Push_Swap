/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:41:43 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/26 20:46:37 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				nb;
	int				position;
	int				cost;
	bool			mediane;
	bool			cheapest;
	struct s_list	*target;
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;

void				checks_and_list(char **av, bool two_ac, t_list **a);
void				free_av(char **av);
void				free_list(t_list **a);
void				sa(t_list **a);
void				sb(t_list **b);
void				ss(t_list **a, t_list **b);
void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);
void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);
void				pa(t_list **a, t_list **b);
void				pb(t_list **a, t_list **b);
void				mediane_a_to_b(t_list **a, t_list **b);
void				init_algo(t_list *a, t_list *b);
int					free_init(t_list **a, char **av, bool two_ac);
int					count_node(t_list *a);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
bool				in_order(t_list *a);
t_list				*find_last(t_list *a);
t_list				*find_biggest(t_list *a);
t_list				*find_smallest(t_list *a);

#endif