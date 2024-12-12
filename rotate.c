/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:58:23 by ekosnick          #+#    #+#             */
/*   Updated: 2024/12/11 16:52:08 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **sta)
{
	t_list	*first;
	t_list	*last;

	if (!sta || !*sta || !(*sta)->next)
		return ;
	first = *sta;
	*sta = first->next;
	first->next = NULL;
	last = *sta;
	while (last->next)
		last = last->next;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_list **stb)
{
	t_list	*first;
	t_list	*last;

	if (!stb || !*stb || !(*stb)->next)
		return ;
	first = *stb;
	*stb = first->next;
	first->next = NULL;
	last = *stb;
	while (last->next)
		last = last->next;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rr(t_list **sta, t_list **stb)
{
	if (sta && *sta && (*sta)->next)
		ra(sta);
	if (stb && *stb &&(*stb)->next)
		rb(stb);
	write(1, "rr\n", 3);
}