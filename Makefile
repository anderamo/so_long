NAME = so_long

NAME_BONUS = checker

MANDATORY	=	main.c\
				gnl/get_next_line.c\
				gnl/get_next_line_utils.c\
				src/check.c\
				src/check_2.c\
				src/create.c\
				src/create_2.c\
				src/move.c\
				src/close.c\
				src/utils.c

OBJ = $(MANDATORY:.c=.o)

CC = gcc

INC = -I./includes

FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./libft
		$(MAKE) -C ./minilibx
		cp libft/libft.a .
		$(CC) $(FLAGS) $(INC) $(MANDATORY) -fsanitize=address -g3 libft.a -o $(NAME) -L minilibx -lmlx -framework OpenGL -framework AppKit

clean:
	$(MAKE) clean -C ./libft
	rm -rf *.o
	rm -rf src/*.o
	rm -rf gnl/*.o

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./minilibx
	rm -rf a.out
	rm -rf a.out.dSYM
	rm -rf *.a
	rm -rf so_long.dSYM
	rm -rf so_long

re: fclean all

.PHONY:	all clean fclean bonus re
