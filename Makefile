# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynoam </var/mail/ynoam>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/24 22:45:25 by ynoam             #+#    #+#              #
#    Updated: 2020/11/25 10:59:35 by ynoam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = cast_all_rays.c cast_ray.c check_single_position.c draw_all_sprit.c \
			draw_ciell_and_floor.c draw_sprite.c draw_wall.c fill_file_bitmap.c \
			fill_header_bitmap.c ft_add_new_sprite.c ft_addr_of_texture_img.c \
			ft_check_data.c ft_check_first_last_line.c ft_check_map.c \
			ft_check_map_line.c ft_check_space.c ft_check_texture.c \
			ft_check_texture_files.c ft_cos.c ft_distance.c ft_draw.c ft_draw_3d.c \
			ft_file_error.c ft_file_extention.c ft_find_sprit_pos.c ft_init_data.c \
			ft_init_p_view.c ft_is_all_line_one.c ft_is_sprit_visible.c \
			ft_isdata_begin.c ft_ismap_begin.c ft_isnothing.c ft_loop.c ft_map_error.c \
			ft_my_errors.c ft_ray_is_facing.c ft_red_bouton.c ft_setup.c ft_sin.c \
			ft_sort_sprit.c ft_swap_sprit_conts.c ft_sys_error.c ft_take_map.c \
			ft_tan.c ft_texture_error.c ft_update.c ft_update_player.c get_color.c \
			get_resolution.c get_rgb.c get_texture.c has_wall_at.c main.c \
			my_mlx_pixel_put.c my_pixel_get.c normalize_angle.c raycast_hor.c \
			raycast_ver.c read_file.c read_map.c save_image.c selection.c \
			third_argument.c

SRCS = $(addprefix srcs/, $(SRC))

#DEBUG = -g -fsanitize=address

CC = gcc -Werror -Wall -Wextra

FRMWORK_FLG = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRCS) Makefile libft/*.c libft/libft.h
	@make -C libft
	@$(CC) -o $(NAME) $(DEBUG) $(SRCS) libft/libft.a $(FRMWORK_FLG)
	@echo "Compilation of $(NAME):	\033[1;32mOK\033[m"

clean:
	@rm -f libft/*.o

fclean: clean
	@rm -f libft/libft.a $(NAME)
	@echo "$(NAME):	Removing $(NAME)"

re : fclean all

run:
	./$(NAME) maps/map2.cub
save:
	./$(NAME) maps/map2.cub --save
