NAME = minishell

FLAGS = -Wall -Wextra -Werror

SRC = srcs/

SOURCES = $(SRC)main.c \
		  $(SRC)parse.c \
		  $(SRC)split.c \
		  $(SRC)tilda_helpers.c \
		  $(SRC)substitute_interior_helpers.c \
		  $(SRC)substitute_vars.c \
		  $(SRC)dict.c \
		  $(SRC)dict_find.c \
		  $(SRC)helpers.c \
		  $(SRC)base_loop.c \
		  $(SRC)balance_built_in.c \
		  $(SRC)ft_exit.c \
		  $(SRC)ft_echo.c \
		  $(SRC)ft_env_helpers.c \
		  $(SRC)ft_env.c \
		  $(SRC)ft_cd.c \
		  $(SRC)ft_bins.c 

LIBFT_FOLDER = libft

LIBFT = -L $(LIBFT_FOLDER) -lft

OBJECTS = $(SOURCES:.c=.o)

HEADERS = -I includes -I $(LIBFT_FOLDER)/includes

HDR = includes/minishell.h

%.o: %.c $(HDR)
	@gcc $(FLAGS) $(HEADERS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(LIBFT_FOLDER)
	@make -C $(LIBFT_FOLDER) clean
	@gcc $(FLAGS) -o $(NAME) $(HEADERS) $(OBJECTS) $(LIBFT)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_FOLDER) fclean

re: fclean all

test:
	@gcc -g $(FLAGS) -o $(NAME) $(HEADERS) $(SOURCES) $(LIBFT)
	@./$(NAME)

valgr:
	@gcc -g $(FLAGS) -o $(NAME) $(HEADERS) $(SOURCES) $(LIBFT)
	@valgrind --leak-check=full --verbose ./$(NAME)

val:
	@gcc -g $(FLAGS) -o $(NAME) $(HEADERS) $(SOURCES) $(LIBFT)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME)
