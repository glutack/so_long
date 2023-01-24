# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irmoreno <irmoreno@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 16:30:09 by irmoreno          #+#    #+#              #
#    Updated: 2022/06/06 16:33:44 by irmoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	libft.a
SRCS		= 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
				ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
				ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c\
				ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
				ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
				ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c
OBJS		= 	${SRCS:.c=.o}
SRCS_BONUS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c 
OBJS_BONUS	=	${SRCS_BONUS:.c=.o}
CFLAGS		= 	-Wall -Wextra -Werror --debug
RM			= 	rm -f
CC			=	gcc

all: $(NAME)

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "Objetos creados"

$(NAME): ${OBJS} 
	@${CC} -c ${CFLAGS} ${SRCS}
	@ar crs ${NAME} ${OBJS}
	@echo "Librería creada"

bonus: $(NAME) ${OBJS_BONUS}
	@ar crs ${NAME} ${OBJS_BONUS}
	@echo "Bonus creado"

clean: 
	@${RM} ${OBJS} ${OBJS_BONUS}
	@echo "Objetos eliminados"

fclean: clean
	@${RM} ${NAME}
	@echo "Librería eliminada"

re: fclean all
	@echo ":D"

.PHONY: all clean fclean re bonus
