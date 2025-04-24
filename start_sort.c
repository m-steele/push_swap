/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:04 by ekosnick          #+#    #+#             */
/*   Updated: 2025/04/23 20:41:36 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int 	n;
	int		pushed;
	int		i;

	n = ft_lstsize(*sta);
	sm_as = find_n_smallest(*sta, n / 2);
	pushed = 0;
	i = 0;

	while (n > 6 && i < n && pushed < n / 2)
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
	while (n - pushed > 3)
	{
		ptob(sta, stb);
		pushed++;
	}
}

void start_sort(t_list **sta, t_list **stb)
{
	int	lstsize;

	lstsize = ft_lstsize(*sta);
	if (!sta || !*sta)
		return ;
	if (lstsize == 2)
		sa(sta);
	else if (lstsize == 3)
		sort3(sta);
	else
	{
		calculate_index(*sta, lstsize);
		first_ptob(sta, stb);
		sort3(sta);
	}
// everything appears to work at this point
	while (*stb)
	{
		id_target(sta, stb);/*--> id_target seems fine for now.*/
		negotiate_price(sta, stb);
		pay_cheapest(sta, stb);
	}
	print_stack(*sta);
	print_stack(*stb);
}
	// if (!sorted(*sta))
/*NOT sure about the code below for handling the end of it.*/
	// {
	// 	while (ft_lstsize(*sta) > 3)
	// 		ptoa(sta, stb);
	// 	sort3(sta);
	// }

/*use these as trackers:
print_stack(*sta);
print_stack(*stb);*/