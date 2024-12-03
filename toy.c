
// 1. Make libft in its directory
// 2. Make pushtoy.a in push_swap directory
// 3. ./pushtoy.a 5 8 1 6 45 8

// valgrind --leak-check=full ./pushtoy.a 1 2 5 4

#include "/home/peatjohnston/_42/github/libft/libft.h"

// This appends the new node to end of last node
void	append_node(t_list	**top, char	*content)
{
	t_list	*new_node = ft_lstnew(content);
	if (!new_node)
		return ;
	if (!*top)
	{
		*top = new_node;
		return ;
	}
	t_list	*temp = *top;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new_node;
}

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (ft_atoi(stack->content) > ft_atoi(stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int i = 1;
	if (argc < 2)
	{
		ft_printf("Too small: %s\n", argv[0]);
		return (1);
	}
	t_list	*stack = NULL;
	while (i < argc)
	{
		append_node(&stack, argv[i]);
		i++;
		// ft_printf("%s\n", beans[i]);
	}
	ft_printf("is sorted: %d\n", is_sorted(stack));
	t_list		*temp = stack;
	int count = 0;
	int monkey = 3; /*used to print out a specific node*/
	while (temp && count < monkey - 1)
	{
		temp = temp->next;
		count++;
	}
	if (temp)
			ft_printf("This is Node %d: %s\n", monkey, temp->content);
	else
		ft_printf("Less than %d Nodes\n", monkey);
	while (stack)
		{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (0);
}
