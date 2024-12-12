/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:57:54 by ekosnick          #+#    #+#             */
/*   Updated: 2024/12/12 09:31:54 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **sta)
{
	t_list	*first;
	t_list	*second;
	
	if (!sta || !*sta || !(*sta)->next)
		return ;
	first = *sta;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*sta = second;
	write(1, "sa\n", 3);
}

void	sb(t_list **stb)
{
	t_list	*first;
	t_list	*second;
	
	if (!stb || !*stb || !(*stb)->next)
		return ;
	first = *stb;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stb = second;
	write(1, "sb\n", 3);
}

void	ss(t_list **sta, t_list **stb)
{
	if (sta && *sta && (*sta)->next)
		sa(sta);
	if (stb && *stb && (*stb)->next)
		sb(stb);
	write(1, "ss\n", 3);
}