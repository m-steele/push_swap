/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:04 by ekosnick          #+#    #+#             */
/*   Updated: 2025/03/19 12:03:18 by ekosnick         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

/*AT SOME POINT YOU MAY BE ABLE TO DO SOMETHING LIKE THIS ON THE FIRST_PTOB
THE IDEA IS TO SEE IF YOU CAN USE RR OR SS WHLE SORTING THE FIRT BIT OVER TO B*/
// if (ft_lstsize(*stb) > 1)
// 				{
// 					if (ft_atoi((*stb)->ct) < ft_atoi((*stb)->nt->ct))
// 						sb(stb);
// 					if (ft_atoi((*stb)->ct) < ft_atoi(ft_lstlast(*stb)->ct))
// 					{
// 						if (!is_in_smallest(ft_atoi((*sta)->ct), *sm_as, n))
// 							rr(sta, stb);
// 						else
// 							rb(stb);
// 					}
// 					if (ft_atoi((*stb)->ct) < ft_atoi((*stb)->nt->ct) && ft_atoi((*stb)->ct) < ft_atoi(ft_lstlast(*stb)->ct))
// 						rr(sta, stb);
// 					else
// 					{
// 						ft_printf("THE CONDITION IF > 1\n");
// 						ra(sta);
// 					}
// 				}
// 			}


void	first_ptob(t_list **sta, t_list **stb, int n)
{
		int *sm_as;
		
		sm_as = find_n_smallest(*sta, n);
		if (!sm_as)
			return ;
 		while (!all_smalls_ptob(*sta, sm_as, n))
		{
			if (is_in_smallest(ft_atoi((*sta)->ct), sm_as, n)) /*Just changed this from !is_in... to is_in...*/
				ptob(sta, stb);/*Basically we are just pushing everything to B with a few conditions*/
			else
				ra(sta);
		}
		free(sm_as);
}

void	sort(t_list **sta)
{
	int		*sm_as; /*the n smallest values in stack A*/
	t_list	*stb = NULL;
	int 	n; /*this is in place to chunking 50% or some other ratio*/

	if (ft_lstsize(*sta) % 10 != 0)
	{
		n = ft_lstsize(*sta) % 10;
		first_ptob(sta, &stb, n);
	}
	if (ft_lstsize(*sta) >= 10)	/*((ft_lstsize(*sta)) > (ft_lstsize(*sta) / 2) && ft_lstsize(*sta) >= 9)*/
	{
		while (ft_lstsize(*sta) >= 20)
		{
			n = 10;
			sm_as = find_n_smallest(*sta, n);
			if (!sm_as)
				return;
 			while (!all_smalls_ptob(*sta, sm_as, n))
			{
				if (is_in_smallest(ft_atoi((*sta)->ct), sm_as, n)) /*Just changed this from !is_in... to is_in...*/
					ptob(sta, &stb);
				else
					ra(sta);
			}
			free(sm_as);
			sort_10_ina(sta, stb); /*&stb is used if it is passed to a double pointer*/
		}
	}
	if (ft_lstsize(*sta) == 10)
		sort_10_ina(sta, stb);
	/*THIS SHOULD BE IT, IF WE CAN FIX THE LOGIC IN SORT_10_INB() WE SHOULD BE GOOD*/
	while (stb && ft_lstsize(stb) >= 10)
			sort_10_inb(sta, stb);
	if (stb && ft_lstsize(stb) >= 5)
	ft_printf("Start sort_5_inb()\n");
		sort_5_inb(sta, stb);
	while (stb != NULL)
	{
		ft_printf("STACK B AT END OF SORT; n = %d\n", ft_lstsize(stb));
		print_stack(stb);
		ft_printf("PUSHING ERROR Entering last while (stb when there should be nothing)\n");
		break ;
		// if (ft_lstsize(stb) >= 3)
		// 	sort3inb(sta, &stb);
		// else
		// 	ptoa(sta, &stb);
		// if (*sta && (*sta)->nt && ft_atoi((*sta)->ct) > ft_atoi((*sta)->nt->ct))
		// 	sa(sta);
	}
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
	else
		sort(sta);
}

/*TEN	TEN	TEN	TEN		TEN	TEN*//*TEN	TEN	TEN	TEN		TEN	TEN*/