# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/20 12:14:15 by tclarita          #+#    #+#              #
#    Updated: 2020/10/25 10:27:25 by tclarita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = wolf.c read_map.c setup.c sdl_window.c key.c update.c tools.c cast_ray.c generate_3d.c render.c

OBJ = $(SRC:.c=.o)

HEADER = wolf.h

FLAGS = -Wall -Wextra -Werror -I $(HEADER)
SDL = -lSDL2

LIBFT = libft

COLOR = \033[2;14m

all: $(NAME)

$(NAME): $(OBJ) $(SRC)
		@make -C $(LIBFT)
		@gcc -c $(SRC)
		@gcc -o $(NAME) $(FLAGS) $(OBJ) $(SDL) -lm libft/libft.a

clean:
		@make clean -C $(LIBFT)
		@rm -rf $(OBJ)

fclean: clean
		@make fclean -C $(LIBFT)
		@rm -rf $(NAME)

re: fclean all