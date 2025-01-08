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

int	evaluate(t_list *stb, int min1, int min2)
{
	int	rmin1; /*rank 1 min*/
	int	rmin2; /*rank 2 min*/
	int	imin1;
	int	imin2;
	int i = 0;

		// while (*stb && ft_atoi((*stb)->nt->ct) != min_sta(*stb))
	ft_printf("I: %i\n", i); /*currently this function is called but crashes at 33*/
	while (stb && ft_atoi((stb)->ct) != min1)	/*(ft_lstsize(stb) != min1) && */
	{
		stb = stb->nt;/*note that this could be stb->ct or stb->nt->ct*/
		i++;
	}
	rmin1 = i;
	i = 0;
	while (stb && ft_atoi((stb)->ct) != min2) /*(ft_lstsize(stb) != min2) && */
	{
		stb = stb->nt;
		i++;
	}
	rmin2 = i;
	imin1 = ((i/2) - rmin1);
	imin2 = ((i/2) - rmin2);
	ft_printf("rmin1: %i, rmin2: %i\n", rmin1, rmin2);
	// ft_printf("I: %i, imin1: %i, imin2: %i\n", i, imin1, imin2);
	if (ft_abs(imin1) > ft_abs(imin2) && imin1 > 1)
		return (1);
	else if (ft_abs(imin1) > ft_abs(imin2) && imin1 < 1)
		return (2);
	else if (ft_abs(imin1) < ft_abs(imin2) && imin1 > 1)
		return (3);
	else/*this will also include if imin1 == imin2 at middle: rrb*/
		return (4);
}

void	pusher(int option, int min1, int min2, t_list **sta, t_list **stb)
{
	ft_printf("OPTION: %i, rmin1: %i, rmin2: %i\n", option, min1, min2);
	ft_printf("STACK B:\n");
	print_stack(*stb);
	// while (*stb)
	// {

	// PRETTY SURE THE WHILE LOOP ABOVE CREATES THE INFINITE LOOP -> delete it
	// 1.
	// THERE IS AN ISSUE WIHT THE LOGIC BELOW AS WE SHOULD NOT BE USING
	// ra OR rra --> double check the logic wiht the options given from evaluate()
	// 2.
	// 	ALSO: THERE IS A PROBLEM WIHT THE LOGIC OF PUSING THE SMALLEST 2 TO A
	// BECUASE THERE IS A SCENARIO WHERE THE SMALLEST IS NOT PUSHED TO A UNTIL THE END
	// WILL NEED SOME INTERMEDIATE FUNCTION IN HERE TO MAKE SURE THAT THESE
	// ARE HANDLED
	// 3.
	// YOU MAY WANT TO KEEP THE HIGHEST 4 IN STACK A, THEN PUSH THE HIGHEST
	// 2 FROM STACK B TO A, THEN SORT SORT
		if (option == 1)
		{
		while (ft_atoi((*stb)->ct) != min1 && ft_atoi((*stb)->ct) != min2)
			ra(stb); 
		if (*stb)
			ptoa(sta, stb);
		}
		else if (option == 2)
		{
		while (ft_atoi((*stb)->ct) != min1 && ft_atoi((*stb)->ct) != min2)
				rra(stb);
		if (*stb)
			ptoa(sta, stb);
		}
		else if (option == 3)
		{
		while (ft_atoi((*stb)->ct) != min1 && ft_atoi((*stb)->ct) != min2)
				rb(stb);
		if (*stb)
			ptoa(sta, stb);
		}
		else
		{
		while (ft_atoi((*stb)->ct) != min1 && ft_atoi((*stb)->ct) != min2)
				rrb(stb);
		if (*stb)
			ptoa(sta, stb);
		// }
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
// find out if your next number is closer to the top or bottom
// MUST USE THE EVALUATOR FUNCTION, BUT DOES NOT LOOK RIGHT
void	find_next(int *sm_bs, t_list **sta, t_list **stb)
{
	int min1 = sm_bs[0];
	int min2 = sm_bs[1];
	int	option;

	ft_printf("min1: %d, min2: %d\n", sm_bs[0], sm_bs[1]);
	while (*stb && ft_lstsize(*stb) > 3)
	{	
		option = evaluate(*stb, min1, min2);
		ft_printf("Option = %d\n", option);
		pusher(option, min1, min2, sta, stb);
		// Re-evaluate the next item after each push
		if (*stb)
		{
			sm_bs = find_n_smallest(*stb, 2); /*part of the infinite loop; pusher not pushing so the while loop keeps printing*/
			min1 = sm_bs[0];
			min2 = sm_bs[1];
			free(sm_bs);
		}
	}
	last_push(sta, stb);
}

// sort() will find the lowsest 4 values, pushing the rest to b
// then sort4, we could potentially implement this to sort 5 items
void	sort(t_list **sta)
{
	t_list	*stb = NULL;
	int		*sm_as; /*smallest in stack A*/
	int		*sm_bs; /*smallest in stack B*/

	sm_as = find_n_smallest(*sta, 4);
	// ft_printf("sm_as: %d, %d, %d, %d\n", sm_as[0], sm_as[1], sm_as[2], sm_as[3]);
	if (!sm_as)
		return;
	while (ft_lstsize(*sta) > 4)
	{
		if (!is_in_smallest(ft_atoi((*sta)->ct), sm_as, 4))
			ptob(sta, &stb);
		else
			ra(sta);
	}
	free(sm_as);
	sm_bs = find_n_smallest(stb, 2);
	sort4ord(sta, &stb);
	find_next(sm_bs, sta, &stb);
	ft_printf("STA after find_next:\n");
	print_stack(*sta);/********* */
	free(sm_bs);
	// NOTE THAT last_push is now in find_next
	// last_push(sta, &stb); /*may need last in reverse order then ptoa and ra*/
}

void start_sort(t_list **sta)
{
	if (!sta || !*sta)
		return ;
	if (ft_lstsize(*sta) == 2)
		sa(sta);
	else if (ft_lstsize(*sta) == 3)
		sort3(sta);
	else if (ft_lstsize(*sta) == 4)
		sort4(sta);
	else if (ft_lstsize(*sta) > 4)
		sort(sta);
}
