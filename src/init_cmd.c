#include "../includes/push_swap.h"

void	initialize_cmd(t_cmd *cmd, int c)
{
	cmd->ra = c;
	cmd->rb = c;
	cmd->rra = c;
	cmd->rrb = c;
	cmd->total = c * 2;
}

void	rev_rotate(t_stack *t, t_cmd *cmd)
{
	while (cmd->rra && cmd->rrb)
	{
		rrr(t);
		cmd->rra--;
		cmd->rrb--;
	}
	while (cmd->rra)
	{
		rra(t);
		cmd->rra--;
	}
	while (cmd->rrb)
	{
		rrb(t);
		cmd->rrb--;
	}
}

void	rotate(t_stack *t, t_cmd *cmd)
{
	while (cmd->ra && cmd->rb)
	{
		rr(t);
		cmd->ra--;
		cmd->rb--;
	}
	while (cmd->ra)
	{
		ra(t);
		cmd->ra--;
	}
	while (cmd->rb)
	{
		rb(t);
		cmd->rb--;
	}
}
/*parcourt A pour determiner position ou mettre b[i],
puis ra ou rra en fonction de position*/

t_cmd	edit_command_a(t_stack *t, t_cmd cmd, int b_of_i)
{
	int	i;
	int	total_shift_a;

	total_shift_a = -1;
	i = 0;
	if (b_of_i < t->a[0] && b_of_i > t->a[t->size_a - 1])
		total_shift_a = 0;
	while (i < t->size_a && total_shift_a != 0)
	{
		if (b_of_i < t->start && t->a[i] == t->start)
			total_shift_a = i;
		else if (b_of_i > t->a[i]
			&& b_of_i < t->a[i + 1] && i < t->size_a - 1)
			total_shift_a = i + 1;
		i++;
	}
	if (total_shift_a > t->size_a / 2)
		cmd.rra = t->size_a - total_shift_a;
	else
		cmd.ra = total_shift_a;
	return (cmd);
}

/* parcourt B jusqu'a i de b[i], determine selon sa position si ra ou rra
pour le mettre en haut de la pile B*/
t_cmd	edit_command_b(t_stack *t, t_cmd cmd, int b_of_i)
{
	int	total_shift_b;

	total_shift_b = 0;
	while (t->b[total_shift_b] != b_of_i)
		total_shift_b++;
	if (total_shift_b > t->size_b / 2)
		cmd.rrb = t->size_b - total_shift_b;
	else
		cmd.rb = total_shift_b;
	return (cmd);
}
