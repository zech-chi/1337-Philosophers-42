NAME = philo_bonus

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

PTHREAD = -pthread

SRCS =	main_bonus.c \
		parsing_bonus.c \
		tools_bonus.c \
		table_bonus.c \
		philos_bonus.c \
		forks_bonus.c \
		time_bonus.c \
		simulation_bonus.c \
		routine_bonus.c \
		sem_tools_bonus.c \
		observer_bonus.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c philo_bonus.h
	$(CC) $(CFLAGS) $(PTHREAD) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(PTHREAD) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
