#---------- ----------#
NAME	=	so_long
SRC		=	./src/main.c ./src/images.c ./src/keys.c ./src/check_map.c\
			./src/player.c ./src/check_other.c ./src/move_enemy.c\
			./src/errors.c ./src/map.c ./src/animation.c
OBJ		=	$(SRC:.c=.o)

#--------- library ---------#
LIBFT		=	./libft/libft.a
LIBMLX		=	./minilibx-linux/libmlx_Linux.a
#LIBMLX		=	./mlx/libmlx.a

#---------- other ----------#
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

#---------- rules ----------#

all: $(NAME) 

$(LIBFT):
	@make -C ./libft

$(LIBMLX):
	@make -C minilibx-linux
#@make -C ./mlx

%.o: %.c
	@gcc -g $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
#@gcc $(CFLAGS) -c $(SRC)
	@echo "Objetos creados :D"

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
	@make -C ./libft fclean
	@echo "Objetos de las librerías eliminados :D"

.PHONY: all clean fclean re libclean