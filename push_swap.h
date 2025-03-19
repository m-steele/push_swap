/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:50:33 by ekosnick          #+#    #+#             */
/*   Updated: 2025/03/19 12:16:18 by ekosnick         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

typedef struct s_list
{
	int				ct;
	int				pos;
	int				index;
	int				target;
	int				costfora;
	int				costforb;
	struct	s_list	*nt;
} t_list;

/*push_swap*/
// char		**freeme(char **nums, int index);
int			sorted(t_list *sta);
int			inverted(t_list *st);
int			process_beans(char ***nums, char **beans, char *delim);
void		print_stack(t_list *sta);
t_list		fill_stack(nums, len);

/*small_sorts*/
void		sort3(t_list **sta);
void		sort4(t_list **sta);
// void		sort4ord(t_list **sta, t_list **stb);
int			min_sta(t_list *sta);

void		sort3inb(t_list **sta, t_list **stb);
void		sort3ina(t_list **sta, t_list **stb);
void		sa_fst_sec_hi(t_list **sta, t_list **stb);
void		sa_fst_lo(int fst,int sec,int thr, t_list **sta, t_list **stb);
void		sa_fst_hi(int fst,int sec,int thr, t_list **sta, t_list **stb);

/*start_sort*/
void		start_sort(t_list **sta);
int			not_valid(char **nums);
int			all_smalls_ptob(t_list *sta, int *smallest, int n);
int			all_bigs_ptoa(t_list *st, int *biggest, int n);

/*find_n_smallest*/
int			*find_n_smallest(t_list *sta, int n);
int			is_in_smallest(int value, int *smallest, int n);

/*find_n_biggest*/
int			*find_n_biggest(t_list *sta, int n);
int			is_in_biggest(int value, int *biggest, int n);

/*push_ops*/
int			find_in_pos(t_list	*sta, int target);
void		push_ops(t_list **sta, t_list **stb);
void		push_into_pos(t_list **sta, int pos);
int			mk_chunk(int size);
void		sort_10_ina(t_list **sta, t_list *stb);
void		sort_10_inb(t_list **sta, t_list *stb);
void		sort_5_ina(t_list **sta, t_list *stb);
void		sort_5_inb(t_list **sta, t_list *stb);

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
void        ra_no_write(t_list **sta);
void        rb_no_write(t_list **stb);
void		rr(t_list **sta, t_list **stb);

// /*reverse*/
void		rra(t_list **sta);
void		rrb(t_list **stb);
void        rra_no_write(t_list **sta);
void        rrb_no_write(t_list **stb);
void		rrr(t_list **sta, t_list **stb);

#endif