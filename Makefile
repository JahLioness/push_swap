CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

SRC = main.c set_groups.c push_groups.c set_target.c sorting_utils.c ft_sort.c ft_score.c set_to_top.c push_swap.c 

B_SRC = checker_main.c 

C_SRC = ft_check_args.c ft_parse.c ft_push.c ft_reverse_rotate.c ft_rotate.c ft_swap.c ft_utils.c lst_utils.c lst_utils2.c set_index.c 

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

C_OBJ = $(C_SRC:.c=.o)

HEADER_F = push_swap.h

B_HEADER_F = checker.h

LIBFT = ./libft/libft.a

NAME = push_swap

B_NAME = checker

all: $(NAME)

bonus: $(B_NAME)

$(NAME): $(OBJ) $(C_OBJ) $(HEADER_F) $(LIBFT)
	$(CC) $(CFLAGS) -c $(SRC) $(C_SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(C_OBJ) $(LIBFT)

$(LIBFT):
	make -C libft

$(B_NAME): $(B_OBJ) $(B_HEADER_F) $(LIBFT)
	$(CC) $(CFLAGS) -c $(B_SRC) $(C_SRC)
	$(CC) $(CFLAGS) -o $(B_NAME) $(B_OBJ) $(C_OBJ) $(LIBFT)

clean:
	rm -f $(OBJ) $(C_OBJ)
	rm -f $(B_OBJ) $(C_OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f $(B_NAME)
	make -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re