#---------- ----------#
NAME	=	so_long
SRC		=	main.c images.c keys.c check_map.c move_player.c errors.c map.c animation.c
OBJ		=	$(SRC:.c=.o)

#--------- library ---------#
LIBFT		=	./libft/libft.a
#LIBMLX		=	./mlx/libmlx.a
LIBMLX		=	./minilibx-linux/libmlx_Linux.a

#---------- other ----------#
#CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

#---------- rules ----------#

all: $(NAME) 

$(LIBFT):
	@make -C ./libft

$(LIBMLX):
#@make -C ./mlx
	@make -C minilibx-linux

%.o: %.c
	@gcc -g $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
#@gcc $(CFLAGS) -c $(SRC)
	@echo "Objetos creados :D"

#To link with the required internal Linux API:#
$(NAME): $(OBJ) $(LIBMLX) $(LIBFT)
	@gcc -g $(CFLAGS) $(OBJ) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft -o $(NAME)
#@gcc $(OBJ) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
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
#@make -C ./mlx clean
	@make -C ./libft clean
	@echo "Objetos de las librerías eliminados :D"

.PHONY: all clean fclean re