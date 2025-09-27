#include "../includes/push_swap_bonus.h"
#include "../includes/get_next_line.h"

void	rra(t_stack *t)
{
	int	tmp;
	int	size;

	size = t->size_a;
	tmp = t->a[size - 1];
	while (size > 1)
	{
		t->a[size - 1] = t->a[size - 2];
		size--;
	}
	t->a[0] = tmp;
}

void	rrb(t_stack *t)
{
	int	tmp;
	int	size;

	size = t->size_b;
	tmp = t->b[size - 1];
	while (size > 1)
	{
		t->b[size - 1] = t->b[size - 2];
		size--;
	}
	t->b[0] = tmp;
}

void	rrr(t_stack *t)
{
	int	tmp;
	int	size;

	size = t->size_a;
	tmp = t->a[size - 1];
	while (size > 1)
	{
		t->a[size - 1] = t->a[size - 2];
		size--;
	}
	t->a[0] = tmp;
	size = t->size_b;
	tmp = t->b[size - 1];
	while (size > 1)
	{
		t->b[size - 1] = t->b[size - 2];
		size--;
	}
	t->b[0] = tmp;
}
