NAME = philo

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror# -fsanitize=thread -g

PTHREAD = -pthread

SRCS =	main.c \
		parsing.c \
		tools.c
#		forks.c \
#		philos.c \
#		simulation.c \
#		time.c \
#		monitor.c \
#		stop.c \
#		to_remove.c

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
