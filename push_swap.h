/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:33:32 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/15 13:53:50 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				position;
	int				score;
	int				group;
	struct s_list	*target;
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;

/*********************** UTILS *********************************/
long	ft_atol(const char *nptr);
int		ft_strcmp(char *s1, const char *s2);

/************************* LST UTILS *********************************/
void	ft_lst_set_position(t_list *lst);
t_list	*ft_lstnew(int value, int position);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);

/**************************** COMMANDES ******************************/
void	push_a(t_list **a, t_list **b, int write);
void	push_b(t_list **a, t_list **b, int write);
void	swap_a(t_list **a, int write);
void	swap_b(t_list **b, int write);
void	swap_ab(t_list **a, t_list **b, int write);
void	ft_ra(t_list **a, int write);
void	ft_rb(t_list **b, int write);
void	ft_rr(t_list **a, t_list **b, int write);
void	ft_rra(t_list **a, int write);
void	ft_rrb(t_list **b, int write);
void	ft_rrr(t_list **a, t_list **b, int write);

/**************************** PARSING ******************************/
int		ft_check_args(char **argv);
int		check_max_min(char **argv);
int		check_max_min_args(char **argv);
int		check_double(char **argv, int argc);
void	ft_validation_args(int argc, char **argv);
int		ft_check_order(t_list **a);
t_list	*ft_parse_arg(char **argv);
t_list	*ft_parse_many(char **argv, int argc);

/************************* SORTING UTILS ****************************/
void	set_index(t_list **a);
void	set_3groups(t_list **lst);
void	set_6groups(t_list **lst);
void	set_target(t_list **a, t_list **b);
void	set_target_for_maxb(t_list **a, t_list **b);
void	reset_target(t_list **b);
t_list	*get_min(t_list **a);
t_list	*get_middle(t_list **lst);
t_list	*get_cheapest(t_list **lst);
int		first_half(t_list **lst, t_list *current);
void	ft_score(t_list **lst, char lst_name);

/***************************** SORTING ****************************/
int		check_group(t_list **lst, int group);
void	push_groups_atob(t_list **a, t_list **b);
void	ft_sort3(t_list **lst);
void	set_to_top(t_list **a, t_list **b);
void	final_sorting(t_list **a, t_list **b);
void	push_swap(t_list **a);

#endif