# Nombre de la librería
NAME = libft.a

# Flags de compilación
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente que quieres compilar
SRC = ft_isalpha.c ft_strlen.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c#main.c

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
