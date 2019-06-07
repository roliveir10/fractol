/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 23:09:55 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/06 11:58:09 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACTOL_H
# define _FRACTOL_H

# include "libft.h"

# define SCREENX 1250
# define SCREENY 1250
# define NTYPE 3

typedef enum		e_event
{
	KEYPRESS = 2,
	MOUSEPRESS = 4,
	MOUSEMOVE = 6
}					t_event;

typedef enum		e_key
{
	KESCAP = 53,
	KLEFT = 123,
	KRIGHT,
	KDOWN,
	KUP,
	STATUS = 49,
	BLOCK = 11,
	CHANGEI = 0,
	KEYT = 17
}					t_key;

typedef enum		e_mouse
{
	MOLU = 4,
	MOLD = 5
}					t_mouse;

typedef enum		e_type
{
	MANDELBROT,
	JULIA,
	TRICORN
}					t_type;

typedef struct		s_mlx
{
	void			*mlx;
	void			*image;
	void			*id;
	unsigned int	*mem_image;
	int				pix;
	int				size_line;
	int				endian;
}					t_mlx;

typedef struct		s_nbr
{
	double			re;
	double			im;
}					t_nbr;

typedef struct		s_fractal
{
	double			x[2];
	double			y[2];
	t_nbr			zo;
	char			j_status;
	double			t_exp;
}					t_fractal;

typedef struct		s_zoom
{
	double			zoom[2];
	double			offx;
	double			offy;
	int				type;
}					t_zoom;

typedef	struct		s_env
{
	t_mlx			mlx;
	int				type;
	t_fractal		fractal[NTYPE];
	t_nbr			z;
}					t_env;

void				delenv(t_env *env);
int					getoption(int argc, char **argv, t_env *env);
int					iter_julia(t_env *env);
int					iter_tricorn(t_env *env);

/*
**	events
*/

int					key_press(int keycode, void *param);
int					mouse_press(int keycode, int x, int y, void *param);
int					mouse_move(int x, int y, void *param);

/*
**	print
*/

void				print_manager(t_env *env);
int					choose_color(int k, double r);

/*
**	fill
*/

void				fill_struct(t_env *env);
void				fill_z(t_env *env, double re, double im);
void				fill_offset(t_fractal *fractal, double offsetx,
		double offsety);
void				fill_juliaz(t_env *env, int keycode);

/*
**	utils
*/

double				getx(t_env *env, int born);
double				gety(t_env *env, int born);
double				getzo(t_env *env, int part);
double				getdx(t_env *env);
double				getdy(t_env *env);
#endif
