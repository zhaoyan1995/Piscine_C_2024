FLAG = -Wall -Wextra -Werror

SRC_PATH = ./srcs/
SRC = $(SRC_PATH)main.c $(SRC_PATH)ft_display_file.c
BINARY_FILE = ft_display_file
HEADER = ./includes/
OBJ = $(SRC_PATH)main.o $(SRC_PATH)ft_display_file.o

all : $(BINARY_FILE)

$(BINARY_FILE): $(OBJ)
	gcc $(FLAG) $^ -o $@

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	gcc $(FLAG) -c -I$(HEADER) $< -o $@ 

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(BINARY_FILE)

