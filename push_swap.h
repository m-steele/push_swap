/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:50:33 by ekosnick          #+#    #+#             */
/*   Updated: 2025/04/30 13:08:18 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

// NOTE THAT WHEN WE ARE AT HOME WE NEED THIS DIRECTORY
// include "/home/peatjohnston/_42/github/libft/libft.h"
// # include "../libft/libft.h"

// typedef struct s_list
// {
// 	void			*ct;
// 	int				pos;
// 	int				index;
// 	int				target;
// 	int				costfora;
// 	int				costforb;
// 	struct	s_list	*nt;
// } t_list;

/*push_swap*/
int			process_beans(char ***nums, char **beans, char *delim);
t_list		*fill_stack(char **nums, int len);

/*utilities*/
int			sorted(t_list *sta);
int			inverted(t_list *st);
void		id_target(t_list **sta, t_list **stb);

/*start_sort*/
void		start_sort(t_list **sta, t_list **stb);
int			not_valid(char **nums);
void		sort3(t_list **sta);

/*find_n_smallest*/
int			*find_n_smallest(t_list *sta, int n);
int			is_in_smallest(int value, int *smallest, int n);

/*find_n_biggest*/
int			*f_n_b(t_list *sta, int n);
int			inb(int value, int *biggest, int n);

/*push*/
void		ptoa(t_list **sta, t_list **stb);
void		ptob(t_list **sta, t_list **stb);
void		push(t_list **src, t_list **dst);

/*swap*/
void		sa(t_list **sta);
void		sb(t_list **stb);
void		ss(t_list **sta, t_list **stb);

// /*rotate*/
void		ra(t_list **sta);
void		rb(t_list **stb);
void		ra_no_write(t_list **sta);
void		rb_no_write(t_list **stb);
void		rr(t_list **sta, t_list **stb);

// /*reverse*/
void		rra(t_list **sta);
void		rrb(t_list **stb);
void		rra_no_write(t_list **sta);
void		rrb_no_write(t_list **stb);
void		rrr(t_list **sta, t_list **stb);

// /*moveit*/
void		pay_cheapest(t_list **sta, t_list **stb);
void		negotiate_price(t_list **sta, t_list **stb);

#endif