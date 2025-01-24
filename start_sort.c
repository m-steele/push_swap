/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:04 by ekosnick          #+#    #+#             */
/*   Updated: 2025/01/24 14:12:46 by ekosnick         ###   ########.fr       */
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
		ft_printf("Size of 'n' = %d\n", n);
 		while (!all_smalls_ptob(*sta, sm_as, n))
		{
			if (is_in_smallest(ft_atoi((*sta)->ct), sm_as, n)) /*Just changed this from !is_in... to is_in...*/
				ptob(sta, stb);/*Basically we are just pushing everything to B with a few conditions*/
			else
				ra(sta);
		}
		ft_printf("END FIRST PUSH TO B\n");
		ft_printf("STACK A in first_ptob() function\n");
		print_stack(*sta);
		free(sm_as);
}

void	sort(t_list **sta)
{
	int		*sm_as; /*the n smallest values in stack A*/
	t_list	*stb = NULL;
	int 	n; /*this is in place to chunking 50% or some other ratio*/
	// int 	i = 1; /*if we continue on the path as below*/

/*The goal is to push all but the 10 biggest values to B, then start sorting 
chuncks of 10; when there is a different multiple of ten, then when we are under
20, we use ft_lstsize(*sta) % 10 to push the odd number over which should leave us
with 10 remaining in stack A
*/
/*OK we need to do a first push when it is not a multiple of ten
This is just the first check to push that amount over to b, before the big push*/
	if (ft_lstsize(*sta) % 10 != 0)
	{
		n = ft_lstsize(*sta) % 10;
		ft_printf("START FIRST PUSH TO B\n");
		ft_printf("STACK A in sort function\n");
		print_stack(*sta);
		first_ptob(sta, &stb, n);
	}
/*Then we will loop through and push stacks of 10*/
	while (ft_lstsize(*sta) > 10)	/*((ft_lstsize(*sta)) > (ft_lstsize(*sta) / 2) && ft_lstsize(*sta) >= 9)*/
	{
		n = 10;
		sm_as = find_n_smallest(*sta, n);
		if (!sm_as)
			return;
 		while (!all_smalls_ptob(*sta, sm_as, n))
		{
			if (is_in_smallest(ft_atoi((*sta)->ct), sm_as, n)) /*Just changed this from !is_in... to is_in...*/
				ptob(sta, &stb);/*Basically we are just pushing everything to B with a few conditions*/
			else
				ra(sta);
		}
		free(sm_as);
		ft_printf("END OF THE INITIAL PUSH\n");
		ft_printf("STACK A in sort function; n = %d\n", ft_lstsize(*sta));
		print_stack(*sta);
		ft_printf("STACK B in sort function; n = %d\n", ft_lstsize(stb));
		print_stack(stb);
	
		sort_10_ina(sta, stb); /*&stb is used if it is passed to a double pointer*/
		
		/*NOTE that sort_10_inb is never called and so this is a problem*/
		ft_printf("END sort_10_ina(sta, stb);\n");
		ft_printf("STACK A ; n = %d\n", ft_lstsize(*sta));
		print_stack(*sta);
		ft_printf("STACK B; n = %d\n", ft_lstsize(stb));
		print_stack(stb);
		/*makeshift push to a so that the process can be completed*/
		/*SOMEHOW WE LOSE 3 VALUES BEFORE WE GET HERE, SOMEWHERE IN sort_10_ina()*/
		while (stb)
		{
   			ptoa(sta, &stb);
		    if (*sta && (*sta)->nt && ft_atoi((*sta)->ct) > ft_atoi((*sta)->nt->ct))
		        sa(sta);
		}
		ft_printf("STACK A AT END OF SORT; n = %d\n", ft_lstsize(*sta));
		print_stack(*sta);
		ft_printf("STACK B AT END OF SORT; n = %d\n", ft_lstsize(stb));
		print_stack(stb);
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

/*	NOTE THIS WILL HAVE TO BE MODIFIED TO HANDLE THE 5 AND 10 CASES
	else if (ft_lstsize(sta) > 4 && ft_lstsize(sta) <= 10)
		sort_10_ina(sta, stb);
*/
	else
		sort(sta);
}

/*TEN	TEN	TEN	TEN		TEN	TEN*//*TEN	TEN	TEN	TEN		TEN	TEN*/