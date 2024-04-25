NAME = philo

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

PTHREAD = -pthread

SRCS =	main.c \
		parsing.c \
		tools.c \
		forks.c \
		philos.c \
		simulation.c \
		to_remove.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) $(PTHREAD) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re