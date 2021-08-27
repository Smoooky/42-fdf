NAME = fdf
OBJ_DIR = ./objects
SRC_DIR = ./sources
OBJS =	$(OBJ_DIR)/main.o\
		$(OBJ_DIR)/draw.o\
		$(OBJ_DIR)/get_next_line.o\
		$(OBJ_DIR)/get_next_line_utils.o\
		$(OBJ_DIR)/read_file.o\
		$(OBJ_DIR)/sub.o
HDRS_DIR = ./includes
HDRS = 	$(HDRS_DIR)/fdf.h\
		$(HDRS_DIR)/ft_printf.h\
		$(HDRS_DIR)/get_next_line.h\
		$(HDRS_DIR)/libft.h\
		$(HDRS_DIR)/mlx.h\
		$(HDRS_DIR)/mlx_int.h\
		$(HDRS_DIR)/mlx_new_window.h
LIBFT = $(SRC_DIR)/printf/libft
PRINTF = $(SRC_DIR)/printf
MLX = $(SRC_DIR)/minilibx_macos
FW = -framework OpenGL -framework AppKit
LIBS = -L$(MLX) -lmlx -L$(LIBFT) -lft -L$(PRINTF) -lftprintf

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(HDRS)
	$(MAKE) -C $(PRINTF)
	$(MAKE) -C $(MLX)
	gcc -o $@ $(OBJS) $(LIBS) $(FW)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c $< -o $@

$(OBJ_DIR):
	mkdir objects

clean:
	$(MAKE) -C $(PRINTF) clean
	$(MAKE) -C $(MLX) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF) fclean

re: fclean all