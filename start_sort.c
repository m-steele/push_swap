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

void sort4(t_list **sta)
{
	t_list	*stb = NULL;
	int		fst;
	int		sec;
	int		thr;
	int		frt;

	fst = ft_atoi((*sta)->content);
	sec = ft_atoi((*sta)->next->content);
	thr = ft_atoi((*sta)->next->next->content);
	frt = ft_atoi((*sta)->next->next->next->content);

// we will find the lowest value, push to b, sort3
// then push back to a
	if (fst == min_sta(*sta))
	{
		ptob(sta, &stb);
		sort3(sta);
		ptoa(sta, &stb);
	}
	else if (sec == min_sta(*sta))
	{
		ra(sta);
		ptob(sta, &stb);
		sort3(sta);
		ptoa(sta, &stb);
	}
	else if (thr == min_sta(*sta))
	{
		rra(sta);
		rra(sta);
		ptob(sta, &stb);
		sort3(sta);
		ptoa(sta, &stb);
	}
	else
	{
		rra(sta);
		ptob(sta, &stb);
		sort3(sta);
		ptoa(sta, &stb);
	}
	ft_printf("A: %s %s %s %s\n", (*sta)->content, (*sta)->next->content, (*sta)->next->next->content, (*sta)->next->next->next->content);
}

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

// sort() will find the lowsest 4 values, pushing the rest to b
// then sort4, we could potentially implement this to sort 5 items,
// ensuring that the lowest 2 are pushed to stack b in the correct order
// That asside, we will need to find a sorting method to get items from 
// stack b back to stack a. CHECK THE OLD NOTES BELOW.
void	sort(t_list **sta)
{
	t_list	*stb;

	stb = NULL;
	while (ft_lstsize(*sta) > 4)
	{
		if (ft_atoi((*sta)->content) > (min_sta(*sta) + 3))
			ptob(sta, &stb);
		else
			ra(sta);
	}
	sort4(sta);
	// ft_printf("Min of A: %d\n", min_sta(*sta));
	while (stb)
		ptoa(sta, &stb);
	ft_printf("A: %s %s %s %s %s %s %s\n", (*sta)->content, (*sta)->next->content, (*sta)->next->next->content, (*sta)->next->next->next->content, (*sta)->next->next->next->next->content, (*sta)->next->next->next->next->next->content, (*sta)->next->next->next->next->next->next->content);
}

/*OLD NOTES OF IDEAS*/
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

// CONSIDER CHANGIGN THE NAME OF CONTENT TO 'C'
// AND NEXT TO 'N' TO SAVE SPACE

void start_sort(t_list **sta)
{
	if (!sta || !*sta)
		return ;
	if (ft_lstsize(*sta) == 2)
		sa(sta);
	else if (ft_lstsize(*sta) == 3)
		sort3(sta);
	else if (ft_lstsize(*sta) == 4)
		sort4(sta);
	else
		sort(sta);
}
