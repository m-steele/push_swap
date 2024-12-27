/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:57:54 by ekosnick          #+#    #+#             */
/*   Updated: 2024/12/27 12:45:38 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **sta)
{
	t_list	*first;
	t_list	*second;
	
	if (!sta || !*sta || !(*sta)->nt)
		return ;
	first = *sta;
	second = first->nt;
	first->nt = second->nt;
	second->nt = first;
	*sta = second;
	write(1, "sa\n", 3);
}

void	sb(t_list **stb)
{
	t_list	*first;
	t_list	*second;
	
	if (!stb || !*stb || !(*stb)->nt)
		return ;
	first = *stb;
	second = first->nt;
	first->nt = second->nt;
	second->nt = first;
	*stb = second;
	write(1, "sb\n", 3);
}

void	wsa(t_list **sta)
{
	t_list	*first;
	t_list	*second;
	
	if (!sta || !*sta || !(*sta)->nt)
		return ;
	first = *sta;
	second = first->nt;
	first->nt = second->nt;
	second->nt = first;
	*sta = second;
}

void	wsb(t_list **stb)
{
	t_list	*first;
	t_list	*second;
	
	if (!stb || !*stb || !(*stb)->nt)
		return ;
	first = *stb;
	second = first->nt;
	first->nt = second->nt;
	second->nt = first;
	*stb = second;
}

void	ss(t_list **sta, t_list **stb)
{
	if (sta && *sta && (*sta)->nt)
		wsa(sta);
	if (stb && *stb && (*stb)->nt)
		wsb(stb);
	write(1, "ss\n", 3);
}