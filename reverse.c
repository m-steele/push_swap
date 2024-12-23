/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:01:33 by ekosnick          #+#    #+#             */
/*   Updated: 2024/12/21 12:29:50 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **sta)
{
	t_list	*prev;
	t_list	*last;

	if (!sta || !*sta || !(*sta)->nt)
		return ;
	prev = NULL;
	last = *sta;
	while (last->nt)
	{
		prev = last;
		last = last->nt;
	}
	*sta = last;
	last->nt = *sta;
	prev->nt = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stb)
{
	t_list	*prev;
	t_list	*last;

	if (!stb || !*stb || !(*stb)->nt)
		return ;
	prev = NULL;
	last = *stb;
	while (last->nt)
	{
		prev = last;
		last = last->nt;
	}
	*stb = last;
	last->nt = *stb;
	prev->nt = NULL;
	write(1, "rrb\n", 4);
}

void	rra_no_write(t_list **sta)
{
	t_list	*prev;
	t_list	*last;

	if (!sta || !*sta || !(*sta)->nt)
		return ;
	prev = NULL;
	last = *sta;
	while (last->nt)
	{
		prev = last;
		last = last->nt;
	}
	*sta = last;
	last->nt = *sta;
	prev->nt = NULL;
}

void	rrb_no_write(t_list **stb)
{
	t_list	*prev;
	t_list	*last;

	if (!stb || !*stb || !(*stb)->nt)
		return ;
	prev = NULL;
	last = *stb;
	while (last->nt)
	{
		prev = last;
		last = last->nt;
	}
	*stb = last;
	last->nt = *stb;
	prev->nt = NULL;
}

void	rrr(t_list **sta, t_list **stb)
{
	if (sta && *sta && (*sta)->nt)
		rra_no_write(sta);
	if (stb && *stb && (*stb)->nt)
		rrb_no_write(stb);
	write(1, "rrr\n", 4);
}