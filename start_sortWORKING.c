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

// sort() 50% does not work and not even close; mk_chunck function works but the sorting is not accurate
// and there are still issues with meeting the efficiency. Therefore, the problem has to 
// be in the sorting from b back to a. The goal now is to ptob in chunks of 10 until
// sta reaches lstsize = 10. Modify push_ops() to deal with 10. First lets figure out how to sort 10
// Then modify it so that it pushes the inverse from b to a

// can we sort ten --> push five sort five push five back sort five??????????? 
// The idea is to push back to a in the same fashion, and back to B until bother are sorted
// also will put in a check to see if ((sta)->ct) > ((sta)->nt-ct) && (ft_lstlast((sta)->ct)) < (sta)->ct)
// so we can implement the ss, rrr, and rr functions while going back and forth... just to 
// check the top and bottom to see if the same functions are applicable

void	sort(t_list **sta)
{
	t_list	*stb = NULL;
	int		*sm_as; /*smallest in stack A*/
	int		n;

	while (ft_lstsize(*sta) > 4)	/*((ft_lstsize(*sta)) > (ft_lstsize(*sta) / 2) && ft_lstsize(*sta) >= 9)*/
	{
	// n = (ft_lstsize(*sta) / 2);
	n = mk_chunk(ft_lstsize(*sta));
	sm_as = find_n_smallest(*sta, n);
	// ft_printf("sm_as --> (lstsize/2): %d\n", n);
	// ft_printf("sm_as: %d, %d, %d, %d\n", sm_as[0], sm_as[1], sm_as[2], sm_as[3]);
		if (!sm_as)
			return;
// The helper function ensure all smallest are pushed
		while (!all_smalls_ptob(*sta, sm_as, n)) 	/*while (ft_lstsize(*sta) > n + 1)*/
		{
			// ft_printf("sm_as or n --> (lstsize/2): %d\n", n);
			// ft_printf("TOP of sta: %s\n", (*sta)->ct);
			if (is_in_smallest(ft_atoi((*sta)->ct), sm_as, n)) /*Just changed this from !is_in... to is_in...*/
				ptob(sta, &stb);
			else
				ra(sta);
			// ft_printf("SIZE of sta: %d\n", ft_lstsize(*sta));
		}
		// ft_printf("STA and STB after PtoB() Loop:\n");
		// print_stack(*sta);/*************************** */
		// ft_printf("\n");
		// print_stack(stb);/*************************** */
		// ft_printf("\n");
		free(sm_as);
	}
	sort4(sta);
	// ft_printf("STA after SORT_4():\n");
	// print_stack(*sta);/*************************** */
	// ft_printf("\n");
	while (stb)
	{
/********************************************** */
/*It appears that the logic behind push_ops is not great*/
		// ft_printf("start push_ops()\n");
		push_ops(sta, &stb);
		// ft_printf("STA after push_ops():\n");
		// print_stack(*sta);/*************************** */
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
// ACTION THIS *******************************************************
	// else if (lstsize > 4 && lstsize < 9) /*Now need to build a function to handle this number of items*/
	// 	sort_up_to8(sta); /*there is room for this in small_sorts()*/
	else if (lstsize > 4) /*we want to make this a bigger starting point*/
		sort(sta);
}