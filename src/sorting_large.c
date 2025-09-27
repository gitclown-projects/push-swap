#include "../includes/push_swap.h"

/* une fois tout dans A, check si a[0] est dans la 1ere moitie de A 
rra sinon ra*/
void	last_moves(t_stack *t)
{
	if (t->a[0] <= t->size_a / 2 + 1)
		while (t->a[0] != 1)
			rra(t);
	else
		while (t->a[0] != 1)
			ra(t);
}

/* permet de faire les moves necessaires pour send l'element 
choose best dans pile a*/
void	insert_b_to_a(t_stack *t)
{
	t_cmd	cmd_best;
	t_cmd	cmd;
	int		i;

	initialize_cmd(&cmd, 0);
	while (t->size_b)
	{
		initialize_cmd(&cmd_best, 100000);
		i = 0;
		while (i < t->size_b)
		{
			cmd = edit_command_a(t, cmd, t->b[i]);
			cmd = edit_command_b(t, cmd, t->b[i]);
			cmd_best = choose_best(cmd, cmd_best);
			i++;
			initialize_cmd(&cmd, 0);
		}
		rotate(t, &cmd_best);
		rev_rotate(t, &cmd_best);
		pa(t);
		if (t->a[0] < t->start)
			t->start = t->a[0];
	}
}

/* i++ si pas dans la plage start/end; si un element dans A et 1 dans B 
double rotation, si un dans B rotation uniquement dans B*/
void	opti_half(t_stack *t)
{
	int	i;

	i = 0;
	while (!(t->a[i] >= t->start && t->a[i] <= t->end) && i < t->size_a)
		i++;
	if (i > 0 && t->b[0] >= t->start
		&& t->b[0] <= (t->end + t->start) / 2 && t->size_b > 1)
		rr(t);
	if (t->b[0] >= t->start
		&& t->b[0] <= (t->end + t->start) / 2 && t->size_b > 1)
		rb(t);
}

/*send + petits puis quand B a la moitie des elements,
 les + grands sauf 3 max qui restent dans A*/
void	half_to_b(t_stack *t)
{
	int	tmp;

	tmp = t->size_a;
	while (t->size_a >= 3)
	{
		if (t->size_b == tmp / 2)
		{
		t->start = t->end;
		t->end = tmp - 3;
		}
		while (!(t->a[0] >= t->start && t->a[0] <= t->end))
			ra(t);
		pb(t);
		if (t->size_a == 3)
			break ;
		opti_half(t);
	}
}

void	sorting_large(t_stack *t)
{
	half_to_b(t);
	sorting_3(t);
	pa(t);
	t->start = t->a[0];
	insert_b_to_a(t);
	last_moves(t);
}
