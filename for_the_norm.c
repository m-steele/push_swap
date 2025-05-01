/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_the_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 07:45:02 by ekosnick          #+#    #+#             */
/*   Updated: 2025/05/01 07:46:40 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// cleanup function
char	**freeme(char **nums, int i)
{
	if (!nums)
		return (NULL);
	while (i >= 0)
		free(nums[i--]);
	free(nums);
	return (NULL);
}

void	clean_and_exit(char **nums, int i, t_list *sta, int exit_code)
{
	if (nums)
		freeme(nums, i - 1);
	if (sta)
		ft_lstclear(&sta, free);
	exit(exit_code);
}

void	fin_ptob(t_list **sta, t_list **stb, int s_size, int pushed)
{
	int		*bg_as;

	bg_as = f_n_b(*sta, 1);
	while (s_size - pushed > 3)
	{
		if (inb(ft_atoi((*sta)->ct), bg_as, 1))
			ra(sta);
		else
		{
			ptob(sta, stb);
			pushed++;
		}
	}
	free(bg_as);
}

void	first_ptob(t_list **sta, t_list **stb)
{
	int		*sm_as;
	int		s_size;
	int		pushed;

	s_size = ft_lstsize(*sta);
	sm_as = find_n_smallest(*sta, s_size / 2);
	pushed = 0;
	while (s_size > 5 && pushed < s_size / 2)
	{
		if (is_in_smallest(ft_atoi((*sta)->ct), sm_as, s_size / 2))
		{
			ptob(sta, stb);
			pushed++;
		}
		else
			ra(sta);
	}
	free(sm_as);
	fin_ptob(sta, stb, s_size, pushed);
}
