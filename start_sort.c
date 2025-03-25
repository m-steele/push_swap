/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:04 by ekosnick          #+#    #+#             */
/*   Updated: 2025/03/25 11:30:32 by ekosnick         ###   ########.fr       */
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

void first_ptob(t_list **sta, t_list **stb, int *sm_as, int n)
{
    if (!sm_as)
        return;
    while (!all_smalls_ptob(*sta, sm_as, n))
    {
        if (is_in_smallest(ft_atoi((*sta)->ct), sm_as, n)) /*Just changed this from !is_in... to is_in...*/
            ptob(sta, stb); /*Basically we are just pushing everything to B with a few conditions*/
        else
            ra(sta);
    }
    free(sm_as); // Free sm_as directly
}

void	sort(t_list **sta, t_list **stb)
{
	int		*sm_as; /*the n smallest values in stack A*/
	int 	n; /*this is in place to chunking 50% or some other ratio*/

    /* The goal is to push all but the 10 biggest values to B, then start sorting 
    chunks of 10; when there is a different multiple of ten, then when we are under
    20, we use ft_lstsize(*sta) % 10 to push the odd number over which should leave us
    with 10 remaining in stack A */

    // OK we need to do a first push when it is not a multiple of ten
    if (ft_lstsize(*sta) % 10 != 1)
    {
        n = ft_lstsize(*sta) % 10;
        sm_as = find_n_smallest(*sta, n);
        if (!sm_as)
            return;
        first_ptob(sta, stb, sm_as, n);
    }

    /* Then we will loop through and push stacks of 10 */
    while (ft_lstsize(*sta) > 20)
    {
        n = 10;
        sm_as = find_n_smallest(*sta, n);
        if (!sm_as)
            return;
        while (!all_smalls_ptob(*sta, sm_as, n))
        {
            if (is_in_smallest(ft_atoi((*sta)->ct), sm_as, n))
            {
                ptob(sta, stb);
                if (ft_atoi((*stb)->ct) < ft_atoi((*stb)->nt->ct))
                    sb(stb);
                if (ft_atoi((*stb)->ct) < ft_atoi(ft_lstlast(*stb)->ct))
                {
                    if (!is_in_smallest(ft_atoi((*sta)->ct), sm_as, n))
                        rr(sta, stb);
                    else
                        rb(stb);
                }
            }
            else if (ft_atoi((*stb)->ct) < ft_atoi((*stb)->nt->ct) && ft_atoi((*stb)->ct) < ft_atoi(ft_lstlast(*stb)->ct))
                rr(sta, stb);
            else
                ra(sta);
        }
        free(sm_as);
        ft_printf("END OF THE INITIAL PUSH\n");
        ft_printf("STACK A in sort function\n");
        print_stack(*sta);
        ft_printf("STACK B in sort function\n");
        print_stack(*stb);
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
	else if (lstsize == 4)
		sort4(sta);
	else
		sort(sta, stb);
}
