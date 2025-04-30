/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:04 by ekosnick          #+#    #+#             */
/*   Updated: 2025/04/30 07:06:12 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Need to fix this and done ????  static void*/
static void	fin_sort(t_list **sta) /*, t_list **stb*/
{
	if (!sorted(*sta))
	{
		while (ft_atoi((*sta)->ct) > ft_atoi(ft_lstlast(*sta)->ct)) // Access and convert the last node's `ct`
			rra(sta);
		// while (!sorted(*sta))
		// {
		// 	rra(sta);
		// 	ptob(sta, stb);
		// }
		// while (*stb)
		// {
		// 	id_target(sta, stb);
		// 	negotiate_price(sta, stb);
		// 	pay_cheapest(sta, stb);
		// }
	}
}

void calculate_index(t_list *sta, int lstsize)
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

/*20250410: COMPLETELY changing tacktics to push all but last three, then will
sort from B around the placement of those in A. Also, will use n and sm_as
to divide the bulk of the fptob into largest and smallest*/

void	first_ptob(t_list **sta, t_list **stb)
{
	int		*sm_as; /*the n smallest values in stack A*/
	int		*bg_as;
	int 	n;
	int		pushed;
	int		i;

	n = ft_lstsize(*sta);
	sm_as = find_n_smallest(*sta, n / 2);
	pushed = 0;
	i = 0;

	while (/*n > 6 && */i < n && pushed < n / 2)
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
	bg_as = f_n_b(*sta, 1);/**/
	sm_as = find_n_smallest(*sta, 1);
	while (n - pushed > 3 )
	{
		if (inb(ft_atoi((*sta)->ct), bg_as, 1) || is_in_smallest(ft_atoi((*sta)->ct), sm_as, 1))
			ra(sta);
		else
		{
			ptob(sta, stb);
			pushed++;
		}
	}
	free(bg_as);
	free(sm_as);
}


/*Seems likely that the index needs to be used instead of the values...*/
void start_sort(t_list **sta, t_list **stb)
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
		id_target(sta, stb);/*--> id_target seems fine for now.*/
		negotiate_price(sta, stb);
		pay_cheapest(sta, stb);
	}
	/*
	THEN SOME CLOSING OPERATION TO PUSH THESE LAST BITS OVER THEN APPLY A SORT 
	FUNCTION TO GET THE REMAINDERS*/
	fin_sort(sta);
	// if (!sorted(*sta))
	// 	start_sort(sta, stb);
	// print_stack(*sta);
}

/*use these as trackers:
print_stack(*sta);
print_stack(*stb);*/