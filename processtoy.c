/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processtoy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:51:11 by peatjohnsto       #+#    #+#             */
/*   Updated: 2024/12/09 10:53:54 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "/home/peatjohnston/_42/github/libft/libft.h"

// cleanup function
static char **freeme(char **nums, int index)
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
	while (sta && sta->next)
	{
		if (ft_atoi(sta->content) > ft_atoi(sta->next->content))		
			return (0);
		sta = sta->next;
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
	joined = ft_strdup(*beans++);
	while (*beans)
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

// {
// 	char	*joined;
// 	char	*temp;
// 	int		i;

// 	if (!beans || !*beans || !delim)
// 		return (0);
// 	joined = ft_strdup("");
// 	if (!joined)
// 		return (0);
// 	while (*beans)
// 	{
// 		temp = joined;
// 		if (*joined)
// 		{
// 			joined = ft_strjoin(joined, delim);
// 			free(temp);
// 			temp = joined;
// 		}
// 		joined = ft_strjoin(joined, *beans++);
// 		free(temp);
// 		if (!joined)
// 			return (0);
// 	}
// 	*nums = ft_split(joined, ' ');
// 	free (joined);
// 	i = 0;
// 	while ((*nums)[i])
// 		i++;
// 	return (i);
// }


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
		// for (int i = 0; nums[i] !=NULL; i++)
		// 	ft_printf("Num[%d]: [%s]\n", i, nums[i]);
		// ft_printf("Beans: ");
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
			return (ft_printf("NOT SORTED\n"));
			// push_swap(&sta); /*THIS IS WHERE THE REAL FUN WILL BE*/
		ft_lstclear(&sta, free);
		free(nums);
	}
	return (0);
}
