/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:51:11 by peatjohnsto       #+#    #+#             */
/*   Updated: 2025/01/10 11:11:29 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// valgrind --leak-check=full --track-origins=yes ./push_swap  5 24 421 9 78 1 549 -41 54 101 38 389 -12 -1 87 999 15882 4 74 45
// ARG="5 2 4 9 22 54 41 8 1 89 11 87 21 23 25 46 123 321 5412 84 151 -5 -1 -8"; ./push_swap $ARG | ./checker_linux $ARG

// NEW ISSUE 20240110: checker_linux does not work at home...

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

	if (!beans || !*beans || !delim || !nums)
		return (0);
	joined = ft_strdup(*beans++); /*pre-processing the beans*/
	if (!joined)
		return (0);
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
	if (!*nums)
		return (0);
	i = 0;
	while ((*nums)[i])
		i++;
	return (i);
}

// int	main(int subitizer, char **beans)
// {
// 	int		len;
// 	char	**nums;
// 	t_list	*sta;
// 	t_list	*new_node;

// 	if (subitizer > 1)
// 	{
// 		len = process_beans(&nums, beans + 1, " ");
// 		if (!len || not_valid(nums))
// 			clean_and_exit(nums, len, NULL, 1);
// 		ft_printf("Number of Items: %d\n", len); /*This is my counter remove for final*/
// 		sta = NULL;
// 		while (len--)
// 		{
// 			new_node = ft_lstnew(nums[len]);
// 			if (!new_node)
// 				clean_and_exit(nums, len, sta, 1);
// 			ft_lstadd_front(&sta, new_node);
// 		}
// 		// ft_printf("A: %s %s %s %s %s %s %s %s\n", (sta)->ct, (sta)->nt->ct, (sta)->nt->nt->ct, (sta)->nt->nt->nt->ct, (sta)->nt->nt->nt->nt->ct, (sta)->nt->nt->nt->nt->nt->ct, (sta)->nt->nt->nt->nt->nt->nt->ct, (sta)->nt->nt->nt->nt->nt->nt->nt->ct);
// 		if (!sorted(sta))
// 			start_sort(&sta); /*THIS IS WHERE THE REAL FUN WILL BE*/
// 		ft_lstclear(&sta, free);
// 		free(nums);	/*we need to keep this*/
// 		// sta = NULL; /*not sure that we really need this...*/
// 	}
// 	return (0);
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
		// ft_printf("A: %s %s %s %s %s %s %s %s\n", (sta)->ct, (sta)->nt->ct, (sta)->nt->nt->ct, (sta)->nt->nt->nt->ct, (sta)->nt->nt->nt->nt->ct, (sta)->nt->nt->nt->nt->nt->ct, (sta)->nt->nt->nt->nt->nt->nt->ct, (sta)->nt->nt->nt->nt->nt->nt->nt->ct);
		if (!sorted(sta))
			start_sort(&sta); /*THIS IS WHERE THE REAL FUN WILL BE*/
		ft_lstclear(&sta, free);
		free(nums);	/*we need to keep this*/
		// sta = NULL; /*not sure that we really need this...*/
	}
	return (0);
}
