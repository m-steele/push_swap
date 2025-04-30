/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_n_biggest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:33:11 by ekosnick          #+#    #+#             */
/*   Updated: 2025/04/30 11:25:03 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bg_array(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		arr[i++] = INT_MIN;
}

void	bg_array(int *arr, int n, int val)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		if (val > arr[i])
		{
			j = n - 1;
			while (j > i)
			{
				arr[j] = arr[j - 1];
				j--;
			}
			arr[i] = val;
			break ;
		}
		i++;
	}
}

int	*f_n_b(t_list *sta, int n)
{
	int	*biggest;
	int	val;

	biggest = malloc(sizeof(int) * n);
	if (!biggest)
		return (NULL);
	init_bg_array(biggest, n);
	while (sta)
	{
		val = ft_atoi(sta->ct);
		bg_array(biggest, n, val);
		sta = sta->nt;
	}
	return (biggest);
}

// Helper function to check if a value is among the biggest
int	inb(int value, int *biggest, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (value == biggest[i])
			return (1);
		i++;
	}
	return (0);
}
