/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:04 by ekosnick          #+#    #+#             */
/*   Updated: 2025/05/01 07:46:35 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fin_sort(t_list **sta)
{
	if (!sorted(*sta))
	{
		while (ft_atoi((*sta)->ct) > ft_atoi(ft_lstlast(*sta)->ct))
			rra(sta);
	}
}

void	sort3(t_list **sta)
{
	int	fst;
	int	sec;
	int	thr;

	fst = (*sta)->index;
	sec = (*sta)->nt->index;
	thr = (*sta)->nt->nt->index;
	if (sorted(*sta))
		return ;
	if (fst < sec && fst < thr && sec > thr)
	{
		rra(sta);
		sa(sta);
	}
	else if (fst > sec && sec > thr)
	{
		sa(sta);
		rra(sta);
	}
	else if (fst < sec && sec > thr)
		rra(sta);
	else if (fst > sec && fst > thr)
		ra(sta);
	else
		sa(sta);
}

void	calculate_index(t_list *sta, int lstsize)
{
	t_list	*tmp;
	t_list	*highest;
	int		current;

	while (--lstsize > 0)
	{
		tmp = sta;
		highest = NULL;
		current = INT_MIN;
		while (tmp)
		{
			if (atoi(tmp->ct) == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (atoi(tmp->ct) > current && tmp->index == 0)
			{
				current = atoi(tmp->ct);
				highest = tmp;
				tmp = sta;
			}
			else
				tmp = tmp->nt;
		}
		if (highest != NULL)
			highest->index = lstsize;
	}
}

void	start_sort(t_list **sta, t_list **stb)
{
	int	lstsize;

	lstsize = ft_lstsize(*sta);
	if (!sta || !*sta)
		return ;
	calculate_index(*sta, lstsize);
	if (lstsize == 2)
		sa(sta);
	else if (lstsize == 3)
		sort3(sta);
	else
	{
		first_ptob(sta, stb);
		sort3(sta);
	}
	while (*stb)
	{
		id_target(sta, stb);
		negotiate_price(sta, stb);
		pay_cheapest(sta, stb);
	}
	fin_sort(sta);
}
