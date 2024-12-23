/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:58:23 by ekosnick          #+#    #+#             */
/*   Updated: 2024/12/20 12:42:24 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **sta)
{
	t_list	*first;
	t_list	*last;

	if (!sta || !*sta || !(*sta)->nt)
		return ;
	first = *sta;
	*sta = first->nt;
	first->nt = NULL;
	last = *sta;
	while (last->nt)
		last = last->nt;
	last->nt = first;
	write(1, "ra\n", 3);
}

void	rb(t_list **stb)
{
	t_list	*first;
	t_list	*last;

	if (!stb || !*stb || !(*stb)->nt)
		return ;
	first = *stb;
	*stb = first->nt;
	first->nt = NULL;
	last = *stb;
	while (last->nt)
		last = last->nt;
	last->nt = first;
	write(1, "ra\n", 3);
}

void	rb_no_write(t_list **stb)
{
	t_list	*first;
	t_list	*last;

	if (!stb || !*stb || !(*stb)->nt)
		return ;
	first = *stb;
	*stb = first->nt;
	first->nt = NULL;
	last = *stb;
	while (last->nt)
		last = last->nt;
	last->nt = first;
}

void	ra_no_write(t_list **sta)
{
	t_list	*first;
	t_list	*last;

	if (!sta || !*sta || !(*sta)->nt)
		return ;
	first = *sta;
	*sta = first->nt;
	first->nt = NULL;
	last = *sta;
	while (last->nt)
		last = last->nt;
	last->nt = first;
}

void	rr(t_list **sta, t_list **stb)
{
	if (sta && *sta && (*sta)->nt)
		ra_no_write(sta);
	if (stb && *stb &&(*stb)->nt)
		rb_no_write(stb);
	write(1, "rr\n", 3);
}