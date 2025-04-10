/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:04 by ekosnick          #+#    #+#             */
/*   Updated: 2025/04/10 12:27:32 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Note wea re changing the name of this from startsortTEN.c to start_sort.c so we can check if we can process 5 and 10
/*TEN	TEN	TEN	TEN		TEN	TEN*/

#include "push_swap.h"

int	all_smalls_ptob(t_list *sta, int *smallest, int n)
{
	while (sta)
	{
		if (is_in_smallest(ft_atoi(sta->ct), smallest, n))
			return (0);
		sta = sta->nt;
	}
	return (1);
}

int	all_bigs_ptoa(t_list *st, int *biggest, int n)
{
	while (st)
	{
		if (is_in_biggest(ft_atoi(st->ct), biggest, n))
			return (0);
		st = st->nt;
	}
	return (1);
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
	print_stack(*sta);
	print_stack(*stb);
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
		first_ptob(sta, stb);
	sort3(sta);

/* STOPPED HERE 20250410 -> Need to create:
		id_target(sta, stb);
		negotiate_price(sta, stb);
		pay_cheapest(sta, stb);
*/
	
	while (*stb)
	{
		id_target(sta, stb);
		negotiate_price(sta, stb);
		pay_cheapest(sta, stb);
	}
	if (!sorted(*sta))
/*NOT sure about the code below for handling the end of it.*/
	{
		while (ft_lstsize(*sta) > 3)
			ptoa(sta, stb);
		sort3(sta);
	}
}
