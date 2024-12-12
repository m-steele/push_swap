/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:13:30 by ekosnick          #+#    #+#             */
/*   Updated: 2024/12/11 14:13:30 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_valid(const char *nums)
// {
// 	long	num;
// 	int		sign;
// 	int		i;

// 	if (!nums || !*nums)
// 		return (0);
// 	sign = 0;
// 	if (*nums == '-' || *nums == '+')
// 		sign = 1;
// 	if (sign && !ft_isdigit(nums[sign]))
// 		return (0);
// 	num = 0;
// 	i = sign;
// 	while (nums[i] != '\0')
// 	{
// 		if (!ft_isdigit(nums[i]))
// 			return (0);
// 		num = num * 10 + (nums[i++] - '0');
// 		if (num > INT_MAX && *nums != '-')
// 			return (0);
// 		if (num > (long)INT_MAX + 1 && *nums == '-')
// 			return (0);
// 		i++;
// 	}
//  	return (1);
// }

{
	long	num;
	int		sign;
	int		i;

	if (!nums ||!*nums)
		return (0);
	sign = (*nums == '-' || *nums =='+');
	i = sign;
	if (!ft_isdigit(nums[i]))
		return (0);
	num = 0;
	while (nums[i])
	{
		if (!ft_isdigit(nums[i]))
			return (0);
		num = num *  + (nums[i++] - '0');
		if (num > INT_MAX && *nums != '-')
			return (0);
		if (num > (long)INT_MAX + 1 && *nums == '-')
			return (0);
	}
	return (1);
}

static int duplicates(char **nums)
{
	int	i;
	int	j;
	
	i = 0;
	while (nums[i] !=NULL)
	{
		j = i + 1;
		while (nums[j] != NULL)
		{
			if (ft_atoi(nums[i]) == ft_atoi(nums[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int not_valid(char **nums)
{
	int	i;

	i = 0;
	if (!nums || !*nums)
		return (1);
	while (nums[i])
	{
		if (!is_valid(nums[i]))
			return (1);
		i++;
	}
	return (duplicates(nums));
}
