/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:19:14 by ekosnick          #+#    #+#             */
/*   Updated: 2025/01/13 09:59:54 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_in_pos(t_list	*sta, int target)
{
	t_list	*curr;
	int		pos;
	int		size;

	if (!sta || !sta->nt)
		return (0);
	pos = 0;
	size = ft_lstsize(sta);
	curr = sta;
	while (curr && curr->nt)
	{
		if (ft_atoi(curr->ct) < target && target < ft_atoi(curr->nt->ct))
			return (pos + 1);
		curr = curr->nt;
		pos++;
	}
// if target is smaller or larger than all it goes to the end
	if(target < ft_atoi(sta->ct) || target > ft_atoi(ft_lstlast(sta)->ct))
		return (size);
	return(0);
}

void	push_into_pos(t_list **sta, int pos)
{
	int	size;
	
	size = ft_lstsize(*sta);
	if(pos <= size / 2)
		while (pos-- > 0)
			ra(sta);
	else
		while (pos++ < size)
			rra(sta);
}

void	push_ops(t_list **sta, t_list **stb)
{
	int	target;
	int	pos;

	if (!stb || !*stb)
		return ;
	target = ft_atoi((*stb)->ct);
	pos = find_in_pos(*sta, target);
	push_into_pos(sta, pos);
	ptoa(sta, stb);
}