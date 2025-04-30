/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:04 by ekosnick          #+#    #+#             */
/*   Updated: 2025/04/30 12:52:36 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fin_sort(t_list **sta) /*, t_list **stb*/
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

void	first_ptob(t_list **sta, t_list **stb)
{
	int		*sm_as;
	int		*bg_as;
	int		n;
	int		pushed;
	int		i;

	n = ft_lstsize(*sta);
	sm_as = find_n_smallest(*sta, n / 2);
	pushed = 0;
	i = 0;
	while (n > 5 && i < n && pushed < n / 2)
	{
		if (is_in_smallest(ft_atoi((*sta)->ct), sm_as, n / 2))
		{
			ptob(sta, stb);
			pushed++;
		}
		else
			ra(sta);
		i++;
	}
	free(sm_as);
	bg_as = f_n_b(*sta, 1);
	while (n - pushed > 3)
	{
		if (inb(ft_atoi((*sta)->ct), bg_as, 1))
			ra(sta);
		else
		{
			ptob(sta, stb);
			pushed++;
		}
	}
	free(bg_as);
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
