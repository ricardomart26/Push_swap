CC = gcc -Wall -Wextra -Werror

CCS = gcc -Wall -Wextra -Werror -fsanitize=address -static-libsan

INCLUDE = -I push_swap.h

LIB = -L ./Libft -l libft.a -static

SRC = $(wildcard main/*.c) $(wildcard cmds_and_combos/*.c) $(wildcard utils/*.c) $(wildcard simulate/*.c)

OBJS = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)

	# ifeq ("$(wildcard Objs)","Objs")
		# mkdir Objs
	# @echo "created Dirs"
	$(CC) $(OBJS) -o $(NAME)
	mv $(OBJS) Objs

san: fclean $(OBJS)
	# mkdir Objs
	# @echo "created Dirs"
	$(CCS) $(OBJS) -g -o $(NAME)
	mv $(OBJS) Objs

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf Objs
	rm -f swap.out

re:	fclean $(NAME)

.PHONY: all clean fclean re
