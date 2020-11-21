/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:26:58 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/20 16:45:42 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The variable endian is little because the representation , example:
** int 0x01234567
** 67 45 23 01
** the representation is the inverse.
*/

#ifndef CUB3D_H
# define CUB3D_H

/*
** Include header files.
*/

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "read_file.h"

/*
** Macros for LINUX.
*/

# define LINUX_KEY_ESC 		65307
# define LINUX_DOWN_ARROW	65364
# define LINUX_LEFT_ARROW	65361
# define LINUX_RIGHT_ARROW	65363
# define LINUX_UP_ARROW		65362
# define LINUX_KEY_H		104
# define LINUX_KEY_J		106
# define LINUX_KEY_K		107
# define LINUX_KEY_L		108

/*
** Macros for MAC.
*/

# define MAC_DOWN_ARROW		125
# define MAC_KEY_ESC		53
# define MAC_LEFT_ARROW		123
# define MAC_RIGHT_ARROW	124
# define MAC_UP_ARROW		126
# define MAC_KEY_H			4
# define MAC_KEY_J			38
# define MAC_KEY_K			40
# define MAC_KEY_L			37
# define MAC_KEY_W			13
# define MAC_KEY_A			0
# define MAC_KEY_S			1
# define MAC_KEY_D			2

/*
** Macros.
*/

# define FOV_ANGLE			60
# define FALSE				0
# define TRUE				1
# define TILE_SIZE			64
# define MINIMAP_SCALE		0.4

/*
** Macro for Colors.
*/

# define RED				0xff0000
# define WHITE				0xffffff
# define GOLD				0xffd700
# define BLUE				0x0000ff
# define SKY				0x87ceeb
# define GREEN				0x32CD32
# define AQUA				0x00ffff
# define BROWN				0xCD853F
# define ORAN				16744448
# define MORAN				666633333
# define NORTHCOL			16754448
# define EASTCOL			36754448
# define SOUTHCOL			56754448
# define WESTCOL			76754448
# define CEILCOLOR			204000000
# define FLOORCOLOR			502142110

/*
** My data type.
*/

typedef	struct	s_ray
{
	float			ray_angle;
	float			wall_hitx;
	float			wall_hity;
	float			distance;
	int				was_hit_ver;
	int				is_rayfacing_up;
	int				is_rayfacing_down;
	int				is_rayfacing_left;
	int				is_rayfacing_right;
	int				wall_content;
}				t_rays;

typedef	struct	s_images
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_images;

typedef struct	s_four_var
{
	int		var1;
	int		var2;
	int		var3;
	int		var4;
}				t_four_var;

struct			s_texture
{
	char			*file;
	void			*img;
	int				*addr;
	int				width;
	int				height;
	int				bpp;
	int				line_length;
	int				endian;
};

typedef	struct	s_sprit
{
	float			x;
	float			y;
	float			screen_x;
	float			screen_y;
	float			size;
	float			distance;
	int				visible;
	struct s_sprit	*next;
}				t_sprit;

/*
** Global variables.
*/

/*
** Player data.
** x, y the position of the player in the win.
** direction = the direction of the view of the player.
** mov_speed = how many pixels the player move one time.
** if (walk = 1) = go forward.
** if (walk = -1) = go backward.
** turn = 1 , go left, turn = -1 , go right.
*/

struct			s_player
{
	float	rotation;
	float	direction;
	float	x;
	float	y;
	float	mov_speed;
	float	radius;
	int		walk;
	int		turn;
	int		lateral;
}				g_player;

struct s_texture	g_txtr_n;
struct s_texture	g_txtr_e;
struct s_texture	g_txtr_s;
struct s_texture	g_txtr_w;
struct s_texture	g_txtr_sprit;

t_sprit	*g_sprits_ptr;

/*
** My functions.
*/

char			*fill_header_bitmap(void);
double			ft_cos(double angle);
double			ft_sin(double angle);
float			ft_distance(float x, float y);
float			ft_tan(float l_angle);
float			normalize_angle(float angle);
int				ft_loop(int l_key);
int				ft_red_bouton(int key);
int				ft_texture_error(char *str);
int				has_wall_at(float x, float y);
int				mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
int				my_pixel_get(int x, int y, int wich_txtr);
t_sprit			*ft_add_new_sprite(int y, int x);
void			cast_all_rays(t_rays l_rays[]);
void			cast_ray(t_rays *pointer);
void			draw_all_sprit(t_images *img, t_rays ray[]);
void			draw_sprite(int arr[], t_sprit *ptr,
				t_images *img, t_rays ray[]);
void			fill_file_bitmap(t_images img);
void			ft_addr_of_texture_img();
void			ft_check_data(void);
void			ft_check_texture(void);
void			ft_draw(void);
void			ft_draw_3d(t_images *img, t_rays ray[]);
void			ft_draw_all_rays(t_rays l_rays[]);
void			ft_draw_circle(double x, double y);
void			ft_draw_circle_with_img(t_images *img, float x, float y);
void			ft_draw_column(t_images *img, float x, float y, float height);
void			ft_draw_map_2d(void);
void			ft_draw_map_2d_with_img(t_images *img);
void			ft_draw_p_2d_with_img(t_images *img);
void			ft_draw_p_direction(t_images *img);
void			ft_draw_player(void);
void			ft_draw_rays_with_img(t_images *img, t_rays rays[]);
void			ft_draw_square(int x, int y, int color);
void			ft_draw_square_with_img(t_images *img, int x, int y, int color);
void			ft_find_sprit_pos(void);
void			ft_init_p_view(void);
void			ft_is_sprit_visible(void);
void			ft_ray_is_facing(t_rays *ray);
void			ft_setup(const char *file);
void			ft_sort_sprit(void);
void			ft_swap_sprit_conts(t_sprit *one, t_sprit *two);
void			ft_update(int l_key);
void			ft_update_player(void);
void			my_mlx_pixel_put(t_images *data, int x, int y, int color);
void			save_image(void);
void			third_argument(char *str);
void			ft_check_first_last_line(void);
int				ft_check_space(size_t j, char *str);
void			check_single_position(void);
void			draw_ciell_and_floor(t_images *img, int x,
				int wall_top_pxl, int wall_bottom_pxl);

void			draw_wall(t_images *img, t_rays ray[], int arr[]);

#endif
