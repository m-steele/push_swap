/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_n_biggest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:33:11 by ekosnick          #+#    #+#             */
/*   Updated: 2025/01/12 10:04:26 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// NOTE WE NEED TO CHANGE THE LOGIC SO THAT THE LARGEST OF THE STACK ARE FOUND
// AT THE MOMENT IT IS SET FOR THE SMALLEST --SEE BELOW

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
			break;
		}
		i++;
	}
}

int	*find_n_biggest(t_list *sta, int n)
{
	int	*biggest;
	int	val;

	biggest = malloc(sizeof(int) * n);
	if (!biggest)
		return (NULL);
	init_bg_array(biggest, n);/* Initialize the array with INT_MIN */
	while (sta)
	{
		val = ft_atoi(sta->ct);
		bg_array(biggest, n, val);/* Insert the value if it is among the n biggest */
		sta = sta->nt;
	}
	int i = 0;
	ft_printf("Biggest: ");
	while (i < n)
	{
		ft_printf("%d ", biggest[i]);
		i++;
	}
	ft_printf("\n");
	return (biggest);
}

// Helper function to check if a value is among the smallest
int	is_in_biggest(int value, int *biggest, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (value == biggest[i])
			return (1);
		i++;
	}
	return (0);
}