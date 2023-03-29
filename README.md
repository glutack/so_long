<p align="center"><img src="https://github.com/glutack/glutack/blob/master/42img/so_long/so_long_banner.png?raw=true" alt="so_long 42 banner 125% 10/02/2023"/></p>

The `so_long` project lets us code a classic 2D game with the MLX Library, where you have to get all the collectibles in the map in order to win.
In my case the game will be called **"Las aventuras de Selene"** *(The adventures of Selene)*, a cute game where you're Selene (a hungry cute doggy) ready to eat all the chicken wings she can while trying to avoid Paulina, an evil chicken that will try to stab you <sup>(this game is kinda a joke, both are my pets irl)</sup>.

<p align="center" size=""><img src="https://github.com/glutack/glutack/blob/master/42img/so_long/selenegif.gif?raw=true" alt="game main character"/>	<img src="https://github.com/glutack/glutack/blob/master/42img/so_long/objectgif.gif?raw=true" alt="game collectibles"/>	<img src="https://github.com/glutack/glutack/blob/master/42img/so_long/exitgif.gif?raw=true" alt="game exit"/>	<img src="https://github.com/glutack/glutack/blob/master/42img/so_long/paulinogifnoback.gif?raw=true" alt="game enemy"/></p>

<p align="center"><sup>Main character: Selene	|	Collectibles: chicken wings	|	Exit	|	Enemy: Paulina</sup></p>

## Usage
When cloned you'll only have to `make` and start the program as `./so_long [map]`. There's a few maps in folder `maps`.

### Library
- As the MXL lib is different for MAC and LINUX, there's a few changes to be made in the `Makefile`, it saved to work with LINUX when cloned, if you want to use it for MAC, you must uncomment (#) the rules commented and comment the ones refering to LINUX. 
<details>
<summary>The ones with # are for MAC</summary>

```
LIBMLX		=	./minilibx-linux/libmlx_Linux.a	
#LIBMLX		=	./mlx/libmlx.a	
```
```
$(LIBMLX):
	@make -C minilibx-linux
#@make -C ./mlx	
```
```
%.o: %.c
	@gcc -g $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@ 
#@gcc $(CFLAGS) -c $(SRC)
```
```
$(NAME): $(OBJ) $(LIBMLX) $(LIBFT)
	@gcc -g $(CFLAGS) $(OBJ) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft -o $(NAME)
#@gcc $(OBJ) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
```
```
libclean:
	@make -C ./minilibx-linux clean
#@make -C ./mlx clean
```
</details>

### Map
If any of these rules fails, the program won't work:
- Only elements available are `P` *(player)*, `E` *(exit)*, `C` *(collectible)*, `1` *(wall)* and `0` *(path)*
- There must be at least one exit, one collectible and there can only be one player
- Must be in `.ber` format
- Must be rectangular and all rows must have the same lenght
- Must be closed
- There must be a path available between the exit and the player

---
## to improve
- [ ] reduce number of player movement functions to 1?
- [ ] enemy moves
- [ ] option to get to next map inmediately after finishing a map, without having to close the window
- [ ] using global variable SIZE to resize images depending on window?
- [ ] using global variables to asign keys properly

## to fix
- [x] reduced number of player movement functions to 2
- [x] reduced number of enemy movement functions to 1
- [ ] change player cell in map_done when moving for better enemy animation?
---
banner and all game assets by me