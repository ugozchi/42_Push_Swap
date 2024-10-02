/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakerken <sakerken@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:02:37 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/25 16:44:37 by sakerken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	struct s_list	*prev;
	struct s_list	*next;
	char			*ope;
	int				content;
}	t_list;

t_list	*ft_lstnew2(int num, char *ope);
void	ft_lstadd(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2, int i, int j);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_strdup(char *s);
void	error_exit(void);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	free_list(t_list **lst);
void	free_tab(void **tab);
void	init_list(t_list **a, int size, char **av, int flag);
long	ft_atoi(const char *nptr);
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
void	ft_putendl_fd(char *s, int fd);
void	do_move(t_list **a, t_list **b, t_list **op);
int		ft_strcmp(char *s1, char *s2);
void	check_exit(t_list **a);
void	free_all(t_list **a, t_list **b, t_list **ope);
void	check_move(t_list **a, t_list **b, t_list **ope);
void	do_move(t_list **a, t_list **b, t_list **op);
void	free_exit(char **av, long	*tab, t_list **a, int flag);

#endif