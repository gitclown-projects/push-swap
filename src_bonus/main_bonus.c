#include "../includes/push_swap_bonus.h"
#include "../includes/get_next_line.h"

void	exec_commands(t_stack *t, int n, char c)
{
	if (n == 211 && c == 'r')
		ra(t);
	else if (n == 212 && c == 'r')
		rb(t);
	else if (n == 325 && c == 'r')
		rra(t);
	else if (n == 326 && c == 'r')
		rrb(t);
	else if (n == 210 && c == 'p')
		pb(t);
	else if (n == 209 && c == 'p')
		pa(t);
	else if (n == 212 && c == 's')
		sa(t);
	else if (n == 213 && c == 's')
		sb(t);
	else if (n == 230 && c == 's')
		ss(t);
	else if (n == 228 && c == 'r')
		rr(t);
	else if (n == 342 && c == 'r')
		rrr(t);
	else
		write (2, "Error\n", 6);
}

void	read_commands(t_stack *t)
{
	int		i;
	int		n;
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		i = 0;
		n = 0;
		while (str[i] != '\n')
		{
			n += str[i];
			i++;
		}
		exec_commands(t, n, str[0]);
		free(str);
		str = get_next_line(0);
	}
}

t_stack	init_stack(int argc, char **argv)
{
	t_stack	t;

	t.size_a = 0;
	t.size_b = 0;
	t.a = malloc(sizeof(int) * (argc - 1));
	if (!t.a)
		return (t);
	t.b = malloc(sizeof(int) * (argc - 1));
	if (!t.b)
		return ((free(t.a), t));
	while (t.size_a < argc - 1)
	{
		t.a[t.size_a] = ft_atol(argv[t.size_a + 1]);
		t.size_a++;
	}
	t.start = 0;
	t.end = t.size_a / 2;
	return (t);
}

int	main(int argc, char **argv)
{
	t_stack	t;

	if (argc >= 2)
	{
		t = init_stack(argc, argv);
		if (check_arg(argc, argv))
			return (ft_clear(&t));
		if (!t.a || !t.b)
			return (ft_clear(&t));
		if (check_sorting(&t))
			return (ft_clear(&t));
		read_commands(&t);
		if (check_sorting(&t) && t.size_b == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_clear(&t);
	}
	return (0);
}
