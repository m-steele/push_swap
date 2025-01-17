/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:19:14 by ekosnick          #+#    #+#             */
/*   Updated: 2025/01/17 17:38:12 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	mk_chunk(int size)
// {
// 	int	chunk;

// 	chunk = 1;
// 	if (size < 50)
// 		chunk = 3 + (size - 6) / 7;
// 	else if (size >= 50 && size < 100)
// 		chunk = 10 + (size - 50) / 8;
// 	else if (size >= 100 && size < 350)
// 		chunk = 18 + (size - 100) / 9;
// 	else if (size >= 350 && size <= 500)
// 		chunk = 27 + (size - 350) / 15;
// 	else if (size > 500)
// 		chunk = 37 + (size - 500) / 20;
// 	return (chunk);
// }

// int	find_in_pos(t_list	*sta, int target)
// {
// 	t_list	*curr;
// 	int		pos;
// 	int		size;

// 	if (!sta || !sta->nt)
// 		return (0);
// 	pos = 0;
// 	size = ft_lstsize(sta);
// 	curr = sta;
// 	while (curr && curr->nt)
// 	{
// 		if (ft_atoi(curr->ct) < target && target < ft_atoi(curr->nt->ct))
// 			return (pos + 1);
// 		curr = curr->nt;
// 		pos++;
// 	}
// // if target is smaller or larger than all it goes to the end
// 	if (target < ft_atoi(sta->ct) || target > ft_atoi(ft_lstlast(sta)->ct))
// 		return (size);
// 	return(0);
// }

// void	push_into_pos(t_list **sta, int pos)
// {
// 	int	size;
	
// 	size = ft_lstsize(*sta);
// 	if (pos <= size / 2)
// 		while (pos-- > 0)
// 			ra(sta);
// 	else
// 		while (pos++ < size)
// 			rra(sta);
// }

// void	push_ops(t_list **sta, t_list **stb)
// {
// 	int	target;
// 	int	pos;

// 	if (!stb || !*stb)
// 		return ;
// 	target = ft_atoi((*stb)->ct);
// 	pos = find_in_pos(*sta, target);
// 	push_into_pos(sta, pos);
// 	ptoa(sta, stb);
// }

void sort_5_ina(t_list **sta, t_list *stb)
{
	int		*sm_as;
	int		current_value;

	sm_as = find_n_smallest(*sta, 2);
	if (!sm_as)
		return;
	while (!all_smalls_ptob(*sta, sm_as, 2) && (ft_lstsize(*sta) > 3)) 	/*while (ft_lstsize(*sta) > n + 1)*/
	{
		current_value = ft_atoi((*sta)->ct);
		if (is_in_smallest(current_value, sm_as, 2))
			ptob(sta, &stb);
		else
			ra(sta);
	}
	free(sm_as);
	ft_printf("Start SORT_3 IN STA():\n");
	ft_printf("STA:\n");
	print_stack(*sta);
	ft_printf("STB:\n");
	print_stack(stb);
/*******May need to handle the case if there are <=3 elements
 if (st_lstsize(*st) <= 3) */
	sort3ina(sta, &stb);
	ft_printf("END SORT_3 IN STA():\n");
	ptoa(sta, &stb);
	ptoa(sta, &stb);
	// if (ft_atoi((*sta)->ct) > ft_atoi((*sta)->nt->ct))  /*This should be taken care of in sort3ina()*/
	// 	sa(sta);
}

void sort_5_inb(t_list **sta, t_list *stb)
{
	int		*bg_bs;
	int		current_value;
	int		i_rotatinons;

	bg_bs = find_n_biggest(stb, 2);
	if (!bg_bs)
		return;
	i_rotatinons = 0;
	while (!all_bigs_ptoa(stb, bg_bs, 2) && (ft_lstsize(stb) > 3))
	{
		current_value = ft_atoi((stb)->ct);
		if (is_in_biggest(current_value, bg_bs, 2))
			ptoa(sta, &stb);
		else
		{
			rb(&stb);
			i_rotatinons++;
		}
	}
	free(bg_bs);
/*each time you rotate one in the stack to the bottom, you have to rrb() to get them
back to the top so that you can those specific sort3inb()*/
	while (i_rotatinons > 0 && !inverted(stb))
	{
		rrb(&stb);
		i_rotatinons--;
	}
	ft_printf("Start SORT_3 IN STB():\n");
	sort3inb(sta, &stb); /*-> needs to be in inverse sort to put highest on top*/
	// if (ft_atoi((*sta)->ct) > ft_atoi((*sta)->nt->ct)) /*since you have alrady pushed the two highest to A*/
	// 	sa(sta);			/*The new sort3inb() takes care of the sa() with ss()*/

// I believe sort3inb takes care of the ptoa()s so the below can be deleted
	// ptoa(sta, &stb);
	// ptoa(sta, &stb);
	// ptoa(sta, &stb);
	// if (ft_atoi((*sta)->ct) > ft_atoi((*sta)->nt->ct))
	// 	sa(sta);
}


/*NOTE THAT THE LOGIC IS THAT CHUNKS OF THE LOWEST to highest 10 ARE ALREADY 
PUSHED INTO STB; THEREFORE THE WHILE LOOPS ARE ONLY INTERESTED IN THE x NUMBER (5 OR 3) OF 
HIGHEST IN THAT STACK BECUASE THEY HAVE TO BE AT THE TOP OF THAT STACK*/
void sort_10_ina(t_list **sta, t_list *stb)
{
	int		*sm_as; /*the n smallest values in stack A*/

	sm_as = find_n_smallest(*sta, 5); /******OUR PROBLEM IS WITH THIS HERE ************/
	if (!sm_as)
		return ;
	while (!all_smalls_ptob(*sta, sm_as, 5) && (ft_lstsize(*sta) > 5)) 	/*MAY NOT NEED THE AND CONDITION*/
	{
		if (is_in_smallest(ft_atoi((*sta)->ct), sm_as, 5))
			ptob(sta, &stb);
		else
			ra(sta);
	}
	free(sm_as);	/*TRYING TO FREE THIS EARLIER RATHER THAN AT THE END OF THE FUNCTION*/
	ft_printf("Start SORT_5() STA:\n");
	sort_5_ina(sta, stb);
// I BELEIVE THE SORT 5 IN A IS WORKING FINE
// WE JUST HAVE TO IMPLEMENT THE SAME LOGIC GETTING NUMBERS FROM STACK B TO A
	ft_printf("Start SORT_5() STB:\n");
	sort_5_inb(sta, stb); /*instead of the basic pushing implemented below, we will sort_5_inb()*/	
	// while (n > 0)
	// {
	// 	if (ft_atoi((*sta)->ct) > ft_atoi((*sta)->nt->ct))
	// 		sa(sta);
	// 	if (stb)
	// 		ptoa(sta, &stb);
	// 	n--;
	// }
	// if (ft_atoi((*sta)->ct) > ft_atoi((*sta)->nt->ct))/*line probably not needed but keep here for now*/
}

// THEN WE NEED TO WRITE THE sort_10_inb() function.
void sort_10_inb(t_list **sta, t_list *stb)
{
	int		*bg_bs; /*the n biggest in stack b*/
	int		current_value;
	int		i_rotatinons;
	
	bg_bs = find_n_biggest(stb, 5);
	if (!bg_bs)
		return;
	i_rotatinons = 0;
	while (!all_bigs_ptoa(stb, bg_bs, 5) && (ft_lstsize(stb) > 5))
	{
		current_value = ft_atoi((stb)->ct);
		if (is_in_biggest(current_value, bg_bs, 5))
			ptoa(sta, &stb);
		else
		{
			rb(&stb);
			i_rotatinons++;
		}
	}
	while (i_rotatinons > 0)
	{
		rrb(&stb);
		i_rotatinons--;
	}
	free(bg_bs); /*THIS WAS PLACED AT THE END OF THE FUNCTI*/
	sort_5_ina(sta, stb);
	ft_printf("Start SORT_5 IN STB():\n");
	sort_5_inb(sta, stb); /*-> needs to be in inverse sort to put highest on top*/
}