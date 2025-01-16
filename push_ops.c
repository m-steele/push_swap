/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:19:14 by ekosnick          #+#    #+#             */
/*   Updated: 2025/01/16 10:29:24 by ekosnick         ###   ########.fr       */
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

	sm_as = find_n_smallest(*sta, 2);
	if (!sm_as)
		return;
	while (!all_smalls_ptob(*sta, sm_as, 2)) 	/*while (ft_lstsize(*sta) > n + 1)*/
	{
		int current_value = ft_atoi((*sta)->ct);
		// ft_printf("Current value top of STA: %d\n", current_value);
		if (is_in_smallest(current_value, sm_as, 2))
			ptob(sta, &stb);
		else
			ra(sta);
	}
	ft_printf("Start SORT_3():\n");
	sort3(sta);
	ptoa(sta, &stb);
	ptoa(sta, &stb);
	if (ft_atoi((*sta)->ct) > ft_atoi((*sta)->nt->ct))
		sa(sta);
	free(sm_as);	
}

void sort_10_ina(t_list **sta, t_list *stb)
{
	int		*sm_as; /*the n smallest values in stack A*/
	int		n;

	sm_as = find_n_smallest(*sta, 5);
	if (!sm_as)
		return ;
	while (!all_smalls_ptob(*sta, sm_as, 5)) 	/*while (ft_lstsize(*sta) > n + 1)*/
	{
		if (is_in_smallest(ft_atoi((*sta)->ct), sm_as, 5))
			ptob(sta, &stb);
		else
			ra(sta);
	}
	ft_printf("Start SORT_5():\n");
	sort_5_ina(sta, stb);
	n = ft_lstsize(stb);

// GREAT, THIS IS WHERE WE WANT TO BE AT LEAST FOR NOW. WHAT WE NEED FROM HERE
// IS A SURE WAY TO SORT FIVE FROM B TO A. i BELEIVE THE SORT 5 IN A IS WORKING FINE
// WE JUST HAVE TO IMPLEMENT THE SAME LOGIC GETTING NUMBERS FROM STACK B TO A
	
	while (n > 0)
	{
		if (ft_atoi((*sta)->ct) > ft_atoi((*sta)->nt->ct))
			sa(sta);
		if (stb)
			ptoa(sta, &stb);
		n--;
	}
	free(sm_as);
}
