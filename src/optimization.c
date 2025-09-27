#include "../includes/push_swap.h"

t_cmd	best_rot(t_cmd cmd)
{
	while (cmd.ra && cmd.rb)
	{
		cmd.ra--;
		cmd.rb--;
		cmd.total++;
	}
	while (cmd.ra)
	{
		cmd.ra--;
		cmd.total++;
	}
	while (cmd.rb)
	{
		cmd.rb--;
		cmd.total++;
	}
	return (cmd);
}

t_cmd	best_rev_rot(t_cmd cmd)
{
	while (cmd.rra && cmd.rrb)
	{
		cmd.rra--;
		cmd.rrb--;
		cmd.total++;
	}
	while (cmd.rra)
	{
		cmd.rra--;
		cmd.total++;
	}
	while (cmd.rrb)
	{
		cmd.rrb--;
		cmd.total++;
	}
	return (cmd);
}

t_cmd	choose_best(t_cmd cmd, t_cmd cmd_best)
{
	t_cmd	clone;

	clone = cmd;
	cmd = best_rot(cmd);
	cmd = best_rev_rot(cmd);
	clone.total = cmd.total;
	if (cmd_best.total > cmd.total)
		cmd_best = clone;
	return (cmd_best);
}
