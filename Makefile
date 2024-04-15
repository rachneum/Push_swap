NAME	= push_swap

src = 	./main.c \
		./ft_split.c \
		./error.c \
		./ft_push.c \
		./ft_swap.c \
		./ft_rotate.c \
		./ft_reverse_rotate.c \
		./sort_stack_last.c \
		./sort_stack.c \
		./stack_algo.c \
		./stack_cost_analisis.c \
		./stack_utils.c \
		./stack.c \

OBJS = ${src:.c=.o}

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re