# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roliveir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/28 01:21:35 by roliveir          #+#    #+#              #
#    Updated: 2019/06/06 12:25:49 by roliveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -flto -O2 

INC_PATH = includes/
LIB_INC_PATH = libft/includes/
OBJ_PATH = objs/

SRC_PATH = srcs/

LIBFT_FLAG = -Llibft -lft
MLX_FLAG = -lmlx -framework OpenGL -framework AppKit

SRC_NAME = main.c			\
		   key_handler.c	\
		   mouse_handler.c	\
		   getoption.c		\
		   utils.c			\
		   print.c			\
		   fill.c			\
		   calc.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) -I $(INC_PATH) -I $(LIB_INC_PATH)\
		-I minilibx/ $(MLX_FLAG) $(LIBFT_FLAG) -o $(NAME) $(OBJ)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2>&-
$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ)
	@rm -rf $(OBJ_PATH) 2>&-

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
