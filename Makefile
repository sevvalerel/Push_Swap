NAME = push_swap

SRCS = 

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re