# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahir <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 20:51:27 by ozahir            #+#    #+#              #
#    Updated: 2022/03/20 22:41:26 by ozahir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


M_DIR = mandatory
B_DIR = bonus

M_NAME = so_long
B_NAME = so_long_bonus

M_MAIN = $(M_DIR)/main.c
B_MAIN = $(B_DIR)/main.c


CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS =  -lmlx -framework OpenGL -framework AppKit

M_PARSING_DIR = $(M_DIR)/parsing
M_MOVES_DIR = $(M_DIR)/moves
M_LIB_DIR = $(M_DIR)/lib
M_INC_DIR = $(M_DIR)/inc
M_EVENTS_DIR = $(M_DIR)/events
M_PRINT_DIR = $(M_DIR)/a_print
M_OBJ_DIR = $(M_DIR)/obj

B_PARSING_DIR = $(B_DIR)/parsing
B_MOVES_DIR = $(B_DIR)/moves
B_LIB_DIR = $(B_DIR)/lib
B_INC_DIR = $(B_DIR)/inc
B_EVENTS_DIR = $(B_DIR)/events
B_PRINT_DIR = $(B_DIR)/a_print
B_OBJ_DIR = $(B_DIR)/obj

M_HEADERS = $(M_INC_DIR)/get_next_line.h  $(M_INC_DIR)/so_long.h
B_HEADERS = $(B_INC_DIR)/get_next_line.h  $(B_INC_DIR)/so_long.h

M_SRC = $(M_PRINT_DIR)/m_print.c $(M_PRINT_DIR)/print.c $(M_EVENTS_DIR)/events.c \
	$(M_EVENTS_DIR)/images.c  $(M_LIB_DIR)/ft_split.c $(M_LIB_DIR)/get_next_line.c \
	$(M_LIB_DIR)/get_next_line_utils.c $(M_LIB_DIR)/itoi.c  $(M_MOVES_DIR)/p_moves.c \
	$(M_PARSING_DIR)/pars_map.c $(M_PARSING_DIR)/pars_map1.c $(M_LIB_DIR)/add.c


B_SRC = $(B_PRINT_DIR)/m_print.c $(B_PRINT_DIR)/print.c $(B_EVENTS_DIR)/events.c \
	$(B_EVENTS_DIR)/images.c  $(B_LIB_DIR)/ft_split.c $(B_LIB_DIR)/get_next_line.c \
	$(B_LIB_DIR)/get_next_line_utils.c $(B_LIB_DIR)/itoi.c  $(B_MOVES_DIR)/p_moves.c \
	$(B_PARSING_DIR)/pars_map.c $(B_PARSING_DIR)/pars_map1.c $(B_MOVES_DIR)/e_moves.c $(B_LIB_DIR)/add.c

M_OBJ = $(addprefix $(M_OBJ_DIR)/, $(notdir $(M_SRC:.c=.o)))

B_OBJ = $(addprefix $(B_OBJ_DIR)/, $(notdir $(B_SRC:.c=.o)))

all: $(M_NAME)

$(M_NAME): $(M_OBJ) $(M_HEADERS) $(M_MAIN)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(M_MAIN) $(M_OBJ) -o $(M_NAME)

bonus: $(B_OBJ) $(B_HEADERS) $(B_MAIN)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(B_MAIN) $(B_OBJ) -o $(B_NAME)

$(M_OBJ_DIR)/%.o: $(M_PARSING_DIR)/%.c
	mkdir -p mandatory/obj
	$(CC) $(CFLAGS) -c $< -o $@
$(M_OBJ_DIR)/%.o: $(M_MOVES_DIR)/%.c
	mkdir -p mandatory/obj
	$(CC) $(CFLAGS) -c $< -o $@
$(M_OBJ_DIR)/%.o: $(M_LIB_DIR)/%.c
	mkdir -p mandatory/obj
	$(CC) $(CFLAGS) -c $< -o $@
$(M_OBJ_DIR)/%.o: $(M_EVENTS_DIR)/%.c
	mkdir -p mandatory/obj
	$(CC) $(CFLAGS) -c $< -o $@
$(M_OBJ_DIR)/%.o: $(M_PRINT_DIR)/%.c
	mkdir -p mandatory/obj
	$(CC) $(CFLAGS) -c $< -o $@



$(B_OBJ_DIR)/%.o: $(B_PARSING_DIR)/%.c
	mkdir -p bonus/obj
	$(CC) $(CFLAGS) -c $< -o $@
$(B_OBJ_DIR)/%.o: $(B_MOVES_DIR)/%.c
	mkdir -p bonus/obj
	$(CC) $(CFLAGS) -c $< -o $@
$(B_OBJ_DIR)/%.o: $(B_LIB_DIR)/%.c
	mkdir -p bonus/obj
	$(CC) $(CFLAGS) -c $< -o $@
$(B_OBJ_DIR)/%.o: $(B_EVENTS_DIR)/%.c
	mkdir -p bonus/obj
	$(CC) $(CFLAGS) -c $< -o $@
$(B_OBJ_DIR)/%.o: $(B_PRINT_DIR)/%.c
	mkdir -p bonus/obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(M_OBJ_DIR) $(B_OBJ_DIR)

fclean: clean
	@rm $(M_NAME) $(B_NAME)

re: fclean all
