CC      = cc
CFLAGS = -Wall -Wextra -Werror -D_XOPEN_SOURCE=700 -D_DEFAULT_SOURCE
NAME_S  = server
NAME_C  = client
SRC_S   = server.c utils.c
SRC_C   = client.c utils.c
OBJDIR  = obj
OBJ_S   = $(addprefix $(OBJDIR)/,$(SRC_S:.c=.o))
OBJ_C   = $(addprefix $(OBJDIR)/,$(SRC_C:.c=.o))

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJ_S) minitalk.h
	$(CC) $(CFLAGS) $(OBJ_S) -o $(NAME_S)

$(NAME_C): $(OBJ_C) minitalk.h
	$(CC) $(CFLAGS) $(OBJ_C) -o $(NAME_C)

# regla generica para compilar .c → .o en obj/
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# crear carpeta obj si no existe
$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME_S) $(NAME_C)

re: fclean all
