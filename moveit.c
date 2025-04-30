/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:47:41 by ekosnick          #+#    #+#             */
/*   Updated: 2025/04/30 12:36:46 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Assignign the cost for a and b moves */
void	negotiate_price(t_list **sta, t_list **stb)
{
	t_list	*tmpa;
	t_list	*tmpb;
	int		sizea;
	int		sizeb;

	tmpb = *stb;
	tmpa = *sta;
	sizea = ft_lstsize(tmpa);
	sizeb = ft_lstsize(tmpb);
	while (tmpb)
	{
		tmpb->costforb = tmpb->pos;
		if (tmpb->pos > sizeb / 2)
			tmpb->costforb = (sizeb - tmpb->pos) * -1;
		tmpb->costfora = tmpb->target;
		if (tmpb->target > sizea / 2)
			tmpb->costfora = (sizea - tmpb->target) * -1;
		tmpb = tmpb->nt;
	}
}

static void	rot_n_push_b(t_list **stb, int *costb)
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

static void	rot_n_push(t_list **sta, t_list **stb, int *costa, int *costb)
{
	while (*costb)
		rot_n_push_b(stb, costb);
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
	ptoa(sta, stb);
}

void	rr_and_rrr(t_list **sta, t_list **stb, int costa, int costb)
{
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
}

/*find cheapest m and ptoa*/
void	pay_cheapest(t_list **sta, t_list **stb)
{
	t_list	*tmpb;
	int		costa;
	int		costb;
	int		m;

	tmpb = *stb;
	m = INT_MAX;
	while (tmpb)
	{
		if (ft_abs(tmpb->costfora) + ft_abs(tmpb->costforb) < m)
		{
			m = ft_abs(tmpb->costfora) + ft_abs(tmpb->costforb);
			costa = tmpb->costfora;
			costb = tmpb->costforb;
		}
		tmpb = tmpb->nt;
	}
	if ((costa > 0 && costb > 0) || (costa < 0 && costb < 0))
		rr_and_rrr(sta, stb, costa, costb);
	else
		rot_n_push(sta, stb, &costa, &costb);
}
