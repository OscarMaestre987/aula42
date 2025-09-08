NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = \
	main.c \
	Operations/operations.c \
	Operations/operationsA.c \
	Operations/operationsB.c \
	Operations/operationsC.c \
	Utils/stackHelpers.c \
	Utils/checks.c \
	Utils/compression.c \
	Utils/enterNumbers.c \
	Utils/enterNumbers2.c \
	Utils/enterNumbers3.c \
	SmallNumbers/small.c \
	SmallNumbers/smallUtils.c \
	Utils/utils2.c\
	Utils/utils.c\
	Utils/list.c\
	Utils/list2.c\
	Utils/bigNumbers.c\
	Utils/bigNumbers2.c\
	Utils/bigNumbers3.c\
	Utils/bigNumbers4.c\
	Utils/apply_modes.c\
	Utils/parseInt.c
OBJDIR  = obj
OBJ     = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Regla para compilar .c -> .o dentro de obj/
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Crear carpeta si no existe
$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJ)
	find . -type d -empty -delete

fclean: clean
	rm -f $(NAME)
	find . -type d -empty -delete

re: fclean all
