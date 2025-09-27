#include "../includes/push_swap_bonus.h"
#include "../includes/get_next_line.h"

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
	return (1);
}

int	ft_clear(t_stack *t)
{
	free(t->a);
	free(t->b);
	return (0);
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
