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

void	print_stack(t_list *sta)
{
	ft_printf("Stack:\n");
	while (sta)
	{
		ft_printf("%s\n", sta->ct);
		sta = sta->nt;
	}
}

void sort3(t_list **sta)
{
	int	fst;
	int	sec;
	int	thr;

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

void sort4(t_list **sta)
{
	t_list	*stb = NULL;
	int		fst;
	int		sec;
	int		thr;

	fst = ft_atoi((*sta)->ct);
	sec = ft_atoi((*sta)->nt->ct);
	thr = ft_atoi((*sta)->nt->nt->ct);
	
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
		if (!sorted(*sta))
		{
			ptob(sta, &stb);
			sort3(sta);
			ptoa(sta, &stb);
		}
	}
	// ft_printf("A: %s %s %s %s\n", (*sta)->ct, (*sta)->nt->ct, (*sta)->nt->nt->ct, (*sta)->nt->nt->nt->ct);
	// ft_printf("A: %s %s %s %s\n", (stb)->ct, (stb)->nt->ct, (stb)->nt->nt->ct, (stb)->nt->nt->nt->ct);
}
/*this function is used when stb is already established*/
void sort4ord(t_list **sta, t_list **stb)
{
	int		fst;
	int		sec;
	int		thr;

	fst = ft_atoi((*sta)->ct);
	sec = ft_atoi((*sta)->nt->ct);
	thr = ft_atoi((*sta)->nt->nt->ct);

	if (fst == min_sta(*sta))
	{
		ptob(sta, stb);
		sort3(sta);
		ptoa(sta, stb);
	}
	else if (sec == min_sta(*sta))
	{
		ra(sta);
		ptob(sta, stb);
		sort3(sta);
		ptoa(sta, stb);
	}
	else if (thr == min_sta(*sta))
	{
		rra(sta);
		rra(sta);
		ptob(sta, stb);
		sort3(sta);
		ptoa(sta, stb);
	}
	else
	{
		rra(sta);
		if (!sorted(*sta))
		{
			ptob(sta, stb);
			sort3(sta);
			ptoa(sta, stb);
		}
	}
	// print_stack(*sta);
	// print_stack(*stb);
	// ft_printf("A: %s %s %s %s %s %s %s %s\n", (*sta)->ct, (*sta)->nt->ct, (*sta)->nt->nt->ct, (*sta)->nt->nt->nt->ct, (*sta)->nt->nt->nt->nt->ct, (*sta)->nt->nt->nt->nt->nt->ct, (*sta)->nt->nt->nt->nt->nt->nt->ct, (*sta)->nt->nt->nt->nt->nt->nt->nt->ct);
	// ft_printf("B: %s %s %s %s\n", (*stb)->ct, (*stb)->nt->ct, (*stb)->nt->nt->ct, (*stb)->nt->nt->nt->ct);
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

int	evaluate(int min1, int min2, int i)
{
	int	imin1;
	int	imin2;

	imin1 = ((i/2) - min1);
	imin2 = ((i/2) - min2);

	if (ft_abs(imin1) > ft_abs(imin2) && imin1 > 1)
		return (1);
	else if (ft_abs(imin1) > ft_abs(imin2) && imin1 < 1)
		return (2);
	else if (ft_abs(imin1) < ft_abs(imin2) && imin1 > 1)
		return (3);
	else/*this will also include if imin1 == imin2 at middle: rrb*/
		return (4);
}

void	pusher(int option, int min1, int min2, t_list **sta, t_list **stb)
{
	while (*stb)
	{
		if (option == 1)
		{
		while (ft_atoi((*stb)->ct) != min1 && ft_atoi((*stb)->ct) != min2)
			ra(stb);
		ptoa(sta, stb);
		}
		else if (option == 2)
		{
		while (ft_atoi((*stb)->ct) != min1 && ft_atoi((*stb)->ct) != min2)
				rra(stb);
			ptoa(sta, stb);
		}
		else if (option == 3)
		{
		while (ft_atoi((*stb)->ct) != min1 && ft_atoi((*stb)->ct) != min2)
				rb(stb);
			ptoa(sta, stb);
		}
		else
		{
		while (ft_atoi((*stb)->ct) != min1 && ft_atoi((*stb)->ct) != min2)
				rrb(stb);
			ptoa(sta, stb);
		}
	/*AFTER THE FIRST PUSH RE-EVALUATE IF THE NEXT ITEM IS WORTH THE PUSH*/
	// if ()
	}
}
// find out if your next number is closer to the top or bottom
void	find_next(t_list **sta, t_list **stb)
{
	int i; /*total count of stack b*/
	int j; 
	int min1; 
	int min2;
	int	option; /*option is 1, we will rotate b, else we will rrb*/

	while (*stb && ft_lstsize(*stb) > 3)
	{	i = -1; /*The idea is that we want to start at the top of the stack*/
		while (*stb && (*stb)->nt)
			i++;
		j = 0;
		while (*stb && ft_atoi((*stb)->nt->ct) != min_sta(*stb))
			j++;
		min1 = j;
		j = 0;
		while (*stb && ft_atoi((*stb)->nt->ct) != (min_sta(*stb) + 1))
 			j++;
		min2 = j;
		option = evaluate(min1, min2, i);
		pusher(option, min1, min2, sta, stb);
	}
}

void	last_push(t_list **sta, t_list **stb)
{
	while (*stb)
	{
		if ((*stb)->nt)
			rrb(stb);
		ptoa(sta, stb);
		if (!*stb)
			break ;
	}
}

// sort() will find the lowsest 4 values, pushing the rest to b
// then sort4, we could potentially implement this to sort 5 items,
// ensuring that the lowest 2 are pushed to stack b in the correct order
void	sort(t_list **sta)
{
	t_list	*stb;

	stb = NULL;
	while (ft_lstsize(*sta) > 4)
	{
		if (ft_atoi((*sta)->ct) > (min_sta(*sta) + 3))
			ptob(sta, &stb);
		else
			ra(sta);
	}
	// print_stack(*sta);/********* */
	// print_stack(stb);/************ */
	sort4ord(sta, &stb);
	while (ft_lstsize(stb) > 4)
		find_next(sta, &stb);
	sort4(&stb);
	last_push(sta, &stb);
}

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
