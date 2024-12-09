# Nombre del ejecutable
NAME = libftprintf.a

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente y objetos
SRCS = ft_printf_aux.c ft_printf.c ft_printf2.c
OBJS = $(SRCS:.c=.o)

# Comandos para la creación de la librería
AR = ar rcs

# Regla principal: compila todo
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Compila los archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpia los archivos objeto
clean:
	rm -f $(OBJS)

# Limpia los archivos objeto y el ejecutable
fclean: clean
	rm -f $(NAME)

# Vuelve a compilar todo
re: fclean all

# No interpreta estas palabras como nombres de archivo
.PHONY: all clean fclean re
