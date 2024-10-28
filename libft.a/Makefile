# Nombre de la librería
NAME = libft.a

# Flags de compilación
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente que quieres compilar
SRC = ft_isalpha.c ft_strlen.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c#main.c

# Archivos objeto
OBJ = $(SRC:.c=.o)

# Regla principal para crear la librería
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Limpia los archivos objeto
clean:
	del /f $(OBJ)

# Limpia los archivos objeto y la librería
fclean: clean
	rm -f $(NAME)

# Vuelve a compilar desde cero
re: fclean all
