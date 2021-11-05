#include "push_swap.h"

static void	clear(char **array, int i)
{
	while (i-- > 0)
		free(array[i]);
	free(array);
	return ;
}


int main(int argc, char **argv)
{
	char	**tmp;
	int	*swap_a;
	int	i = 0;
	int	j = 0;
	int	k = 1;

	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		if (!tmp)
			return (0);
		while (tmp[i])
			i++;
		swap_a = malloc(sizeof(int) * i);
		if (!swap_a)
			return (0);
		while (j < i)
		{
			swap_a[j] = ft_atoi(tmp[j]);
			printf("swap_a[%d] = %d\n", j, swap_a[j]);
			j++;
		}
		clear(tmp, i);
	}
	else if (argc > 2)
	{
		while (argv[i])
			i++;
		i -= 1;
		swap_a = malloc(sizeof(int) * i);
		if (!swap_a)
			return (0);
		while (j < i)
		{
			swap_a[j] = ft_atoi(argv[k]);
			printf("swap_a[%d] = %d\n", j, swap_a[j]);
			j++;
			k++;
		}
	}
	else
		write (1, "error", 5);
	return (0);
}
