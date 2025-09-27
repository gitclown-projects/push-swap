#include "../includes/push_swap.h"

void	sorting_4_5(t_stack *t)
{
	if (t->size_a == 5)
	{
		while (t->size_a != 3)
		{
			while (t->a[0] != 1 && t->a[0] != 2)
				ra(t);
			pb(t);
		}
		if (t->b[0] < t->b[1])
			sb(t);
	}
	if (t->size_a == 4)
	{
		while (t->a[0] != 1)
			ra(t);
		pb(t);
	}
	sorting_3(t);
	while (t->size_b)
		pa(t);
}

void	sorting_3(t_stack *t)
{
	if (t->a[0] > t->a[1] && t->a[1] < t->a[t->size_a - 1])
	{
		if (t->a[0] < t->a[t->size_a - 1])
			sa(t);
		else if (t->a[1] < t->a[t->size_a - 1])
			ra(t);
	}
	else if (t->a[0] > t->a[1] && t->a[1] > t->a[t->size_a - 1])
	{
		sa(t);
		rra(t);
	}
	else if (t->a[0] < t->a[1])
	{
		if (t->a[0] < t->a[t->size_a - 1] && t->a[1] > t->a[t->size_a - 1])
		{
			sa(t);
			ra(t);
		}
		else if (t->a[0] > t->a[t->size_a - 1])
			rra(t);
	}
}

void	sorting_2(t_stack *t)
{
	if (t->a[0] > t->a[1])
		sa(t);
}
