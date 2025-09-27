#include "../includes/push_swap_bonus.h"
#include "../includes/get_next_line.h"

void	sa(t_stack *t)
{
	int	tmp;

	tmp = t->a[0];
	t->a[0] = t->a[1];
	t->a[1] = tmp;
}

void	sb(t_stack *t)
{
	int	tmp;

	tmp = t->b[0];
	t->b[0] = t->b[1];
	t->b[1] = tmp;
}

void	ss(t_stack *t)
{
	int	tmp;

	tmp = t->a[0];
	t->a[0] = t->a[1];
	t->a[1] = tmp;
	tmp = t->b[0];
	t->b[0] = t->b[1];
	t->b[1] = tmp;
}

void	pa(t_stack *t)
{
	int	i;
	int	tmp_a;

	i = 0;
	tmp_a = t->size_a;
	while (tmp_a > 0)
	{
		t->a[tmp_a] = t->a[tmp_a - 1];
		tmp_a--;
	}
	t->a[0] = t->b[0];
	while (i < t->size_b - 1)
	{
		t->b[i] = t->b[i + 1];
		i++;
	}
	t->size_a += 1;
	t->size_b -= 1;
}

void	pb(t_stack *t)
{
	int	i;
	int	tmp_b;

	i = 0;
	tmp_b = t->size_b;
	while (tmp_b > 0)
	{
		t->b[tmp_b] = t->b[tmp_b - 1];
		tmp_b--;
	}
	t->b[0] = t->a[0];
	while (i < t->size_a - 1)
	{
		t->a[i] = t->a[i + 1];
		i++;
	}
	t->size_a -= 1;
	t->size_b += 1;
}
