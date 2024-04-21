NAME = philo

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	philo.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re