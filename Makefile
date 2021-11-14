LIBFT_DIR		=	libft/

PS_SRCS			=	$(addprefix src/, $(SRCS))

SRCS			=	push_swap_parsing.c commands_1.c commands_2.c commands_3.c list_utils.c \
					solver.c solver_utils.c solver_utils_2.c solver_utils_3.c \
					push_swap_parsing_utils.c push_swap.c solver_utils_4.c list_utils_2.c \
					solver_long/solver_long_utils.c

HEADER_PS		=	src/push_swap.h

CC				= 	gcc $(CFLAGS)

RM				= 	rm -f

CFLAGS			= 	-Wall -Wextra -Werror

NAME			= 	push_swap

.PHONY:			libft all clean fclean re bonus

all:			$(NAME)

$(NAME):		libft $(OBJS_PRINT)
				$(CC) $(PS_SRCS) $(HEADER_PS) $(LIBFT_DIR)libft.a -o $(NAME)
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
