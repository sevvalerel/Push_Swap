NAME = push_swap

SRCS = move0.c move1.c list.c control.c push_swap.c free.c index.c radix.c less_than_6.c function1.c function2.c

CFLAGS = -Wall -Wextra -Werror 

CC=cc
OBJS = $(SRCS:.c=.o)

all		: $(NAME)
$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re