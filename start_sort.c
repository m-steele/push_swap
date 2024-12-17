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

	fst = ft_atoi((*sta)->content);
	sec = ft_atoi((*sta)->next->content);
	thr = ft_atoi((*sta)->next->next->content);
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

// CONSIDER CHANGIGN THE NAME OF CONTENT TO 'C'
// AND NEXT TO 'N' TO SAVE SPACE

void	sort(t_list **sta)
{
	t_list	*stb;
	int		tb;
	int		ta;

	stb = NULL;
	while (ft_lstsize(*sta) > 3)
		ptob(sta, &stb);
	sort3(sta);
	ta = ft_atoi(*sta->content);
	tb = ft_atoi(stb->content);
	while (stb)
	{

		/*combine these into a double check function
		char dbcheck(sta, stb) return rr, ss, rrr and utilize action:
		if (dbcheck == 'rrr')
			rrr(sta, &stb); etc...
		else*/
		if (tb == min_sta(stb) && ta == min_sta(sta))
			rrr(sta, &stb);
		if (tb == max_sta(stb) && ta == max_sta(sta))
			rr(sta, &stb);
		if (ta < ft_atoi(sta->next->content) && tb < ft_atoi(stb->next->content))
			ss(sta, &stb);

// if sta is smaller than stb, just push the top of 
		if (ft_lastsize(sta) < ft_lastsize(stb))
		{
			/*but this should consider*/
			/*the orientation of sta before the push*/
			prep_a(sta); /*helper function to prep*/
						/*for what is pushed from b
						for instance if tb is greater than
						max_sta or less than min_sta*/
			ptoa(sta, &stb);
			sort_a();
		}
		else
		{
			rot4best(stb); /*rotat_until_best*/
			ptoa(sta, &stb);
		}
		if 
		(tb < min_sta(sta) || tb > max_sta(sta))
			ptoa(sta, &stb);
		
		/*here is the tricky part, what do we do*/
		/*to sort the new number on top of the stack?*/
		
		else

		/*seems that we should do some type of rotate to */
		/*stack b before pushing to stack a*/
	}
}
/*this can be used to check if the actions are working*/
// ft_printf("sta: %d\nstb: %d\n", sta, stb);
// 		ptob(sta, &stb);
// 		ptob(sta, &stb);
// 		ptob(sta, &stb);
// 		sa(sta);
// 		sb(&stb);
// 		ss(sta, &stb);
// 		ra(sta);
// 		rb(&stb);
// 		rr(sta, &stb);
// 		rra(sta);
// 		rrb(&stb);
// 		rrr(sta, &stb);
// 		ptoa(&stb, sta);

int	min_sta(t_list *sta)
{
	int	min;
	int	x;

	min = ft_atoi(sta->content);
	while (sta)
	{
		x = ft_atoi(sta->content);
		if (x < min)
			min = x;
		sta = sta->next;
	}
	return(min);
}

int	max_sta(t_list *sta)
{
	int	max;
	int	x;

	max = ft_atoi(sta->content);
	while (sta)
	{
		x = ft_atoi(sta->content);
		if (x > max)
			max = x;
		sta = sta->next;
	}
	return(max);
}

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
