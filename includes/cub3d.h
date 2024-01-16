/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:53:05 by abazerou          #+#    #+#             */
/*   Updated: 2024/01/14 19:02:11 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "stdio.h"
# include "stdlib.h"
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../Libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

# define HEIGHT 1000
# define WIDTH 1500
# define SIZE 128
# define MINI 0.1
# define MAX_ALLOC 7440737
# define W  13
# define S  1
# define A  0
# define D  2
// extern int NUM;

//******* TEXTURES STRUCT ********
typedef struct s_img
{
	int				tofx;
	int				tofy;
	void			*img;
	unsigned int	*addr;
	unsigned int	*color;
	int				bitppixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}	t_img;

//********* WALLS **********
typedef struct s_walls
{
	double	pwheight;
	double	distanceproj;
	double	correct_dis;
	int		dif;
	int		top_pix;
	int		wbottompx;
	int		w_stripeheight;
}	t_walls;

//****** PLAYER DIRECTION PATHS ********
typedef struct s_paths
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_paths;

//****** PLAYER DIRECTION PATHS ******
typedef struct s_rgb
{
	int	floor;
	int	ceiling;

}	t_rgb;

//****** PLAYER informations ******

typedef struct s_player
{
	int		x;
	int		y;
	int		radius;
	int		turn_dirct;
	int		walk_dirct;
	double	rot_angle;
	double	move_speed;
	double	rot_speed;
}	t_player;

//********** DATA IMG ***********
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_data;

//********** INFO ***********
typedef struct s_info
{
	int			tail_size;
	int			map_rows;
	int			map_cols;
	int			win_width;
	int			win_higth;
	int			player_x;
	int			player_y;
	int			fov_angle;
	int			wall_width ;
	int			num_rays;
	char		player_rot;
	t_player	player	;		
}	t_info;

//********** INTERSECTION ***********
typedef struct s_inter
{
	double	x;
	double	y;
	double	dist;
	bool	hit_v;
	bool	hit_h;
}	t_inter;

//********** RAYS ***********
typedef struct s_ray
{
	double	ray_angle;
	double	hit_x;
	double	hit_y;
	double	distance;
	int		hit_vertical;
	int		facing_up;
	int		facing_down;
	int		facing_right;
	int		facing_left;
	int		hit_content;

}	t_ray;
//******** PARSING STRUCT *****************
typedef struct s_var
{
	char	**map;
	char	**new_map;
	char	*new_line;
	char	**numbers;
	char	*f;
	char	*c;
	char	*s;
	char	*str[4];
	int		fd;
	int		fd1;
	int		i;
	int		j;
	int		n;
	int		x;
	int		y;
	int		v;
	int		index;
	int		found;
	int		flag;
	int		skip;
	int		map_len;
	int		map_pos;
	int		player_pos;
	int		flag_f;
	int		flag_c;
	int		start;
	int		start_j;
	int		save;
	int		is_floor;
	char	*s_trim;
	int		b;
	int		z;
	size_t	big_line;
	size_t	len_s;
	t_paths	*paths;
	t_rgb	*rgb;
	char	**real_map;

}	t_var;

//******** MLX STRUCT ********
typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	t_var		*v;

}	t_mlx;

// ********** FD UTILS ***********
typedef struct s_fds
{
	int	fd0;
	int	fd00;
	int	fd1;
	int	fd01;
	int	fd2;
	int	fd02;
	int	fd3;
	int	fd03;
}	t_fds;

//********** STRUCT ***********
typedef struct s_struct
{
	int				tail_size;
	int				map_rows;
	int				map_cols;
	int				win_width;
	int				win_higth;
	double			player_x;
	double			player_y;
	double			real_x;
	double			real_y;
	double			fov_angle;
	int				wall_width ;
	int				num_rays;
	char			**map;
	char			**vmap;
	void			*mlx;
	void			*win;
	int				x;
	int				y;
	int				radius;
	int				turn_dirct;
	int				walk_dirct;
	double			rot_angle;
	double			move_speed;
	double			rot_speed;
	double			delta_x;
	double			delta_y;
	int				floor;
	int				ceiling;
	void			*g_collector[MAX_ALLOC];
	long long int	alloc_count;
	t_data			img;
	t_img			*no;
	t_img			*so;
	t_img			*we;
	t_img			*ea;
	t_ray			*rays;
	t_rgb			*rgb;
	t_paths			paths;

}	t_struct;

//******** REAL STRUCT ********
typedef struct s_real
{
	char	*line;
	int		i;
	int		begin;
	size_t	j;
	char	*set;
	size_t	len;
	char	*tmp;
	int		k;
}	t_real;

typedef struct s_point
{
	double	dist;
	double	x;
	double	y;
	double	x_intercept;
	double	y_intercept;
	double	y_step;
	double	x_step;
	double	next_x;
	double	next_y;
	double	x_check;
	double	y_check;
}	t_point;

//*********** PARSING *************
void	parsing(t_var *v, t_paths **path);
void	ft_puterror(char *s, int fd);
void	check_ex(char *s);
int		get_biggest_line(char **str);
void	parse_path(char **map, t_var *v);
int		check_right(char *map, int i);
int		check_left(char *map, int i);
int		check_up(char **map, int i, int j);
int		check_down(char **map, int i, int j, t_var *v);
char	**join_space(char **map, t_var *v);
int		count_directions(char **map, t_var *v);
void	ft_freetab(char **map);
void	get_map_len(t_var *v, char *str);
int		read_map(t_var *v);
char	**fill_empty(char **map, t_var *v);
void	check_valid_chars(char **map, t_var *v);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(char *s1, char *s2);
void	search_map(char **map, t_var *v);
int		check_digit(char **str, int i, int j);
void	count_id(t_var *v, int i, int j);
void	start_parser(t_var *v, int i, int j);
int		check_id(t_var *v, t_paths **path);
int		is_comma(char **str, int i, int j);
int		check_digit(char **str, int i, int j);
int		check_after_d(char **str, int i, int j);
void	is_opened(char *s[]);
void	check_rgb_range(t_var *v, int i, int j);
void	is_range_valid(t_var *v, char **numbers);
void	is_rgb_valid(t_var *v);
void	check_id_help(t_var *v, int i, int n);
void	ft_free(char *s[]);
void	get_player_pos(t_var *v);
int		ft_strchrr(const char *string, int searchedChar);
void	init_player(t_struct **s);
void	ft_freemap(char **s);
void	rgb_finalparser(t_var *v, char **numbers);
void	*my_malloc(size_t size, t_struct **s);
void	free_all(t_struct *s, t_var *v);
void	get_path_pos(t_var *v, int i, int j);
void	p_validation_help(t_var *v, int i);
void	fill_path(char *s[], t_paths **paths, int index, int i);
void	helper(t_var *v);
void	skip_space(t_var *v);
void	check_dup(char **map, t_var *v);
void	check_last_line(char **map, t_var *v);
void	help_line(t_var *v, char **map);

//******** GRAPHICS ***********
void	info_init(t_struct **s);
void	put_pixels(t_struct **s, t_paths **path);
void	put_(t_struct **s);
void	rendr_util(t_struct **s, t_walls *wall, t_ray *ray);
void	render_walls(t_struct **s, int x, int texture, t_ray *ray);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	read_textures(t_struct **s, t_paths **path);
int		check_wall_hit(t_struct **s, int texture, t_ray *ray);
int		get_color(t_struct **s, int texture, int wheight, int wall_dif);
void	scale_img(t_img *img, int x, int y, t_struct **s);
int		get_vertical_texture(t_struct **s, t_ray *ray);
int		get_horizontal_texture(t_struct **s, t_ray *ray);
int		search_pixel(t_img *img, int wheight, int wall_dif);

//******** Ray Casting ***********
void	real_map(t_var *var, t_struct **s);
t_real	free_real(t_struct **s, t_real r);
t_real	help2_real(t_var *var, t_struct **s, t_real r);
t_real	help_real(t_var *var, t_real r);
char	*pure_strtrim(char const *s1, char const *set);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strchrr(const char *string, int searchedChar);
void	main2(	t_paths	*paths, t_struct *s, t_var v);
double	distance(double xb, double yb, double xe, double ye);
int		wall_collision(double x, double y, t_struct **s);
int		wall_check(double x, double y, t_struct **s);
t_inter	h_intersect(t_ray ray, t_struct **s);
t_inter	v_intersect(t_ray ray, t_struct **s);
int		key_pressed(int key_code, t_struct **s);
int		key_released(int key_code, t_struct **s);
int		key_exit(int key_code, t_info *info);
t_ray	is_facing(t_ray ray);
void	cast_rays(t_struct **s);
int		in_map(t_point p, t_struct **s);
t_inter	fill_vert(t_inter	interv, t_point p, t_struct **s);
t_inter	fill_horis(t_inter	interv, t_point p, t_struct **s);
int		update_info( t_struct **s);
void	norm(t_struct **s);
double	normalize(double angle);
t_ray	fill_info(t_inter r1, t_ray ray, int vert);
void	ft_direction(t_struct **s, int j, int i);
void	freemap(t_struct **s);
#endif