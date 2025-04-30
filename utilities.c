/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:33:56 by ekosnick          #+#    #+#             */
/*   Updated: 2025/04/30 12:45:12 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this will check if the stack is already sorted
int	sorted(t_list *sta)
{
	if (!sta || !sta->nt)
		return (1);
	while (sta && sta->nt)
	{
		if (ft_atoi(sta->ct) > ft_atoi(sta->nt->ct))
			return (0);
		sta = sta->nt;
	}
	return (1);
}

// THis will check if the stack is sorted invertedly
int	inverted(t_list *st)
{
	if (!st || !st->nt)
		return (1);
	while (st && st->nt)
	{
		if (ft_atoi(st->ct) > ft_atoi(st->nt->ct))
			return (0);
		st = st->nt;
	}
	return (1);
}

void	find_pos(t_list **st)
{
	t_list	*tmp;
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
	if (tget_id != -1)
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

void	id_target(t_list **sta, t_list **stb)
{
	t_list	*tmpb;
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
}
