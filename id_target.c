/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_target.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:47:41 by ekosnick          #+#    #+#             */
/*   Updated: 2025/04/23 19:51:36 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_tget(t_list **sta, int b_index, int tget_index, int tget_id)
{
	t_list	*tmpa;
	
	tmpa = *sta;
	while (tmpa)
	{
		if (tmpa->index > b_index && tmpa->index < tget_index)
		{
			tget_index = tmpa->index;
			tget_id = tmpa->pos;
		}
		tmpa = tmpa->nt;
	}
	if (tget_index != INT_MAX)
		return (tget_id);
	tmpa = *sta;	
	while (tmpa)
	{
		if (tmpa->index < tget_index)
		{
			tget_index = tmpa->index;
			tget_id = tmpa->pos;
		}
		tmpa = tmpa->nt;
	}
	return (tget_id);
}

void	find_pos(t_list **st)
{
	t_list *tmp;
	int		i;

	tmp = *st;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->nt;
		i++;
	}
}

void id_target(t_list **sta, t_list **stb)
{
	t_list *tmpb;
	int		target_id;
	
	tmpb = *stb;
	target_id = 0;
	find_pos(sta);
	find_pos(stb);
	while (tmpb)
	{
		target_id = find_tget(sta, tmpb->index, INT_MAX, target_id);
		tmpb->target = target_id;
		tmpb = tmpb->nt;
	}
	// ft_printf("target id: %d\n", target_id);
}

/*Assignign the cost for a and b moves */
void negotiate_price(t_list **sta, t_list **stb)
{
	t_list *tmpa;
	t_list *tmpb;
	int 	sizea;
	int 	sizeb;

	tmpb = *stb;
	tmpa = *sta;
	sizea = ft_lstsize(tmpa);/*do we really need to add tmpa?*/
	sizeb = ft_lstsize(tmpb);

	while (tmpb)
	{
		tmpb->costforb = tmpb->pos;
		if (tmpb->pos > sizeb / 2)
			tmpb->costforb = (sizeb - tmpb->pos) * -1;
		tmpb->costfora = tmpb->target;
		if (tmpb->target > sizea / 2)
			tmpb->costfora = (sizea - tmpb->target) * -1;
		// ft_printf("\ntmpbPOS = %d\n", tmpb->pos);
		// ft_printf("tmpTARGRET = %d\n", tmpb->target);
		// ft_printf("tmpCOST A = %d\n", tmpb->costfora);
		// ft_printf("tmpCOST B = %d\n", tmpb->costforb);
		tmpb = tmpb->nt;
	}
}

static void	rot_n_push(t_list **sta, t_list **stb, int *costa, int *costb)
{
	while (*costa)
	{
		if (*costa > 0)
		{
			ra(sta);
			(*costa)--;
		}
		else if (*costa < 0)
		{
			rra(sta);
			(*costa)++;
		}
	}
	while (*costb)
	{
		if (*costb > 0)
		{
			rb(stb);
			(*costb)--;
		}
		else if (*costb < 0)
		{
			rrb(stb);
			(*costb)++;
		}
	}
	ptoa(sta, stb);
}

/*Need to fix this and done????*/
// void	fin_sort(t_list **sta)
// {
// 	t_list	*tmpa;
	
// 	tmpa = *sta;
// 	if (!sorted(*sta))
// 	{
// 		while (*sta->ct > ft_lstlast(sta)
// 	}
	
// }

/*find cheapest move and ptoa*/
void	pay_cheapest(t_list **sta, t_list **stb)
{
	t_list *tmpb;
	int		costa;
	int		costb;
	int		m; /*the one to move*/

	tmpb = *stb;
	m = INT_MAX;
	while (tmpb)
	{
		if (ft_abs(tmpb->costfora) + ft_abs(tmpb->costforb) < ft_abs(m))
		{
			m = ft_abs(tmpb->costfora) + ft_abs(tmpb->costforb);
			costa = tmpb->costfora;
			costb = tmpb->costforb;
		}
		tmpb = tmpb->nt;
	}
	if (costa > 0 && costb > 0)
	{
		while (costa > 0 && costb > 0)
		{
			costa--;
			costb--;
			rr(sta, stb);
		}
	}
	else if (costa < 0 && costb < 0)
	{
		while (costa < 0 && costb < 0)
		{
			costa++;
			costb++;
			rrr(sta, stb);
		}
	}
	rot_n_push(sta, stb, &costa, &costb);
	// fin_sort(sta);
}