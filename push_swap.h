# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	char			*str_buf;
	struct s_list	*next;
    struct s_list   *prev;
}					t_stack;

# endif PUSH_SWAP_H