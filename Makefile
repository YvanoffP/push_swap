CC					= gcc
FLAGS				= -Wall -Wextra -Werror
LIBFT_PATH			= ./libft
INCL				= ./src

CFLAGS				= $(FLAGS) -I$(LIBFT_PATH)/ -I$(INCL)/

LINKS				= -L $(LIBFT_PATH) -lft

NAME				= push_swap

SRCS_PATH		   	= src/

MAIN				= push_swap.c

CMD					= commands_1.c commands_2.c commands_3.c

SOLVER				= solver.c solver_utils.c solver_utils_2.c solver_utils_3.c solver_utils_4.c

LIST_UTILS			= list_utils.c list_utils_2.c

PARS				= push_swap_parsing_utils.c push_swap_parsing.c

SRCS				= $(addprefix $(SRCS_PATH), $(MAIN)) \
				 	 $(addprefix $(SRCS_PATH)commands/, $(CMD)) \
				 	 $(addprefix $(SRCS_PATH)list_utils/, $(LIST_UTILS)) \
				 	 $(addprefix $(SRCS_PATH)parsing/, $(PARS)) \
				 	 $(addprefix $(SRCS_PATH)solver/, $(SOLVER))

OBJS_PSWAP	  		= $(SRCS:.c=.o)


all:				$(NAME)

$(OBJS_PSWAP): %.o: %.c
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME) :	   		$(OBJS_PSWAP)
					make -C $(LIBFT_PATH)
					$(CC) -o $(NAME) $(OBJS_PSWAP) $(LINKS)

clean:
					rm -rf $(SRCS:.c=.o)
					make -C $(LIBFT_PATH) clean

fclean: 			clean
					rm -rf $(LIBFT_PATH)libft.a
					rm -rf $(NAME)

re:	 				fclean all

.PHONY : all re clean fclean
