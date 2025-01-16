/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:04 by ekosnick          #+#    #+#             */
/*   Updated: 2025/01/15 18:12:40 by ekosnick         ###   ########.fr       */
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

/*TEN	TEN	TEN	TEN		TEN	TEN*/

void	sort(t_list **sta)
{
	int		*sm_as; /*the n smallest values in stack A*/
	t_list	*stb = NULL;

	sm_as = find_n_smallest(*sta, ft_lstsize(*sta));
	int n = ft_lstsize(*sta);
	ft_printf("sm_as --> (lstsize): %d\n", n);
	ft_printf("sm_as: %d, %d, %d, %d, %d\n", sm_as[0], sm_as[1], sm_as[2], sm_as[3], sm_as[4]);
	sort_10_ina(sta, stb);
			free(sm_as);
	while (stb)
		ptoa(sta, &stb);
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
	else if (lstsize > 4)
		sort(sta);
}

/*TEN	TEN	TEN	TEN		TEN	TEN*//*TEN	TEN	TEN	TEN		TEN	TEN*/