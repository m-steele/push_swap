
// 1. Make libft in its directory
// 2. make pushtoy.a in push_swap directory
// 3. Compile as such:
// cc -Wall -Wextra -Werror toy.c pushtoy.a ~/_42/github/libft/libft.a
// Noting that you have to include libft.a as well as pushtoy.a
// 4. ./a.out 5 8 1 6 45 8

#include "/home/peatjohnston/_42/github/libft/libft.h"

// int main(int argc, char **argv)
// {
// 	int i = 0;
// 	ft_printf("Count of numbers: %d\n", argc);
// 	while (i < argc - 1)
// 	{
// 		i++;
// 		ft_printf("Count %d: %s\n", i, argv[i]);
// 	}
// return (0);
// }

int main(int subitizer, char **beans)
{
	int i = 0;

	ft_printf("%d\n", i);
	while (i < subitizer)
	{
		i++;
		ft_printf("%s\n", beans[3]);
	}
	return (0);
}
