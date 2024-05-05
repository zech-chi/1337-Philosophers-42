NAME = philo

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g

PTHREAD = -pthread

SRCS =	main.c \
		parsing.c \
		tools.c \
		forks.c \
		mtx_get_1.c \
		mtx_get_2.c \
		mtx_set.c \
		mtx_tools.c \
		philos.c \
		table.c \
		time.c \
		to_remove.c \
		routine.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) $(PTHREAD) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(PTHREAD) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
