CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS =  -lmlx -framework OpenGL -framework AppKit
NAME = so_long

MAIN = main.c

PARSING_DIR = parsing
MOVES_DIR = moves
LIB_DIR = lib
INC_DIR = inc
EVENTS_DIR = events
PRINT_DIR = a_print
OBJ_DIR = obj

HEADERS = $(INC_DIR)/get_next_line.h $(INC_DIR)/so_long.h
SRC = $(PARSING_DIR)/pars_map.c $(PARSING_DIR)/pars_map1.c \
	$(MOVES_DIR)/e_moves.c $(MOVES_DIR)/p_moves.c \
	$(LIB_DIR)/add.c $(LIB_DIR)/ft_split.c $(LIB_DIR)/get_next_line_utils.c $(LIB_DIR)/get_next_line.c  $(LIB_DIR)/itoi.c \
	$(EVENTS_DIR)/events.c $(EVENTS_DIR)/images.c \
	$(PRINT_DIR)/m_print.c $(PRINT_DIR)/print.c

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS) $(MAIN)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(MAIN) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(PARSING_DIR)/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: $(MOVES_DIR)/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: $(EVENTS_DIR)/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: $(PRINT_DIR)/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj
fclean: clean
	rm $(NAME)
re: fclean all