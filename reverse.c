/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:01:33 by ekosnick          #+#    #+#             */
/*   Updated: 2024/12/30 11:44:12 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **sta)
{
	t_list	*prev;
	t_list	*last;

	prev = NULL;
	if (!sta || !*sta || !(*sta)->nt)
		return ;
	last = *sta;
	while (last->nt)
	{
		prev = last;
		last = last->nt;
	}
	prev->nt = NULL;
	last->nt = *sta;
	*sta = last;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stb)
{
	t_list	*prev;
	t_list	*last;

	prev = NULL;
	if (!stb || !*stb || !(*stb)->nt)
		return ;
	last = *stb;
	while (last->nt)
	{
		prev = last;
		last = last->nt;
	}
	prev->nt = NULL;
	last->nt = *stb;
	*stb = last;
	write(1, "rrb\n", 4);
}

void	rra_no_write(t_list **sta)
{
	t_list	*prev;
	t_list	*last;

	prev = NULL;
	if (!sta || !*sta || !(*sta)->nt)
		return ;
	last = *sta;
	while (last->nt)
	{
		prev = last;
		last = last->nt;
	}
	prev->nt = NULL;
	last->nt = *sta;
	*sta = last;
}

void	rrb_no_write(t_list **stb)
{
	t_list	*prev;
	t_list	*last;

	prev = NULL;
	if (!stb || !*stb || !(*stb)->nt)
		return ;
	last = *stb;
	while (last->nt)
	{
		prev = last;
		last = last->nt;
	}
	prev->nt = NULL;
	last->nt = *stb;
	*stb = last;
}

void	rrr(t_list **sta, t_list **stb)
{
	if (sta && *sta && (*sta)->nt)
		rra_no_write(sta);
	if (stb && *stb && (*stb)->nt)
		rrb_no_write(stb);
	write(1, "rrr\n", 4);
}