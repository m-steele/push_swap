/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:04 by ekosnick          #+#    #+#             */
/*   Updated: 2025/01/17 16:48:04 by ekosnick         ###   ########.fr       */
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

/*TEN	TEN	TEN	TEN		TEN	TEN*/

void	sort(t_list **sta)
{
	int		*sm_as; /*the n smallest values in stack A*/
	t_list	*stb = NULL;
	
	int n = 10; /*this is in place to chunking 50% or some other ratio*/

/*NOTE WE ARE JUST GOING TO SKIP OVER THIS WHILE LOOP IF IT IS LESS THAN 10*/
	while (ft_lstsize(*sta) > n)	/*((ft_lstsize(*sta)) > (ft_lstsize(*sta) / 2) && ft_lstsize(*sta) >= 9)*/
	{
	sm_as = find_n_smallest(*sta, n);
		if (!sm_as)
			return;
		while (!all_smalls_ptob(*sta, sm_as, n)) 	/*while (ft_lstsize(*sta) > n + 1)*/
		{
			if (is_in_smallest(ft_atoi((*sta)->ct), sm_as, n)) /*Just changed this from !is_in... to is_in...*/
				ptob(sta, &stb);
			else
				ra(sta);
		}
		free(sm_as);
	}
	ft_printf("Start SORT_10 STA():\n");
	sort_10_ina(sta, stb);
	ft_printf("END SORT_10 STA():\n");
	ft_printf("Size of stb: %d\n", ft_lstsize(stb));	
	while (ft_lstsize(stb) >= 10)
	{
		ft_printf("Start SORT_10 STB():\n");
		sort_10_inb(sta, stb);
	}
ft_printf("END SORT_10 STB():\n");
	while (stb)
	{
		if (ft_atoi((*sta)->ct) > ft_atoi((*sta)->nt->ct))
			sa(sta);
		ptoa(sta, &stb);
	}
}

/*TEN	TEN	TEN	TEN		TEN	TEN*/
/*TEN	TEN	TEN	TEN		TEN	TEN*/

void start_sort(t_list **sta)
{
	int	lstsize;

	lstsize = ft_lstsize(*sta); 
	if (!sta || !*sta)
		return ;
	if (lstsize == 2)
		sa(sta);
	else if (lstsize == 3)
		sort3(sta);
	else if (lstsize == 4)
		sort4(sta);
	// else if (lstsize > 4 && lstsize < 10) we will have to address this if this scheme works...
	else if (lstsize > 4)
		sort(sta);
}

/*TEN	TEN	TEN	TEN		TEN	TEN*//*TEN	TEN	TEN	TEN		TEN	TEN*/