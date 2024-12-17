/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:58:23 by ekosnick          #+#    #+#             */
/*   Updated: 2024/12/17 13:16:58 by ekosnick         ###   ########.fr       */
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

void	rb_no_write(t_list **stb)
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
}

void	ra_no_write(t_list **sta)
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
}

void	rr(t_list **sta, t_list **stb)
{
	if (sta && *sta && (*sta)->next)
		ra_no_write(sta);
	if (stb && *stb &&(*stb)->next)
		rb_no_write(stb);
	write(1, "rr\n", 3);
}