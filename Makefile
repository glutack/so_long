#---------- ----------#
NAME	=	so_long
SRC		=	main.c images.c keys.c map.c moves.c
OBJ		=	$(SRC:.c=.o)

#--------- library ---------#
LIBFT		=	./libft/libft.a
LIBMLX		=	./minilibx-linux/libmlx_Linux.a

#---------- other ----------#
#CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

#---------- rules ----------#

all: $(NAME) 

$(LIBFT):
	@make -C libft

$(LIBMLX):
	@make -C minilibx-linux

#For object files, you could add the following rule to your makefile, assuming that you have the mlx for linux source in a directory named mlx_linux in the root of your project:#
%.o: %.c
	@gcc $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
	@echo "Objetos creados :D"

#To link with the required internal Linux API:#
$(NAME): $(OBJ) $(LIBMLX) $(LIBFT)
	@gcc $(CFLAGS) $(OBJ) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft -o $(NAME)
	@echo "Juego creado :D"

clean:
	@$(RM) $(OBJ)
	@echo "Objetos eliminados :D"

fclean: clean
	@$(RM) $(NAME)
	@echo "Juego eliminado :D"

re: fclean all

libclean:
	@make -C ./minilibx-linux clean
	@make -C ./libft clean
	@echo "Objetos de las librerías eliminados :D"

.PHONY: all clean fclean re