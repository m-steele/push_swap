/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:04 by ekosnick          #+#    #+#             */
/*   Updated: 2025/01/22 16:31:24 by ekosnick         ###   ########.fr       */
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
	int 	n; /*this is in place to chunking 50% or some other ratio*/

/*NOTE WE ARE JUST GOING TO SKIP OVER THIS WHILE LOOP IF IT IS LESS THAN 10
I think you are going to need to make another conditional for handling those > 20 and
those between 10 and 20*/

	if (ft_lstsize(*sta) > 10)	/*((ft_lstsize(*sta)) > (ft_lstsize(*sta) / 2) && ft_lstsize(*sta) >= 9)*/
	{

/* I THINK THE BEST THING TO DO AT THIS POINT IS TO WRITE MAKE THE FUNCTION SO THAT
WE CAN PUSH 10 AT A TIME UNTIL WE ARE STA IS UNDER 10*/

		// if (ft_lstsize(*sta) > 20)

		// n = ft_lstsize(*sta) % 10;
		n = 10;
		ft_printf("value of n= %d\n", n);
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
		ft_printf("END OF THE INITIAL PUSH\n");
		ft_printf("STACK A in sort function\n");
		print_stack(*sta);
		ft_printf("STACK B in sort function\n");
		print_stack(stb);
	}
	// if (ft_lstsize(*sta) < n)/*CAN BUILD A FUNCTION FOR DEALING WITH THESE SIZES*/
	// {
	// 	four_nine(sta, &stb); /*THis will be our function to sort when there are only 4 - 9 remaining*/
	ft_printf("Start sort_10_ina(sta, stb);\n");
	sort_10_ina(sta, stb); /*&stb is used if it is passed to a double pointer*/
	ft_printf("END sort_10_ina(sta, stb);\n");
	// ft_printf("Size of stb: %d\n", ft_lstsize(stb));	
	while (ft_lstsize(stb) >= 10)
	{
		ft_printf("Start sort_10_inb(sta, stb); from loop in sort:\n");
		sort_10_inb(sta, stb); /*CAN RESULT IN INFINITE LOOP*/
		ft_printf("END sort_10_inb(sta, stb); from loop in sort\n");
	}
		ft_printf("Size of stb: %d\n", ft_lstsize(stb));	
	while (stb)	/*HAVE TO FIX THIS FOR THE A FINAL SORT OF 10 OR LESS*/
	{
		ptoa(sta, &stb);
		if (ft_atoi((*sta)->ct) > ft_atoi((*sta)->nt->ct))
			sa(sta);
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
	// else if (lstsize > 4 && lstsize <= 10) Originally was going to call push_10_ina, but cannot from this point
	// else if (lstsize > 10 && lstsize < 20)
	// 	sortsomething(sta);
	else
		sort(sta);
}

/*TEN	TEN	TEN	TEN		TEN	TEN*//*TEN	TEN	TEN	TEN		TEN	TEN*/