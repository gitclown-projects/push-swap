#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	start;
	int	end;
}		t_stack;

typedef struct s_cmd
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	total;
}		t_cmd;

//checking_init_stack
int		check_arg(int argc, char **argv);
t_stack	init_stack(int argc, char **argv);
int		check_sorting(t_stack *t);
//main.c
void	ft_clear(t_stack *t);
//sorting_2_to_5.c
void	sorting_2(t_stack *t);
void	sorting_3(t_stack *t);
void	sorting_4_5(t_stack *t);
//sorting_large.c
void	sorting_large(t_stack *t);
void	half_to_b(t_stack *t);
void	insert_b_to_a(t_stack *t);
//init_cmd.c
void	initialize_cmd(t_cmd *cmd, int c);
void	rev_rotate(t_stack *t, t_cmd *cmd);
void	rotate(t_stack *t, t_cmd *cmd);
t_cmd	edit_command_a(t_stack *t, t_cmd cmd, int b_of_i);
t_cmd	edit_command_b(t_stack *t, t_cmd cmd, int b_of_i);
//optimization.c
t_cmd	choose_best(t_cmd cmd, t_cmd cmd_best);
//cmd_swap_push.c
void	sa(t_stack *t);
void	sb(t_stack *t);
void	ss(t_stack *t);
void	pb(t_stack *t);
void	pa(t_stack *t);
//cmd_rotate.c
void	ra(t_stack *t);
void	rb(t_stack *t);
void	rr(t_stack *t);
//cmd_reverse.c
void	rra(t_stack *t);
void	rrb(t_stack *t);
void	rrr(t_stack *t);

#endif
