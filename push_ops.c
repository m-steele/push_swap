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
	while (!all_smalls_ptob(*sta, sm_as, 2) && (ft_lstsize(*sta) > 3))
	{
		current_value = ft_atoi((*sta)->ct);
		if (is_in_smallest(current_value, sm_as, 2))
			ptob(sta, &stb);
		else
			ra(sta);
	}
	free(sm_as);
	ft_printf("Start SORT_3 IN STA(): from sort_5_ina\n");
	// ft_printf("STA:\n");
	// print_stack(*sta);
	// ft_printf("STB:\n");
	// print_stack(stb);
/*******May need to handle the case if there are <=3 elements
 if (st_lstsize(*st) <= 3) */
	sort3ina(sta, &stb);
	ft_printf("END SORT_3 IN STA(): from sort_5_ina\n");
	ptoa(sta, &stb);
	ptoa(sta, &stb);
	if (ft_atoi((*sta)->ct) > ft_atoi((*sta)->nt->ct))/*This is a potential place to combine operations*/
		sa(sta);
}


void final_ptoa(t_list **sta, t_list *stb)
{
	int		*bg_bs;
	int		current_value;
	int		i_rotatinons;
	int		n = ft_lstsize(stb) % 10;

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
	while (i_rotatinons > 0 && !inverted(stb))
	{
		rrb(&stb);
		ptoa(sta, &stb);
		i_rotatinons--;
	}
	ft_printf("BEFORE SORT_3 IN STB() from final push:\n");
	sort3inb(sta, &stb); /*-> needs to be in inverse sort to put highest on top*/
	// if (ft_atoi((*sta)->ct) > ft_atoi((*sta)->nt->ct)) /*since you have alrady pushed the two highest to A*/
	// 	sa(sta);			/*The new sort3inb() takes care of the sa() with ss()*/
	ft_printf("STACK A from final_ptoa\n");
	print_stack(*sta);
	ft_printf("STACK B from final_ptoa\n");
	print_stack(stb);
}

/*SEEMS THAT WE WILL NEED A FINAL PUSH FROM B OTHERWISE THE LOGIC WILL NOT WORK
see above*/
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
	ft_printf("BEFORE SORT_3 IN STB() from sort_5_inb:\n");
	sort3inb(sta, &stb); /*-> needs to be in inverse sort to put highest on top*/
	// if (ft_atoi((*sta)->ct) > ft_atoi((*sta)->nt->ct)) /*since you have alrady pushed the two highest to A*/
	// 	sa(sta);			/*The new sort3inb() takes care of the sa() with ss()*/

// I believe sort3inb takes care of the ptoa()s so the below can be deleted
	// ptoa(sta, &stb);
	// ptoa(sta, &stb);
	// ptoa(sta, &stb);
	// if (ft_atoi((*sta)->ct) > ft_atoi((*sta)->nt->ct))
	// 	sa(sta);
	ft_printf("STACK A from sort_in_5()\n");
	print_stack(*sta);  /*WHY DOES THIS CREATE AN INFINATE LOOP if 12 digits?*/
	ft_printf("STACK B from sort_in_5()\n");
	print_stack(stb);
}

/*NOTE THAT THE LOGIC IS THAT CHUNKS OF THE LOWEST to highest 10 ARE ALREADY 
PUSHED INTO STB; THEREFORE THE WHILE LOOPS ARE ONLY INTERESTED IN THE x NUMBER (5 OR 3) OF 
HIGHEST IN THAT STACK BECUASE THEY HAVE TO BE AT THE TOP OF THAT STACK*/
void sort_10_ina(t_list **sta, t_list *stb)
{
	int		*sm_as; /*the n smallest values in stack A*/
	int 	n = ft_lstsize(*sta) % 10;
	ft_printf("VALUE OF n AFTER: 	int 	n = ft_lstsize(*sta) MODULS 10;: %d\n", n);

/*THIS IS WHERE THE PROBLEMS BEGIN, WE CANNOT JUST USE A CONSTANT NUMBER
WE WILL HAVE TO USE MODULUS OR SOME DIVISION AND SET N TO IT SO WE CAN DEAL
WITH ODD NUMBERS*/
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
	ft_printf("Start SORT_5() STA from sort_10_ina():\n");
	sort_5_ina(sta, stb);
// I BELEIVE THE SORT 5 IN A IS WORKING FINE
// WE JUST HAVE TO IMPLEMENT THE SAME LOGIC GETTING NUMBERS FROM STACK B TO A
	ft_printf("Start SORT_5() STB from sort_10_ina():\n");
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

void sort_10_inb(t_list **sta, t_list *stb)
{
	int		*bg_bs; /*the n biggest in stack b*/
	int		current_value;
	int		i_rotatinons;
	int 	n = ft_lstsize(*sta) % 10;
	
	bg_bs = find_n_biggest(stb, n);
	if (!bg_bs)
		return;
	i_rotatinons = 0;
	if (ft_lstsize(stb) < 10) /* have to check if this is the place that the final push will be called*/
		final_ptoa(sta, stb);
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
	free(bg_bs); /*THIS WAS PLACED AT THE END OF THE FUNCTI*/
	ft_printf("Start SORT_5 IN STA() from sort_10_inb:\n");
	sort_5_ina(sta, stb);
	ft_printf("Start SORT_5 IN STB() from sort_10_inb:\n");
	sort_5_inb(sta, stb); /*-> needs to be in inverse sort to put highest on top*/
}