#ifndef WOLF_H
# define WOLF_H

# include <stdint.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define VIEW_DIST 10
# define TEX_MAP_SIZE 20

typedef struct		s_rgba
{
	uint8_t		b;
	uint8_t		g;
	uint8_t		r;
	uint8_t		a;
}					t_rgba;

typedef union		u_color
{
	int			value;
	t_rgba		rgba;
}					t_color;

typedef struct		s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
	int			width;
	int			height;
}					t_image;

typedef struct		s_map
{
	int			width;
	int			height;
	int			**values;
}					t_map;

typedef struct		s_vector
{
	float		x;
	float		y;
}					t_vector;

typedef struct		s_cast
{
	int		mx;
	int		my;
	float	sx;
	float	sy;
	float	dx;
	float	dy;
	int		stepx;
	int		stepy;
	float	wall;
}					t_cast;

typedef struct		s_ray
{
	float		x;
	float		y;
	int			side;
	float		dist;
	float		light;
	int			height;
	t_image		*texture;
	int			tex_x;
	float		fx;
	float		fy;
}					t_ray;

typedef struct		s_player
{
	float		x;
	float		y;
	t_vector	d;
	t_vector	p;
}					t_player;

typedef struct		s_mlx
{
	void		*mlx;
	void		*window;
	t_image		*image;
	t_map		*map;
	t_player	player;
	t_image		*tex[TEX_MAP_SIZE];
	int			max_tex;
	t_image		*floor;
	t_image		*ceiling;
}					t_mlx;

t_mlx				*init(void);
t_mlx				*del_mlx(t_mlx *mlx);
void				render(t_mlx *mlx);
int					hook_mousedown(int button, int x, int y, t_mlx *mlx);
int					hook_mouseup(int button, int x, int y, t_mlx *mlx);
int					hook_mousemove(int x, int y, t_mlx *mlx);
int					hook_keydown(int key, t_mlx *mlx);
int					hook_expose(t_mlx *mlx);
t_image				*del_image(t_mlx *mlx, t_image *img);
t_image				*new_image(t_mlx *mlx, int w, int h);
t_image				*xpm_image(char *xpm, t_mlx *mlx);
void				clear_image(t_image *img);
void				image_set_pixel(t_image *image, int x, int y, int color);
t_color				get_pixel(t_image *image, int x, int y);
t_color				clerp(t_color c1, t_color c2, double p);

/*
** Wolf3D functions
*/

void				init_player(t_player *p, t_map *m);
t_map				*read_map(char *fd, int max);
int					get_tile(t_map *m, int x, int y);
int					is_full_map(t_map *m);
int					is_enclosed_map(t_map *m);
void				cast(t_ray *r, t_map *m, t_player *p, t_image *tex[]);
void				rotate_player(t_player *p, float angle);
void				move_player(t_player *p, t_map *m, float distance);
int					load_textures(t_mlx *mlx);
void				draw_minimap(t_mlx *mlx);
#endif
