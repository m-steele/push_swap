/*push_opsTEN.c
THIS IS THE START_SORT CHINCKING 10*/

#include "push_swap.h"

void sort_5_ina(t_list **sta, t_list *stb)
{
	int		*sm_as;
	int		current_value;

	sm_as = find_n_smallest(*sta, 2);
	if (!sm_as)
		return;
	while (!all_smalls_ptob(*sta, sm_as, 2) && (ft_lstsize(*sta) > 3)) /****Place where there may be issues with the logic */
	{
		current_value = ft_atoi((*sta)->ct);
		if (is_in_smallest(current_value, sm_as, 2))
			ptob(sta, &stb);
		else
			ra(sta);
	}
	free(sm_as);
	sort3ina(sta, &stb);
	ptoa(sta, &stb);
	ptoa(sta, &stb);
	if (ft_atoi((*sta)->ct) > ft_atoi((*sta)->nt->ct))/*This is a potential place to combine operations*/
		sa(sta);
}

/*SEEMS THAT WE WILL NEED A FINAL PUSH FROM B OTHERWISE THE LOGIC WILL NOT WORK
see above*/

void sort_5_ina_from_10inb(t_list **sta, t_list *stb)
{
	int		*sm_as;
	int		current_value;
	int		i_rotatinons;

	i_rotatinons = 0;
	sm_as = find_n_smallest(*sta, 2);
	if (!sm_as)
		return;
	while (!all_smalls_ptob(*sta, sm_as, 2) && (ft_lstsize(*sta) > 3)) /****Place where there may be issues with the logic */
	{
		current_value = ft_atoi((*sta)->ct);
		if (is_in_smallest(current_value, sm_as, 2))
			ptob(sta, &stb);
		else
		{
			ra(sta);
			i_rotatinons++;
		}
	}
	while (i_rotatinons > 0)
	{
		rra(sta);
		i_rotatinons--;
	}
	free(sm_as);
	sort3ina(sta, &stb);
	ptoa(sta, &stb);
	ptoa(sta, &stb);
	if (ft_atoi((*sta)->ct) > ft_atoi((*sta)->nt->ct))/*This is a potential place to combine operations*/
		sa(sta);
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
	while (i_rotatinons > 0 && !inverted(stb))/*forseeable issues if is inverted while*/
	{
		rrb(&stb);
		i_rotatinons--;
	}
	sort3inb(sta, &stb); /*-> needs to be in inverse sort to put highest on top*/
}

void sort_10_ina(t_list **sta, t_list *stb)
{
	int		*sm_as; /*the n smallest values in stack A*/
	int 	n = 5;

	sm_as = find_n_smallest(*sta, n);
	if (!sm_as)
		return ;
	while (!all_smalls_ptob(*sta, sm_as, n) && (ft_lstsize(*sta) > n))
	{
		if (is_in_smallest(ft_atoi((*sta)->ct), sm_as, n))
			ptob(sta, &stb);
		else
			ra(sta);
	}
	free(sm_as);
	sort_5_ina(sta, stb);
	sort_5_inb(sta, stb);/*QUESTION, what if there is not 5 values in B???????*/
}

void sort_10_inb(t_list **sta, t_list *stb)
{
	int		*bg_bs; /*the n biggest in stack b*/
	int		current_value;
	int		i_rotatinons;
	int 	n = 5;/*ft_lstsize(*sta) % 10;*/
	
	bg_bs = find_n_biggest(stb, n);
	if (!bg_bs)
		return;
	i_rotatinons = 0;
	// if (ft_lstsize(stb) < 10) /* have to check if this is the place that the final push will be called*/
	// 	final_ptoa(sta, stb);
	while (!all_bigs_ptoa(stb, bg_bs, n) && (ft_lstsize(stb) > n))
	{
		current_value = ft_atoi((stb)->ct);
		if (is_in_biggest(current_value, bg_bs, n))
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
	free(bg_bs);
	sort_5_ina_from_10inb(sta, stb);
	sort_5_inb(sta, stb); /*-> needs to be in inverse sort to put highest on top*/
}
