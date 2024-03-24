NAME	= push_swap


src = 	./main.c \
		./error.c \
		./push_command.c \
		./swap_command.c \
		./rotate_command.c \
		./reverse_rotate_command.c \
		./push_swap_utils \
		./stacks.c \
		./radix_sort.c \

OBJS 	= $(src:.c=.o)

HEADER	= includes

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror

LIB = libft/libft.a

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