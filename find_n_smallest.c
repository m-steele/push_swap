/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_n_smallest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:33:11 by ekosnick          #+#    #+#             */
/*   Updated: 2025/04/10 11:44:45 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sm_array(int *smallest, int n)
{
	int	i;

	i = 0;
	while (i < n)
		smallest[i++] = INT_MAX;
}

void	sm_array(int *smallest, int n, int val)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		if (val < smallest[i])
		{
			j = n - 1;
			while (j > i)
			{
				smallest[j] = smallest[j - 1];
				j--;
			}
			smallest[i] = val;
			break;
		}
		i++;
	}
}

// returns an 'n' number of the lowest ints in an array 
int	*find_n_smallest(t_list *sta, int n)
{
	int	*smallest;
	int	val;

	smallest = malloc(sizeof(int) * n);
	if (!smallest)
		return (NULL);
	init_sm_array(smallest, n);
	while (sta)
	{
		val = ft_atoi(sta->ct);
		sm_array(smallest, n, val);
		sta = sta->nt;
	}
	return (smallest);
}

// Helper function to check if a value is among the smallest
int	is_in_smallest(int value, int *smallest, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (value == smallest[i])
			return (1);
		i++;
	}
	return (0);
}