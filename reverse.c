/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:01:33 by ekosnick          #+#    #+#             */
/*   Updated: 2024/12/17 13:08:57 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **sta)
{
	t_list	*prev;
	t_list	*last;

	if (!sta || !*sta || !(*sta)->next)
		return ;
	prev = NULL;
	last = *sta;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *sta;
	*sta = last;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stb)
{
	t_list	*prev;
	t_list	*last;

	if (!stb || !*stb || !(*stb)->next)
		return ;
	prev = NULL;
	last = *stb;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stb;
	*stb = last;
	write(1, "rrb\n", 4);
}

void	rra_no_write(t_list **sta)
{
	t_list	*prev;
	t_list	*last;

	if (!sta || !*sta || !(*sta)->next)
		return ;
	prev = NULL;
	last = *sta;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *sta;
	*sta = last;
}

void	rrb_no_write(t_list **stb)
{
	t_list	*prev;
	t_list	*last;

	if (!stb || !*stb || !(*stb)->next)
		return ;
	prev = NULL;
	last = *stb;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stb;
	*stb = last;
}

void	rrr(t_list **sta, t_list **stb)
{
	if (sta && *sta && (*sta)->next)
		rra_no_write(sta);
	if (stb && *stb && (*stb)->next)
		rrb_no_write(stb);
	write(1, "rrr\n", 4);
}