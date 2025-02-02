FLAG = -Wall -Wextra -Werror

LIB_NAME = libft.a
SRC_PATH = ./srcs/
SRC = $(SRC_PATH)ft_putchar.c $(SRC_PATH)ft_swap.c $(SRC_PATH)ft_putstr.c $(SRC_PATH)ft_strlen.c $(SRC_PATH)ft_strcmp.c
OBJ = $(SRC_PATH)ft_putchar.o $(SRC_PATH)ft_swap.o $(SRC_PATH)ft_putstr.o $(SRC_PATH)ft_strlen.o $(SRC_PATH)ft_strcmp.o
HEADER = ./includes/

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^

$(SRC_PATH)%.o : $(SRC_PATH)%.c
	gcc -c $(FLAG) -I$(HEADER) $< -o $@
	
clean : 
	rm -f $(OBJ)

fclean: clean
	rm  -f $(LIB_NAME)

re: fclean all




 
