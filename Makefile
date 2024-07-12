##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile my_runner
##

ECHO = /bin/echo -e
DEFAULT = "\033[00m"
BOLD = "\e[1m"
RED = "\e[31m"
GREEN = "\e[32m"
LIGHT_BLUE = "\e[94m"
WHITE = "\e[1;37m"

SRC	=	src/fs_open_file.c	\
		src/move.c	\
		src/my_str_to_word_array.c	\
		src/my_strcat.c	\
		src/my_strcmp.c	\
		src/my_strcpy_m.c	\
		src/my_strcpy.c	\
		src/my_strdup.c	\
		src/my_strlen.c	\
		src/data_on_O.c	\
		src/data_on_X.c	\
		src/set_struct.c	\
		src/player.c	\
		src/main.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CFLAGS	=	-Wall -Wextra  -I includes/ -lncurses
all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -lcsfml-audio -lm -lcsfml-system

	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

debug:	CFLAGS += -g
debug:	re

re:	fclean all

tests_run:
		gcc -o unit_test $(SRC) -L . -lmy -lcriterion --coverage
		./unit_test

%.o:	%.c
	@$(CC) -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)" [OK] " \
	$(WHITE) || $(ECHO) -n $(BOLD) $(RED)" [KO] "$(WHITE) && $(ECHO) \
	$(BOLD) $< | rev | cut -d/ -f 1 | rev && $(ECHO) -n $(DEFAULT)
