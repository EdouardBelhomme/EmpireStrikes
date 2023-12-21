##
## EPITECH PROJECT, 2023
## B-SYN-400-BDX-4-1-empirestrikes-edouard.belhomme
## File description:
## Makefile
##

NAME	= empire

CC		= gcc

RM		= rm -f

SRCS	=	./src/main.c \
			./src/empire.c \
			./src/commands.c \
			./src/help.c \
			./src/init.c \
			./src/romans.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -I ./include/
CFLAGS	+= -Wall -Wextra -lpthread -g

LDFLAGS	= -L./

LDLIBS	= -lempire

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
