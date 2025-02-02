FLAG = -Wall -Wextra -Werror

BINARY_FILE = ft_cat
SRC_PATH = ./srcs/
HEADER_PATH = ./includes/
SRC = $(SRC_PATH)ft_main.c $(SRC_PATH)ft_cat.c
OBJ = $(SRC_PATH)ft_main.o $(SRC_PATH)ft_cat.o

all: $(BINARY_FILE)

$(BINARY_FILE): $(OBJ)
	gcc $(FLAG) $^ -o $(BINARY_FILE)

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	gcc $(FLAG) -I$(HEADER_PATH) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(BINARY_FILE)
