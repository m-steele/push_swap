/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:58:23 by ekosnick          #+#    #+#             */
/*   Updated: 2024/12/27 12:48:11 by ekosnick         ###   ########.fr       */
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
	write(1, "rb\n", 3);
}

void	wra(t_list **sta)
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

void	wrb(t_list **stb)
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

void	rr(t_list **sta, t_list **stb)
{
	if (sta && *sta && (*sta)->nt)
		wra(sta);
	if (stb && *stb &&(*stb)->nt)
		wrb(stb);
	write(1, "rr\n", 3);
}