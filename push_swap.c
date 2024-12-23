/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:51:11 by peatjohnsto       #+#    #+#             */
/*   Updated: 2024/12/23 10:50:12 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// cleanup function
char **freeme(char **nums, int index)
{
	if (!nums)
		return (NULL);
	while (index >= 0)
		free(nums[index--]);
	free (nums);
	return (NULL);
}

	// this will check if the stack is already sorted
int sorted(t_list *sta)
{
	while (sta && sta->nt)
	{
		if (ft_atoi(sta->ct) > ft_atoi(sta->nt->ct))		
			return (0);
		sta = sta->nt;
	}
	return (1);
}

// turns argv (beans) statment into string of numbers (nums) we can
// work with and returns a count of the numbers of beans
int	process_beans(char ***nums, char **beans, char *delim)
{
	char	*joined;
	char	*temp;
	int		i;

	if (!beans || !*beans || !delim)
		return (0);
	joined = ft_strdup(*beans++); /*pre-processing the beans*/
	while (*beans) /*pointing to second position*/
	{
		temp = ft_strjoin(joined, delim);
		free(joined);
		if (!temp)
			return (0);
		joined = ft_strjoin(temp, *beans++);
		free(temp);
		if (!joined)
			return (0);
	}
	*nums = ft_split(joined, *delim);
	free (joined);
	i = 0;
	while ((*nums)[i])
		i++;
	return (i);
}
// TOO LONG:
// {
//     char    *joined;
//     char    *temp;
//     int     i;

//     if (!beans || !*beans || !delim)
//         return (0);
//     joined = ft_strdup(""); // Start with an empty string
//     if (!joined)
//         return (0);
//     while (*beans)
//     {
//         temp = ft_strjoin(joined, *beans); // Append the current argument
//         free(joined);
//         if (!temp)
//             return (0);
//         joined = temp;
//         if (*(beans + 1)) // Add the separator if there are more arguments
//         {
//             temp = ft_strjoin(joined, delim);
//             free(joined);
//             if (!temp)
//                 return (0);
//             joined = temp;
//         }
//         beans++;
//     }
//     *nums = ft_split(joined, *delim); // Split the concatenated string
//     free(joined);
//     i = 0;
//     while ((*nums)[i]) // Count the resulting strings
//         i++;
//     return (i);
// }

int	main(int subitizer, char **beans)
{
	int		len;
	char	**nums;
	t_list	*sta;

	// for (int i = 0; beans[i] !=NULL; i++)
	// 	ft_printf("Num[%d]: [%s]\n", i, beans[i]);
	if (subitizer > 1)
	{
		len = 0;
		len = process_beans(&nums, beans + 1, " ");
		if (!len || not_valid(nums))
		{
			freeme(nums, len);
			ft_printf("Error\n");
			return (1);
		}
		sta = 0;
		while (len--)
			ft_lstadd_front(&sta, ft_lstnew(nums[len]));
		if (!sorted(sta))
			start_sort(&sta); /*THIS IS WHERE THE REAL FUN WILL BE*/
		ft_lstclear(&sta, free);
		free(nums);
	}
	return (0);
}
