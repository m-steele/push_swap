/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:33:56 by ekosnick          #+#    #+#             */
/*   Updated: 2025/01/17 17:43:29 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_list **sta)
{
	int	fst;
	int	sec;
	int	thr;

	// if (!sta || !*sta || !(*sta)->nt || !(*sta)->nt->nt)
	// 	return ;
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

void	sa_fst_sec_hi(t_list **sta, t_list **stb)
{
		if ((*stb)->ct < (*stb)->nt->ct)
			ss(sta, stb);
	else
		sa(sta);
	ra(sta);
	sa(sta);
	rra(sta);
	sa(sta);
}

void	sa_fst_lo(int fst,int sec,int thr, t_list **sta, t_list **stb)
{
	if (fst < sec && fst < thr)
	{
		ra(sta);
		if ((*stb)->ct < (*stb)->nt->ct)
			ss(sta, stb);
		else
			sa(sta);
		rra(sta);
	}
	else if (fst < sec && fst > thr)
	{
		ra(sta);
		if ((*stb)->ct < (*stb)->nt->ct)
			ss(sta, stb);
		else
			sa(sta);
		rra(sta);
		sa(sta);
	}
}

void	sa_fst_hi(int fst,int sec,int thr, t_list **sta, t_list **stb)
{
	if (fst > sec && fst < thr)
	{
		if ((*stb)->ct < (*stb)->nt->ct)
			ss(sta, stb);
		else
			sa(sta);
	}
	else
	{
		if ((*stb)->ct < (*stb)->nt->ct)
			ss(sta, stb);
		else
			sa(sta);
		ra(sta);
		sa(sta);
		rra(sta);
	}
}

void	sort3ina(t_list **sta, t_list **stb)
{
	int	fst;
	int	sec;
	int	thr;

	if (!sta || !*sta || !(*sta)->nt || !(*sta)->nt->nt)
		return ;
	fst = ft_atoi((*sta)->ct);
	sec = ft_atoi((*sta)->nt->ct);
	thr = ft_atoi((*sta)->nt->nt->ct);


// Something is very wrong with the pointers and with regard to stb.... need to figure this
// out before we can proceed
	
	ft_printf("(stb)->ct: %d\n(stb)->nt->ct: %d\n", (*stb)->ct, (*stb)->nt->ct);
	if (fst < sec && sec < thr)
		return ;
	if (fst > sec && sec > thr)
		sa_fst_sec_hi(sta, stb);
	else if (fst < sec)
		sa_fst_lo(fst, sec, thr, sta, stb);
	else 								/*if (fst > sec)*/
		sa_fst_hi(fst, sec, thr, sta, stb);
}

// Have to re-write this so that if you have to rotate, then you will check the other stack if it needs
// to be rotated as well, becuase you will have to reverse rotate to get this values back and so 
// you will check the other stack for that as well. It might actually work to the benefit of sorting
// in blocks of 5 since you will always be pushing the two highet or lowest to the other stack which
// will likely have to be swapped half of the time... this would save about 10 - 20 moves
void sort3inb(t_list **sta, t_list **stb)
{
	int	fst;
	int	sec;
	int	thr;

	if (!stb || !(*stb) || !(*stb)->nt || !(*stb)->nt->nt)
		return;
	fst = ft_atoi((*stb)->ct);
	sec = ft_atoi((*stb)->nt->ct);
	thr = ft_atoi((*stb)->nt->nt->ct);
	ft_printf("This is fst: %d\n        sec: %d\n        thr: %d\n", fst, sec, thr);
	print_stack(*stb);
	if (fst > sec && sec > thr) /*inverted condition*/
		return ;
/*if this works, break out the individual functions as was the case with sort3ina()*/
	else if (fst < sec && sec < thr)	/*sorted condition*/
	{
		rb(stb);
		if ((*sta)->ct > (*sta)->nt->ct)
			ss(sta, stb);
		else
			sb(stb);
		ptoa(sta, stb);
		ptoa(sta, stb);
		rrb(stb);
		ptoa(sta, stb);
	}
	else if (fst < sec && fst < thr)
	{
		if ((*sta)->ct > (*sta)->nt->ct)
			ss(sta, stb);
		else
			sb(stb);
		ptoa(sta, stb);
		sb(stb);
		ptoa(sta, stb);
		ptoa(sta, stb);
	}
	else if (fst < sec && fst > thr)
	{
		if ((*sta)->ct > (*sta)->nt->ct)
			ss(sta, stb);
		else
			sb(stb);
		ptoa(sta, stb);
		ptoa(sta, stb);
		ptoa(sta, stb);
	}
	else if (fst > sec && fst < thr)
	{
		rb(stb);
		if ((*sta)->ct > (*sta)->nt->ct)
			ss(sta, stb);
		else
			sb(stb);
		rrb(stb);
		ptoa(sta, stb);
		ptoa(sta, stb);
	}
	else if (fst > sec && fst > thr)
	{
		if ((*sta)->ct > (*sta)->nt->ct)
			ss(sta, stb);
		ptoa(sta, stb);
		sb(stb);
		ptoa(sta, stb);
		ptoa(sta, stb);
	}
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
	/****************************** */
	// Use this part here to nt->nt->ct for top three of stb, sort3(stb), then ptoa.
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
