INCLUDES	= ../includes/push_swap.h
INCLUDES_B	= ../includes/push_swap_bonus.h ../includes/get_next_line.h

SRC = main.c \
	checking_init_stack.c \
	cmd_swap_push.c \
	cmd_reverse.c \
	cmd_rotate.c \
	init_cmd.c \
	optimization.c \
	sorting_2_to_5.c \
	sorting_large.c \

SRC_B = main_bonus.c \
		checker_utils.c \
		get_next_line.c \
		get_next_line_utils.c \
		cmd_reverse_bonus.c \
		cmd_rotate_bonus.c \
		cmd_swap_push_bonus.c \

SOURCES		= $(addprefix $(SRCFLDR), $(SRC))
SOURCES_B	= $(addprefix $(SRCFLDR_B), $(SRC_B))
OBJECTS		= $(addprefix $(SRCFLDR), $(OBJS))
OBJECTS_B	= $(addprefix $(SRCFLDR_B), $(OBJS_B))
SRCFLDR = 	src/
SRCFLDR_B =	src_bonus/
NAME 	= push_swap
NAME_B	= checker
OBJS	= $(SOURCES:.c=.o)
OBJS_B	= $(SOURCES_B:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
$(NAME_B): $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B)

all : $(NAME) $(NAME_B)

bonus : $(NAME_B)

.objects/%.o: %.c
	${CC} ${CFLAGS} -c $<

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean:
	rm -f $(OBJS) $(OBJS_B) $(NAME) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re bonus
