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

// sort() will push 50% of lowest values from A to B, iteratively the next 50% lowest
// unitil sta reaches lstsize = 4 or maybe 8. Then will use push_ops() to ptoa() in 
// the correct sequence
void	sort(t_list **sta)
{
	t_list	*stb = NULL;
	int		*sm_as; /*smallest in stack A*/
	int		n;

	while (ft_lstsize(*sta) > 4)	/*((ft_lstsize(*sta)) > (ft_lstsize(*sta) / 2) && ft_lstsize(*sta) >= 9)*/
	{
	n = (ft_lstsize(*sta) / 2);
	sm_as = find_n_smallest(*sta, n);
	ft_printf("sm_as --> (lstsize/2): %d\n", n);
	// ft_printf("sm_as: %d, %d, %d, %d\n", sm_as[0], sm_as[1], sm_as[2], sm_as[3]);
		if (!sm_as)
			return;
		while (ft_lstsize(*sta) > n + 1)
		{
			ft_printf("sm_as --> (lstsize/2): %d\n", n);
			ft_printf("TOP of sta: %s\n", (*sta)->ct);
			if (is_in_smallest(ft_atoi((*sta)->ct), sm_as, n)) /*Just changed this from !is_in... to is_in...*/
				ptob(sta, &stb);
			else
				ra(sta);
			ft_printf("SIZE of sta: %d\n", ft_lstsize(*sta));
		}
		ft_printf("STA after Push to B Loop:\n");
		print_stack(*sta);/*************************** */
		free(sm_as);
	}
	sort4(sta);
	while (stb)
	{
		ft_printf("start push_ops()\n");
		push_ops(sta, &stb);
	}
	// free(sm_bs);
	// find_next(sm_bs, sta, &stb); /*replaced with push_ops()*/
	// last_push(sta, &stb); /*may need last in reverse order then ptoa and ra*/
}

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
// ACTION THIS *******************************************************
	// else if (lstsize > 4 && lstsize < 9) /*Now need to build a function to handle this number of items*/
	// 	sort_up_to8(sta); /*there is room for this in small_sorts()*/
	else if (lstsize > 4) /*we want to make this a bigger starting point*/
		sort(sta);
}