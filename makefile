CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
SRC = $(wildcard *.c)
NAME = monty
RM = rm

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(SRC):
	echo "Make a clone from github"

clean:
	$(RM) -f *~ $(NAME)
