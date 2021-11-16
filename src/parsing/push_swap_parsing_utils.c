/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:17:09 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/11/16 16:17:12 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_error_args(char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (only_whitespace(argv))
		return (0);
	while (argv[i])
	{
		j = 0;
		while (ft_isdigit(argv[i][j]) || argv[i][j] == ' ' || argv[i][j] == '-')
		{
			if (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))
				j++;
			else if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ')
				return (0);
			j++;
			if (argv[i][j] == '-' && ft_isdigit(argv[i][j - 1]))
				return (0);
		}
		if (!ft_isdigit(argv[i][j]) && argv[i][j] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	more_than_one(t_node *check, int data, int count)
{
	if (check->data == data && check->next != NULL)
		return (more_than_one(check->next, data, count + 1));
	if (check->next != NULL)
		count = more_than_one(check->next, data, count);
	if (check->data == data && check->next == NULL)
		count++;
	return (count);
}

void	check_for_dup(t_stack *a)
{
	int		checker;
	t_node	*current_node;

	current_node = a->front;
	checker = more_than_one(current_node, current_node->data, 0);
	while (checker == 1 && current_node->next != NULL)
	{
		checker = more_than_one(current_node, current_node->data, 0);
		current_node = current_node->next;
	}
	if (checker != 1)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

void	clear(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	nb_args(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i - 1);
}
