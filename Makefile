# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynoam </var/mail/ynoam>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/24 22:45:25 by ynoam             #+#    #+#              #
#    Updated: 2020/11/05 11:58:10 by ynoam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
NAME = cub3d

SRC = srcs/*.c

#DEBUG = -g -fsanitize=address

CC = gcc -Werror -Wall -Wextra

FRMWORK_FLG = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC) srcs/* Makefile libft/*.c libft/libft.h
	@make -C libft
	@$(CC) $(DEBUG) $(SRC) libft/libft.a -o $(NAME) $(FRMWORK_FLG)
	@echo "Compilation of $(NAME):	\033[1;32mOK\033[m"

clean:
	@rm -f libft/*.o

fclean: clean
	@rm -f libft/libft.a $(NAME)
	@echo "$(NAME):	Removing $(NAME)"

re : fclean all

run:
	./$(NAME) maps/map2.cub
