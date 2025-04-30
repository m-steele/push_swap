/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:51:11 by peatjohnsto       #+#    #+#             */
/*   Updated: 2025/04/30 07:07:29 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// valgrind --leak-check=full --track-origins=yes ./push_swap
// ARG="16 5 10 8 12 1 11 6 19 4 15 9 14 7 13 2 18 3 20 17"; ./push_swap $ARG | ./checker_linux $ARG
// 16 5 10 8 12 1 11 6 19 4 15 9 14 7 13 2 18 3 20 17
// 5 24 421 9 78 1 549 -41 54 101 38 389 -12 -1 87 999 15882 4 74 45 20 3 14
// 5 2 4 9 22 54 41 8 1 89 11 87 21 23 25 46 123 321 5412 84 151 -5 -1 -8
// valgrind --leak-check=full --track-origins=yes ./push_swap 16 88 10 8 12 1 111 6 19 4 -55 15 9 14 7 -11 13 2 18 3 20 17 100 55 44 31 -5 29 -8 201 -2 11 5 666 0 25 26 30 -15684 42 -545 32
// 16 88 10 8 12 1 111 6 19 4 97 98 99 100 90 91 92 93 94 0 5

// ARG="157 213 48 229 5 269 15 238 266 135 152 286 119 279 99 71 101 300 228 220 192 233 40 165 84 249 153 75 69 43 178 262 183 102 261 271 77 275 289 55 250 246 234 270 294 60 49 197 108 212 110 25 123 134 12 82 78 196 206 117 259 282 149 24 267 276 139 198 94 167 17 89 257 154 297 144 142 143 211 136 200 145 36 160 87 164 44 31 38 72 95 222 278 174 203 173 244 274 11 115 272 79 120 103 218 171 16 170 245 166 243 199 107 205 248 163 98 293 100 88 225 182 83 239 255 9 219 179 91 169 180 93 28 291 287 68 26 47 61 59 27 92 20 188 96 235 32 155 33 65 181 216 148 14 53 190 29 131 109 23 141 273 156 41 209 21 172 112 290 247 176 52 56 70 90 263 73 191 121 285 30 63 113 46 299 193 187 45 283 230 64 201 127 151 66 6 207 168 35 125 215 162 126 147 8 137 253 7 202 232 1 76 4 292 106 217 50 224 277 133 105 296 54 204 104 58 241 62 208 37 122 214 185 97 111 231 237 258 264 150 226 51 268 210 177 223 39 256 80 284 195 81 132 -25 186 260 22 85 118 242 -54 114 184 57 74 130 221 138 3 -7 13 86 2 19 18 140 146 158 265 159 251 128 281 34 240 42 175 116 -100 280 67 295 -11 236 161 254 189 10 288 227 194 298 124 129 252 -1"; ./push_swap $ARG | ./checker_linux $ARG



// https://github.com/o-reo/push_swap_visualizer
// ..push_swap/visualizer/build$ ./bin/visualizer

/*Prints the stack in order from left to write
then provides the Total count of items, indented*/
void	print_stack(t_list *sta)
{
	int n;
	
	n = 0;
	while (sta)
	{
		ft_printf("%s, ", sta->ct);
		sta = sta->nt;
		n++;
	}
	ft_printf("\n  Total: %d\n", n);
}

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

// THis will check if the stack is sorted invertedly
int inverted(t_list *st)
{
	if (!st || !st->nt)
		return (1);
	while (st && st->nt)
	{
		if (ft_atoi(st->ct) > ft_atoi(st->nt->ct))
			return (0);
		st = st->nt;
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

t_list	*fill_stack(char **nums, int len)
{
	t_list	*sta;
	t_list	*new_node;

	sta = NULL;
	while (len--)
	{
		new_node = ft_lstnew(nums[len]);
		if (!new_node)
			clean_and_exit(nums, len, sta, 1);
		new_node->index = 0; // Initialize index
		ft_lstadd_front(&sta, new_node);
	}
	return (sta);
}

int	main(int subitizer, char **beans)
{
	int		len;
	char	**nums; /*may handle this differently in future*/
	t_list	*sta;
	t_list	*stb;

	if (subitizer > 1)
	{
		len = process_beans(&nums, beans + 1, " ");
		if (!len || not_valid(nums))
		{
			ft_printf("Error\n");
			clean_and_exit(nums, len, NULL, 1);
		}
		sta = fill_stack(nums, len);
		stb = NULL;
		if (!sorted(sta))
			start_sort(&sta, &stb); /*THIS IS WHERE THE REAL FUN WILL BE*/
		ft_lstclear(&sta, free);
		ft_lstclear(&stb, free);
		stb = NULL; /*not sure that we really need this...*/
		sta = NULL; /*not sure that we really need this...*/
		free(nums);	/*we need to keep this*/
	}
	return (0);
}
