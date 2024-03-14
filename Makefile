NAME	= push_swap

src = 	./src/main.c \
		./src/error.c \
		./src/push_command.c \
		./src/swap_command.c \
		./src/rotate_command.c \
		./src/reverse_rotate_command.c \
		./src/push_swap_utils \
		./src/stacks.c \
		./src/radix_sort.c \

OBJS 	= $(src:.c=.o)

HEADER	= includes

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror

.c.o:		%.o : %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS)
	make -C ./libft
	$(CC) $(OBJS) -Llibft -lft -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: 	clean
	make fclean -C ./libft
	rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re