#include "../includes/push_swap_bonus.h"
#include "../includes/get_next_line.h"

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
}
