/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:50:33 by ekosnick          #+#    #+#             */
/*   Updated: 2024/12/18 11:41:27 by ekosnick         ###   ########.fr       */
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
// 	void			*content;
// 	struct	s_list	*next;
// } t_list;

/*push_swap*/
char		**freeme(char **nums, int index);
int				sorted(t_list *sta);
int				process_beans(char ***nums, char **beans, char *delim);

/*start_sort*/
void			start_sort(t_list **sta);
void			sort3(t_list **sta);
void			sort4(t_list **sta);
int             min_sta(t_list *sta);
int				not_valid(char **nums);

/*push*/
void			ptoa(t_list **sta, t_list **stb);
void			ptob(t_list **sta, t_list **stb);
void			push(t_list **src, t_list **dst);

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