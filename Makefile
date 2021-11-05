LIBFT_DIR		=	libft/

SRCS_PRINT		=	push_swap.c

OBJS_PRINT		=	$(addprefix src/, $(SRCS_PRINT:.c=.o))

CC				= gcc $(CFLAGS)

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

NAME			= push_swap.a

.PHONY:			libft all clean fclean re bonus

all:			$(NAME)

$(NAME):		libft $(OBJS_PRINT)
				ar rcs $(NAME) $(LIBFT_DIR)/*.o $(OBJS_PRINT)
				@echo "Libft is done!"

libft:
				make -C $(LIBFT_DIR) all

clean:
				$(RM) $(OBJS_LIB) $(OBJS_PRINT)
				make -C $(LIBFT_DIR) clean

fclean:			clean
				$(RM) $(NAME)
				make -C $(LIBFT_DIR) fclean

re:				fclean $(NAME)
