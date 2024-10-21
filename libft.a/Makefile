# Nombre de la librería
NAME = libft.a

# Flags de compilación
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente
SRC = ft_isalpha.c ft_strlen.c ft_memset.c main.c# Añade aquí el resto de tus archivos .c

# Archivos objeto (se generan a partir de los .c)
OBJ = $(SRC:.c=.o)

# Regla principal para crear la librería
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Limpia los archivos objeto
clean:
	rm -f $(OBJ)

# Limpia los archivos objeto y la librería
fclean: clean
	rm -f $(NAME)

# Vuelve a compilar desde cero
re: fclean all
