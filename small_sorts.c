/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:33:56 by ekosnick          #+#    #+#             */
/*   Updated: 2025/01/16 15:37:50 by ekosnick         ###   ########.fr       */
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


void	fst_sm(int fst,int sec,int thr, t_list **sta, t_list **stb)
{
	if (fst < sec && fst < thr && sec > thr)
	{
		ra(sta);
		if ((*stb)->ct < (*stb)->nt->ct)
				ss(sta, stb);
			else
				sa(sta);
		rra(sta);
	}
	else if (fst < sec && sec > thr)
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

void	fst_sec_hi(t_list **sta, t_list **stb)
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

void	fst_hi(int fst,int sec,int thr, t_list **sta, t_list **stb)
{








}





void	sort3ina(t_list **sta, t_list *stb)
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
	if (fst < sec)
		fst_sm(fst, sec, thr, sta, stb);
	else if (fst > sec && sec > thr)
		fst_sec_hi(sta, stb);
	else 								/*if (fst > sec)*/
		fst_hi(fst, sec, thr, sta, stb);



	else if (fst > sec && fst > thr)
		ra(sta);
	else
		sa(sta);
}



// Have to re-write this so that if you have to rotate, then you will check the other stack if it needs
// to be rotated as well, becuase you will have to reverse rotate to get this values back and so 
// you will check the other stack for that as well. It might actually work to the benefit of sorting
// in blocks of 5 since you will always be pushing the two highet or lowest to the other stack which
// will likely have to be swapped half of the time... this would save about 10 - 20 moves
void sort3inb(t_list **st)
{
	int	fst;
	int	sec;
	int	thr;

	fst = ft_atoi((*st)->ct);
	sec = ft_atoi((*st)->nt->ct);
	thr = ft_atoi((*st)->nt->nt->ct);
	if (inverted(*st))
		return ;
	if (fst > sec && fst > thr && sec < thr)
	{
		rrb(st);
		sb(st);
	}
	else if (fst > sec && sec < thr)
	{
		sb(st);
		rrb(st);
	}
	else if (fst > sec && sec < thr)
		rrb(st);
	else if (fst < sec && fst < thr)
		rb(st);
	else
		sb(st);
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


// 	if (!sta || !*sta || !(*sta)->nt)
// 		return ;
// 	min = min_sta(*sta);
// 	if (ft_atoi((*sta)->ct) == min)  /*&& !sorted(*sta)*/
// 		ptob(sta, stb);
// 	else if (ft_atoi(ft_lstlast(*sta)->ct) == min)
// 	{
// 		rra(sta);
// 		if (!sorted(*sta))
// 			ptob(sta, stb);
// 	}
// 	else
// 	{
// 		while ((ft_lstsize(*sta) > 3) && ft_atoi((*sta)->ct) != min)
// 		{
// 			ra(sta);
// 			if (ft_atoi((*sta)->ct) == min && !sorted(*sta))
// 				ptob(sta, stb);
// 		}
// 	}
// 	if (ft_lstsize(*sta) == 3)
// 		sort3(sta);
// 	if (stb)
// 		ptoa(sta, stb);
// }