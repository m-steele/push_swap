/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   betterstartsort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:04 by ekosnick          #+#    #+#             */
/*   Updated: 2025/01/12 10:20:01 by ekosnick         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

// IDeas that may or may not be useful

// FIND SMALLEST COULD BE AS MANY n AS YOU WANT
#include "push_swap.h"

int	*find_n_smallest(t_list *sta, int n)
{
	int		*smallest;
	int 	val;
	int		i;
	int		j;

	smallest = malloc(sizeof(int) * n);
	if (!smallest)
		return (NULL);
	i = 0;
	while (i < n)
		smallest[i++] = INT_MAX;
	while (sta)
	{
		val = ft_atoi(sta->ct);
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

void	print_stack(t_list *sta)
{
	while (sta)
	{
		ft_printf("%s\n", sta->ct);
		sta = sta->nt;
	}
}

	// ft_printf("A: %s %s %s %s %s %s %s %s\n", (*sta)->ct, (*sta)->nt->ct, (*sta)->nt->nt->ct, (*sta)->nt->nt->nt->ct, (*sta)->nt->nt->nt->nt->ct, (*sta)->nt->nt->nt->nt->nt->ct, (*sta)->nt->nt->nt->nt->nt->nt->ct, (*sta)->nt->nt->nt->nt->nt->nt->nt->ct);
	// ft_printf("B: %s %s %s %s\n", (*stb)->ct, (*stb)->nt->ct, (*stb)->nt->nt->ct, (*stb)->nt->nt->nt->ct);

int	min_sta(t_list *sta)
{
	int	min;
	int	x;

	min = ft_atoi(sta->ct);
	while (sta)
	{
		x = ft_atoi(sta->ct);
		if (x < min)
			min = x;
		sta = sta->nt;
	}
	return(min);
}

// May not need a ranking function
t_list	*rank(t_list *sta)
{
	t_list	*rank_list;
	t_list	*new_node;
	t_list	*temp;
	int		rank;
	int		x;

	rank_list = NULL;
	while (sta)
	{
		rank = 0;
		temp = sta->nt;
		x = ft_atoi(sta->ct);
		while (temp)
		{
			if (ft_atoi(temp->ct) < x)
				rank++;
			temp = temp->nt;
		}
		new_node = ft_lstnew(ft_itoa(rank));
		if (!new_node)
		{
			ft_lstclear(&rank_list, free);
			return (NULL);
		}
		ft_lstadd_back(&rank_list, new_node);
		sta = sta->nt;
	}
	return (rank_list);
}
