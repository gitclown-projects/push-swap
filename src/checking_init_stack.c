#include "../includes/push_swap.h"

int	check_sorting(t_stack *t)
{
	int	i;
	int	j;

	i = 0;
	while (i < t->size_a - 1)
	{
		j = i + 1;
		while (j < t->size_a)
		{
			if (t->a[i] == t->a[j])
				return (write(2, "Error\ndouble numbers\n", 21));
			j++;
		}
		i++;
	}
	i = 0;
	while (i < t->size_a - 1)
	{
		if (t->a[i] > t->a[i + 1])
			return (0);
		i++;
	}
	write(2, "Error\nalready sorted\n", 21);
	return (1);
}

int	*ft_index(int *tab, int size)
{
	int	index;
	int	i;
	int	j;
	int	*tmp;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i <= size - 1)
	{
		j = 0;
		index = 0;
		while (j <= size - 1)
		{
			if (tab[i] > tab[j])
				index++;
			j++;
		}
		tmp[i] = index + 1;
		i++;
	}
	free(tab);
	return (tmp);
}

long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long int	n;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
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
	t.a = ft_index(t.a, t.size_a);
	return (t);
}

int	check_arg(int argc, char **argv)
{
	int			i;
	int			j;
	int			count_digits;
	long int	n;

	i = 1;
	while (i <= argc - 1)
	{
		j = 0;
		count_digits = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (write(2, "Error\nonly numbers\n", 19));
			count_digits += argv[i][j] != '0';
			j++;
		}
		n = ft_atol(argv[i]);
		if (count_digits > 10 || n > INT_MAX || n < INT_MIN)
			return (write(2, "Error\nthe number is too big\n", 28));
		i++;
	}
	return (0);
}
