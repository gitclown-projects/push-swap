#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	start;
	int	end;
}		t_stack;

//main_bonus.c
t_stack	init_stack(int argc, char **argv);
void	read_commands(t_stack *t);
//checker_utils.c
int		check_arg(int argc, char **argv);
int		ft_clear(t_stack *t);
int		check_sorting(t_stack *t);
long	ft_atol(const char *str);
//cmd_swap_push_bonus.c
void	sa(t_stack *t);
void	sb(t_stack *t);
void	ss(t_stack *t);
void	pb(t_stack *t);
void	pa(t_stack *t);
//cmd_rotate_bonus.c
void	ra(t_stack *t);
void	rb(t_stack *t);
void	rr(t_stack *t);
//cmd_reverse_bonus.c
void	rra(t_stack *t);
void	rrb(t_stack *t);
void	rrr(t_stack *t);

#endif
