#include "../includes/push_swap.h"

void	ra(t_stack *t)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = t->a[0];
	while (i < t->size_a - 1)
	{
		t->a[i] = t->a[i + 1];
		i++;
	}
	t->a[t->size_a - 1] = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *t)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = t->b[0];
	while (i < t->size_b - 1)
	{
		t->b[i] = t->b[i + 1];
		i++;
	}
	t->b[t->size_b - 1] = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *t)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = t->a[0];
	while (i < t->size_a - 1)
	{
		t->a[i] = t->a[i + 1];
		i++;
	}
	t->a[t->size_a - 1] = tmp;
	i = 0;
	tmp = t->b[0];
	while (i < t->size_b - 1)
	{
		t->b[i] = t->b[i + 1];
		i++;
	}
	t->b[t->size_b - 1] = tmp;
	write(1, "rr\n", 3);
}
