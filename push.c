/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:55:45 by ekosnick          #+#    #+#             */
/*   Updated: 2024/12/12 09:32:02 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ptoa(t_list **sta, t_list **stb)
{
	push(stb, sta);
	write(1, "pa\n", 3);
}

void	ptob(t_list **sta, t_list **stb)
{
	push(sta, stb);
	write(1, "pb\n", 3);
}

void	push(t_list **src, t_list **dst)
{
	t_list	*temp;
	
	if (!src || !*src)
		return ;
	temp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = temp;
}
