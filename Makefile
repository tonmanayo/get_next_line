NAME = test_gnl
SRC = main.c \
	  get_next_line.c

LIBDIR = libft
LIB = libft/libft.a
FLAG = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB)

clean:
	@make clean -C $(LIBDIR)

fclean: clean
	@make fclean -C $(LIBDIR)
	@rm -rf $(NAME)

re: fclean all
