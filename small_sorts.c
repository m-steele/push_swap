/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:33:56 by ekosnick          #+#    #+#             */
/*   Updated: 2025/01/11 09:47:10 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort3(t_list **sta)
{
	int	fst;
	int	sec;
	int	thr;

	if (!sta || !*sta || !(*sta)->nt || !(*sta)->nt->nt)
		return ;
	fst = ft_atoi((*sta)->ct);
	sec = ft_atoi((*sta)->nt->ct);
	thr = ft_atoi((*sta)->nt->nt->ct);
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

// this works!!!!!!!!!
void sort4(t_list **sta)
{
	int		min;
	t_list	*stb;
	
	stb = NULL;
	if (!sta || !*sta || !(*sta)->nt)
		return ;
	min = min_sta(*sta);
	if (ft_atoi((*sta)->ct) == min)
		ptob(sta, &stb);
	else if (ft_atoi(ft_lstlast(*sta)->ct) == min)
	{
		rra(sta);
		if (!sorted(*sta))
			ptob(sta, &stb);
	}
	else 
	{	
		while ((ft_lstsize(*sta) > 3) && ft_atoi((*sta)->ct) != min)
		{
			ra(sta);
			if (ft_atoi((*sta)->ct) == min && !sorted(*sta))
				ptob(sta, &stb);
		}
	}
	if (ft_lstsize(*sta) == 3)
		sort3(sta);
	if (stb)
		ptoa(sta, &stb);
}

/*this function is used when stb is already established*/
void sort4ord(t_list **sta, t_list **stb)
{
	int min;
	
	if (!sta || !*sta || !(*sta)->nt)
		return ;
	min = min_sta(*sta);
	if (ft_atoi((*sta)->ct) == min)  /*&& !sorted(*sta)*/
		ptob(sta, stb);
	else if (ft_atoi(ft_lstlast(*sta)->ct) == min)
	{
		rra(sta);
		if (!sorted(*sta))
			ptob(sta, stb);
	}
	else
	{
		while ((ft_lstsize(*sta) > 3) && ft_atoi((*sta)->ct) != min)
		{
			ra(sta);
			if (ft_atoi((*sta)->ct) == min && !sorted(*sta))
				ptob(sta, stb);
		}
	}
	if (ft_lstsize(*sta) == 3)
		sort3(sta);
	if (stb)
		ptoa(sta, stb);
}

int	min_sta(t_list *sta)
{
	int	min;
	int	x;

	min = ft_atoi(sta->ct);
	while (sta)
	{
		x = ft_atoi(sta->ct);
		if (x < min)
			min = x;
		sta = sta->nt;
	}
	return(min);
}