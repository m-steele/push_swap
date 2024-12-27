/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:01:33 by ekosnick          #+#    #+#             */
/*   Updated: 2024/12/27 12:44:09 by ekosnick         ###   ########.fr       */
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
	prev->nt = NULL;
	last->nt = *sta;
	*sta = last;
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
	prev->nt = NULL;
	last->nt = *stb;
	*stb = last;
	write(1, "rrb\n", 4);
}

void	wrra(t_list **sta)
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
	prev->nt = NULL;
	last->nt = *sta;
	*sta = last;
}

void	wrrb(t_list **stb)
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
	prev->nt = NULL;
	last->nt = *stb;
	*stb = last;
}


void	rrr(t_list **sta, t_list **stb)
{
	if (sta && *sta && (*sta)->nt)
		wrra(sta);
	if (stb && *stb && (*stb)->nt)
		wrrb(stb);
	write(1, "rrr\n", 4);
}