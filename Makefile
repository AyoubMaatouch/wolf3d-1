# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynoam </var/mail/ynoam>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/24 22:45:25 by ynoam             #+#    #+#              #
#    Updated: 2020/10/23 18:19:29 by ynoam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
NAME = cub3d

SRC = srcs/*.c

CC = gcc -Werror -Wall -Wextra

FRMWORK_FLG = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC) srcs/* Makefile libft/*.c libft/libft.h
	@make -C libft
	@$(CC) $(SRC) libft/libft.a -o $(NAME) $(FRMWORK_FLG)
#gcc -Werror -Wall -Wextra srcs/*.c libft/libft.a -o test
	@echo "Compilation of $(NAME):	\033[1;32mOK\033[m"

clean:
	@rm -f libft/*.o

fclean: clean
	@rm -f libft/libft.a $(NAME)
	@echo "$(NAME):	Removing $(NAME)"

re : fclean all

run:
	./$(NAME) maps/map2.cub