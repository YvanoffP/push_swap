LIBFT_DIR		=	libft/

PS_SRCS			=	$(addprefix src/, $(SRCS))

SRCS			=	parsing/push_swap_parsing.c parsing/push_swap_parsing_utils.c \
					commands/commands_1.c commands/commands_2.c commands/commands_3.c \
					list_utils/list_utils.c list_utils/list_utils_2.c \
					solver/solver.c solver/solver_utils.c solver/solver_utils_2.c solver/solver_utils_3.c \
					solver/solver_utils_4.c push_swap.c

HEADER_PS		=	src/push_swap.h

CC				= 	gcc $(CFLAGS)

RM				= 	rm -f

CFLAGS			= 	-Wall -Wextra -Werror

NAME			= 	push_swap

.PHONY:			libft all clean fclean re bonus

all:			$(NAME)

$(NAME):		libft
				$(CC) $(PS_SRCS) -I $(HEADER_PS) $(LIBFT_DIR)libft.a -o $(NAME)
				@echo "push_swap has been compiled !"

libft:
				make -C $(LIBFT_DIR) all

clean:
				$(RM) $(NAME)
				make -C $(LIBFT_DIR) clean

fclean:			clean
				$(RM) $(NAME)
				make -C $(LIBFT_DIR) fclean

re:				fclean $(NAME)
