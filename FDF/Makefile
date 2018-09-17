# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmulamba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/01 07:25:22 by bmulamba          #+#    #+#              #
#    Updated: 2018/07/21 13:46:10 by bmulamba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = display.c \
	  draw.c \
	  hook.c \
	  main.c \
	  parser.c\
	  libft/ft_atoi.c \
	  libft/ft_strsplit.c \
	  libft/readfile.c

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror

LIB = -L/usr/local/lib -lmlx

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(LIB) -framework OpenGL -framework Appkit $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
