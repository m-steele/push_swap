/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:04 by ekosnick          #+#    #+#             */
/*   Updated: 2024/12/10 12:20:07 by ekosnick         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void sort3(t_list **sta)
{
	int	fst;
	int	sec;
	int	thr;

	fst = ft_atoi((*sta)->ct);
	sec = ft_atoi((*sta)->nt->ct);
	thr = ft_atoi((*sta)->nt->nt->ct);
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

void	sort(t_list **sta)
{
	t_list	*stb;

	stb = NULL;
	ft_printf("sta: %d\nstb: %d\n", sta, stb);
	if (ft_lstsize(*sta) > 3)
	{
		ptob(sta, &stb);
		ptob(sta, &stb);
		ptob(sta, &stb);
		sa(sta);
		sb(&stb);
		ss(sta, &stb);
		ra(sta);
		rb(&stb);
		rr(sta, &stb);
		rra(sta);
		rrb(&stb);
		rrr(sta, &stb);
		ptoa(&stb, sta);
	}
	ft_printf("sta: %d\nstb: %d\n", sta, stb);
}
	// {
	// 	ptoa(sta, &stb);
	// 	ptoa(sta, &stb);
	// 	ptoa(sta, &stb);
	// 	sa(sta);
	// 	sb(stb);
	// 	ss(sta, &stb);
	// 	ra(sta);
	// 	rb(&stb);
	// 	rr(sta, &stb);
	// 	rra(sta);
	// 	rrb(&stb);
	// 	rrr(sta, &stb);
	// 	ptob(&stb, sta);
	// }

void start_sort(t_list **sta)
{
	if (!sta || !*sta)
		return ;
	if (ft_lstsize(*sta) == 2)
		sa(sta);
	else if (ft_lstsize(*sta) == 3)
		sort3(sta);
	else
		sort(sta);	
}
