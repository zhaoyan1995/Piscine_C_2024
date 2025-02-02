FLAG = -Wall -Wextra -Werror 

FILE_NAME = ft_tail

SRCS_PATH =  ./srcs/
HEADER_PATH = ./includes/

SRCS = $(SRCS_PATH)ft_main.c $(SRCS_PATH)ft_check_argv.c $(SRCS_PATH)ft_commun.c $(SRCS_PATH)ft_with_option.c $(SRCS_PATH)ft_without_option.c 

OBJ= $(SRCS_PATH)ft_main.o $(SRCS_PATH)ft_check_argv.o $(SRCS_PATH)ft_commun.o $(SRCS_PATH)ft_with_option.o $(SRCS_PATH)ft_without_option.o

all: $(FILE_NAME)

$(FILE_NAME): $(OBJ)
	gcc $(FLAG) $^ -o $@

$(SRC_PATH)%.o : $(SRC_PATH)%.c
	gcc $(FLAG) -c -I$(HEADER_PATH) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(FILE_NAME)



