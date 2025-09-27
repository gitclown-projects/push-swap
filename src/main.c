#include "../includes/push_swap.h"

void	ft_clear(t_stack *t)
{
	free(t->a);
	free(t->b);
}

int	main(int argc, char **argv)
{
	t_stack	t;

	if (check_arg(argc, argv))
		return (0);
	if (argc == 2)
		write(2, "Error\nmore arguments needed\n", 28);
	else if (argc > 2)
	{
		t = init_stack(argc, argv);
		if (check_sorting(&t) || !t.a || !t.b)
		{
			ft_clear(&t);
			return (0);
		}
		if (argc == 3)
			sorting_2(&t);
		if (argc == 4)
			sorting_3(&t);
		if (argc > 4 && argc < 7)
			sorting_4_5(&t);
		if (argc > 6)
			sorting_large(&t);
		ft_clear(&t);
	}
	return (0);
}
