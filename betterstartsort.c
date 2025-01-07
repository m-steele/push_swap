/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   betterstartsort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:04 by ekosnick          #+#    #+#             */
/*   Updated: 2025/01/06 12:45:21 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// IDeas that may or may not be useful

// FIND SMALLEST COULD BE AS MANY n AS YOU WANT
#include "push_swap.h"

int	*find_n_smallest(t_list *sta, int n)
{
	int		*smallest;
	int 	val;
	int		i;
	int		j;

	smallest = malloc(sizeof(int) * n);
	if (!smallest)
		return (NULL);
	i = 0;
	while (i < n)
		smallest[i++] = INT_MAX;
	while (sta)
	{
		val = ft_atoi(sta->ct);
		i = 0;
		while (i < n)
		{
			if (val < smallest[i])
			{
				j = n - 1;
				while (j > i)
				{
					smallest[j] = smallest[j - 1];
					j--;
				}
				smallest[i] = val;
				break;
			}
			i++;
		}
		sta = sta->nt;
	}
	return (smallest);
}

// Helper function to check if a value is among the smallest
int	is_in_smallest(int value, int *smallest, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (value == smallest[i])
			return (1);
		i++;
	}
	return (0);
}


void	print_stack(t_list *sta)
{
	// ft_printf("Stack:\n");
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
	int min;
	t_list	*stb;
	
	stb = NULL;
	if (!sta || !*sta || !(*sta)->nt)
		return ;
	min = min_sta(*sta);
	if (ft_atoi((*sta)->ct) == min)  /*&& !sorted(*sta)*/
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
	ft_printf("STA__________\n");
	print_stack(*sta);/***************** */
	ft_printf("STB__________\n");
	print_stack(*stb);/***************** */
}
	// ft_printf("A: %s %s %s %s %s %s %s %s\n", (*sta)->ct, (*sta)->nt->ct, (*sta)->nt->nt->ct, (*sta)->nt->nt->nt->ct, (*sta)->nt->nt->nt->nt->ct, (*sta)->nt->nt->nt->nt->nt->ct, (*sta)->nt->nt->nt->nt->nt->nt->ct, (*sta)->nt->nt->nt->nt->nt->nt->nt->ct);
	// ft_printf("B: %s %s %s %s\n", (*stb)->ct, (*stb)->nt->ct, (*stb)->nt->nt->ct, (*stb)->nt->nt->nt->ct);

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

// May not need a ranking function
// int	ranker(t_list *sta)
// {
// 	int	rank;
// 	int	x;
// }

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


void	find_next(int *sm_bs, t_list **sta, t_list **stb)
{
	int min1 = sm_bs[0];
	int min2 = sm_bs[1];
	int	option;

	ft_printf("min1: %d, min2: %d\n", sm_bs[0], sm_bs[1]);
	while (*stb && ft_lstsize(*stb) > 3)
	{	
		option = evaluate(*stb, min1, min2);
		ft_printf("Option = %d\n", option);
		pusher(option, min1, min2, sta, stb);
		// Re-evaluate the next item after each push
		if (*stb)
		{
			sm_bs = find_n_smallest(*stb, 2);
			min1 = sm_bs[0];
			min2 = sm_bs[1];
			free(sm_bs);
		}
	}
}

void	find_next(int *sm_bs, t_list **sta, t_list **stb)
{
	int i; /*total count of stack b*/
	int min1 = sm_bs[0];
	int min2 = sm_bs[1];
	int	option; /*option is 1, we will rotate b, else we will rrb*/

	min1 = sm_bs[0];
	min2 = sm_bs[1];
	ft_printf("min1: %d, min2: %d\n", sm_bs[0], sm_bs[1]); /*SHOWS THAT SMALLEST 2 IN B ARE ALLOCATED*/
/********************************************************* */
/*THERE HAS TO BE A PROBOLEM AT THIS POINT, START DEBUGGING HERE*/
	while (*stb && ft_lstsize(*stb) > 3)
	{	
		i = -1; /*was originally -1*/
		while (*stb && (*stb)->nt)
			i++;
		option = evaluate(*stb, min1, min2); /*		option = evaluate(*stb, min1, min2, i); not sure why i was */
		ft_printf("Option = %d\n", option);
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
// ensuring that the lowest 2 are pushed to stack b
// void	sort(t_list **sta)
// {
// 	t_list	*stb;

// 	stb = NULL;
// 	while (ft_lstsize(*sta) > 4)
// 	{
// 		if (ft_atoi((*sta)->ct) > (min_sta(*sta) + 3))
// 			ptob(sta, &stb);
// 		else
// 			ra(sta);
// 	}
	// free(min); /*create the min variable to replace (min_sta(*sta) + 3) so that you can free it later>>>*/

// 	// ft_printf("STA_after_ptob_______\n");
// 	// print_stack(*sta);/********* */
// 	// ft_printf("STB_after_ptob_______\n");
// 	// print_stack(stb);/************ */
// 	// sort4ord(sta, &stb);
// 	// while (ft_lstsize(stb) > 4)
// 	// 	find_next(sta, &stb);
// 	// sort4(&stb);
// 	// last_push(sta, &stb);
// }

void	sort(t_list **sta)
{
	t_list	*stb = NULL;
	int		*smallest;
	int		n = 4;

	smallest = find_n_smallest(*sta, n);
	if (!smallest)
		return;

	while (ft_lstsize(*sta) > n)
	{
		if (!is_in_smallest(ft_atoi((*sta)->ct), smallest, n))
			ptob(sta, &stb);
		else
			ra(sta);
	}
	free(smallest);
	ft_printf("STA_after_ptob_______\n");
	print_stack(*sta);/********* */
	ft_printf("STB_after_ptob_______\n");
	print_stack(stb);/********* */
	// Sort the remaining stack and restore pushed elements
	sort4(sta);
	// while (stb)
	// 	ptoa(sta, &stb);
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



// May not need a ranking function
t_list	*rank(t_list *sta)
{
	t_list	*rank_list;
	t_list	*new_node;
	t_list	*temp;
	int		rank;
	int		x;

	rank_list = NULL;
	while (sta)
	{
		rank = 0;
		temp = sta->nt;
		x = ft_atoi(sta->ct);
		while (temp)
		{
			if (ft_atoi(temp->ct) < x)
				rank++;
			temp = temp->nt;
		}
		new_node = ft_lstnew(ft_itoa(rank));
		if (!new_node)
		{
			ft_lstclear(&rank_list, free);
			return (NULL);
		}
		ft_lstadd_back(&rank_list, new_node);
		sta = sta->nt;
	}
	return (rank_list);
}
