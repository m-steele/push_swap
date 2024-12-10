/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:51:11 by peatjohnsto       #+#    #+#             */
/*   Updated: 2024/12/07 13:47:32 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

// cleanup function
static char **freeme(char **str, int idx)
{
	while (index >= 0)
		free(str[idx--]);
	free (str);
	return (NULL);
}

	// this will check if the stack is already sorted
sorted(t_list sta)
{

	while (t_list->content > t_list->next)
		t_list = t_list->next;
}

// turns argv statment into string of numbers we can work with
// and returns a count of the numbers of beans
int	process_beans(char ***nums, char **beans, char *delim)
{
	char	*joined;
	char	*temp;
	int		i;

	if (!beans || !*beans || !delim)
		return (NULL)
	joined = ft_strdup(*beans++)
	while (*beans)
	{
		temp = ft_strjoin(joined, delim);
		free(joined);
		joined = ft_strjoin(temp, *beans++);
		free(temp);
	}
	*nums = ft_split(joined, *delim);
	free (joined);
	i = 0;
	while ((*nums)[i])
		i++;
	return (i);
}

not_valid(*beans)
{
	// check if there is anything not sortable
	// like letters or words
}

ft_sm_sort(char *beans)
{
	
	
}
// this will init the sorting of largers sets
ft_sorter(t_list stk_a, t_list stk_b)
{

}

int	main(int subitizer, char **beans)
{
	int		len;
	char	**nums;
	t_list	*sta;
	
	if (subitizer > 1)
	{
		len = 0;
		len = process_beans(&nums, beans + 1, " ");
		if (!len || !not_valid(nums))
		{
			freeme(nums);
			ft_printf("Error");
			return (1);
		}
	}
	
	if (not_valid(*beans))
	
	if (subitizer = 2)
		return (0);
	while (*beans++)
	{
		if (!ft_atoi(*beans))
			return (0);
	}
	
	while (!sorted(sta))
	{
		ft_sorter(stk_a, stk_b);
	}
	return (-1);
}
