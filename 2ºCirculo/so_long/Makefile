# =========================
# Ejecutable
# =========================
NAME    := so_long

# Carpetas
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include

# Librerías como CARPETAS (tú las tienes así)
LIBFT_DIR        := libft.a
LIBFT_PRINTF_DIR := libftprintf.a

# MiniLibX
MLX_DIR   := mlx
MLX_A     := $(MLX_DIR)/libmlx_Linux.a
MLXFLAGS  := -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
INCS_MLX  := -I$(MLX_DIR)

# Compilador
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(LIBFT_PRINTF_DIR)

# =========================
# Fuentes → Objetos
# =========================
# Proyecto principal
SRC_MAIN := $(wildcard $(SRC_DIR)/*.c)
OBJ_MAIN := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_MAIN))

# libft (todos los .c dentro de la carpeta libft.a/)
SRC_LIBFT := $(wildcard $(LIBFT_DIR)/*.c)
OBJ_LIBFT := $(patsubst $(LIBFT_DIR)/%.c,$(OBJ_DIR)/libft_%.o,$(SRC_LIBFT))

# ft_printf (todos los .c dentro de la carpeta libftprintf.a/)
SRC_PRINTF := $(wildcard $(LIBFT_PRINTF_DIR)/*.c)
OBJ_PRINTF := $(patsubst $(LIBFT_PRINTF_DIR)/%.c,$(OBJ_DIR)/printf_%.o,$(SRC_PRINTF))

OBJ := $(OBJ_MAIN) $(OBJ_LIBFT) $(OBJ_PRINTF)

# =========================
# Reglas
# =========================
all: $(NAME)

$(NAME): $(OBJ) $(MLX_A)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(INCS_MLX) $(MLXFLAGS)

# Reglas de compilación por carpeta
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/libft_%.o: $(LIBFT_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/printf_%.o: $(LIBFT_PRINTF_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Construir MiniLibX si no existe la lib estática
$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
