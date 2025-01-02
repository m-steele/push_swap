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
	while (sta)
	{
		ft_printf("%s\n", sta->ct);
		sta = sta->nt;
	}
}

int	evaluate(t_list *stb, int min1, int min2, int i)
{
	int	rmin1; /*rank 1 min*/
	int	rmin2; /*rank 2 min*/
	int	imin1;
	int	imin2;

	ft_printf("I: %i/n", i); /*currently shows this function is called*/
	while ((ft_lstsize(stb) != min1) && ft_atoi((stb)->ct) != min1)
		i++;
	rmin1 = i;
	i = 0;
	while ((ft_lstsize(stb) != min2) && ft_atoi((stb)->ct) != min2)
		i++;
	rmin2 = i;
	imin1 = ((i/2) - rmin1);
	imin2 = ((i/2) - rmin2);
	ft_printf("rmin1: %i, rmin2: %i\n", rmin1, rmin2);
	// ft_printf("I: %i, imin1: %i, imin2: %i\n", i, imin1, imin2);
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
// mUST USE THE EVALUATOR FUNCTION, BUT DOES NOT LOOK RIGHT
void	find_next(int *sm_bs, t_list **sta, t_list **stb)
{
	int i; /*total count of stack b*/
	int min1 = sm_bs[0];
	int min2 = sm_bs[1];
	int	option; /*option is 1, we will rotate b, else we will rrb*/

	min1 = sm_bs[0];
	min2 = sm_bs[1];
	// ft_printf("min1: %d, min2: %d\n", sm_bs[0], sm_bs[1]); /*SHOWS THAT SMALLEST 2 IN B ARE ALLOCATED*/

/********************************************************* */
/*THERE HAS TO BE A PROBOLEM AT THIS POINT, START DEBUGGING HERE*/
	while (*stb && ft_lstsize(*stb) > 3)
	{	
		i = -1;
		while (*stb && (*stb)->nt)
			i++;
		option = evaluate(*stb, min1, min2, i);
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
		ra(sta);
		if (!*stb)
			break ;
	}
}
// sort() will find the lowsest 4 values, pushing the rest to b
// then sort4, we could potentially implement this to sort 5 items
void	sort(t_list **sta)
{
	t_list	*stb = NULL;
	int		*sm_as;
	int		*sm_bs;

	sm_as = find_n_smallest(*sta, 4);
	// ft_printf("sm_as: %d, %d, %d, %d\n", sm_as[0], sm_as[1], sm_as[2], sm_as[3]);
	if (!sm_as)
		return;
	while (ft_lstsize(*sta) > 4)
	{
		if (!is_in_smallest(ft_atoi((*sta)->ct), sm_as, 4))
			ptob(sta, &stb);
		else
			ra(sta);
	}
	free(sm_as);
	sm_bs = find_n_smallest(stb, 2);
	// ft_printf("sm_bs: %d, %d\n", sm_as[0], sm_as[1]);
	// ft_printf("STA_after_ptob_______\n");
	// print_stack(*sta);/********* */
	// ft_printf("STB_after_ptob_______\n");
	// print_stack(stb);/********* */
	sort4ord(sta, &stb);
	find_next(sm_bs, sta, &stb);
	free(sm_bs);
	last_push(sta, &stb); /*may need last in reverse order then ptoa and ra*/
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
	else if (ft_lstsize(*sta) > 4)
		sort(sta);
}
