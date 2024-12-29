/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:51:11 by peatjohnsto       #+#    #+#             */
/*   Updated: 2024/12/29 09:41:24 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// valgrind --leak-check=full --track-origins=yes ./push_swap 5 2 4 9

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

void clean_and_exit(char **nums, int i, t_list *sta, int exit_code)
{
	if (nums)
		freeme(nums, i - 1);
	if (sta)
		ft_lstclear(&sta, free);
	exit(exit_code);
}

	// this will check if the stack is already sorted
int sorted(t_list *sta)
{
	if (!sta || !sta->nt)
		return (1);
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
	t_list	*new_node;

	if (subitizer > 1)
	{
		len = process_beans(&nums, beans + 1, " ");
		if (!len || not_valid(nums))
			clean_and_exit(nums, len, NULL, 1);
		ft_printf("Number of Items: %d\n", len); /*This is my counter remove for final*/
		sta = NULL;
		while (len--)
		{
			new_node = ft_lstnew(nums[len]);
			if (!new_node)
				clean_and_exit(nums, len, sta, 1);
			ft_lstadd_front(&sta, new_node);
		}
		// free(nums);	/*we may need to keep this in the end*/
		if (!sorted(sta))
			start_sort(&sta); /*THIS IS WHERE THE REAL FUN WILL BE*/
		ft_lstclear(&sta, free);
		// sta = NULL; /*not sure that we really need this...*/
	}
	return (0);
}

// ORIGINAL MAIN() THAT USED TO WORK...
// int	main(int subitizer, char **beans)
// {
// 	int		len;
// 	char	**nums;
// 	t_list	*sta;

// 	if (subitizer > 1)
// 	{
// 		len = 0; /*NOTE this is your MAX value of counted numbers*/
// 		len = process_beans(&nums, beans + 1, " ");
// 		if (!len || not_valid(nums))
// 		{
// 			freeme(nums, len);
// 			ft_printf("Error\n");
// 			return (1);
// 		}
// 		ft_printf("Number of Items: %d\n", len);
// 		sta = 0;
// 		while (len--)
// 			ft_lstadd_front(&sta, ft_lstnew(nums[len]));
// 		if (!sorted(sta))
// 			start_sort(&sta); /*THIS IS WHERE THE REAL FUN WILL BE*/
// 		ft_lstclear(&sta, free);
// 		free(nums);
// 	}
// 	return (0);
// }
