# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 16:48:14 by garibeir          #+#    #+#              #
#    Updated: 2023/09/13 16:19:54 by garibeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----- Program name:
NAME	= fdf

#---- Compilation:
CC = cc
CFLAGS = -Imlx -g -O3 -Wall -Werror -Wextra -fsanitize=address
MILIB  = -I /usr/X11/include -g -L /usr/X11/lib -l minilibx-linux -framework OpenGL -framework AppKit

#----- Printf:
FT_PRINTF_PATH	= ./includes/printf 
FT_PRINTF_NAME	= ./includes/printf/printf.a

#----- libft:
FT_LIBFT_PATH	= ./includes/libft
FT_LIBFT_NAME	= ./includes/libft/libft.a

#----- MiniLibx:
MLX_LIB_DIR = ./includes/minilibx-linux/
MLX_INCLUDE = -I minilibx-linux/
LMLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -fPIC

#----- Colors:
DEFAULT = \033[0;92m

#----- Files:
SRC	= ./srcs/fdf.c ./srcs/draw.c ./srcs/keyhandler.c ./srcs/aux.c ./srcs/structcall.c ./srcs/parser.c \
	./srcs/iso.c ./includes/getnextline/get_next_line.c 	./includes/getnextline/get_next_line_utils.c \
	./srcs/aux1.c ./srcs/renderer.c\


OBJ	= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
		@echo "$(DEFAULT)\tCompiling Printf...\n"
		make -s -C $(FT_PRINTF_PATH)
		@echo "$(DEFAULT)\tDone Compiling.\n"
		@echo "$(DEFAULT)\tCompiling libft...\n"
		make -s -C $(FT_LIBFT_PATH)
		@echo "$(DEFAULT)\tDone Compiling.\n"
		@echo "$(DEFAULT)\tCompiling MLX..\n"
		@make -s -C $(MLX_LIB_DIR)
		$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF_NAME) $(FT_LIBFT_NAME)  $(LMLX_FLAGS) $(MLX_INCLUDE) -O3 -o $(NAME)
		@clear
		@echo "$(DEFAULT)\tDone Compiling.\n"

clean:
		make clean -s -C $(FT_PRINTF_PATH)
		make clean -s -C $(FT_LIBFT_PATH) 
		@echo "$(DEFAULT)\tDone cleaning.\n"

fclean:		clean
			$(RM) $(NAME) $(OBJ)
			make -s fclean -C $(FT_PRINTF_PATH)
			make -s fclean -C $(FT_LIBFT_PATH) 
			@clear
			@echo "$(DEFAULT)\tDone function cleaning.\n"

re: fclean all
