/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 03:08:28 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/06 11:58:52 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				fill_struct(t_env *env)
{
	env->fractal[MANDELBROT].x[0] = -2;
	env->fractal[MANDELBROT].x[1] = 1;
	env->fractal[MANDELBROT].y[0] = -1.5;
	env->fractal[MANDELBROT].y[1] = 1.5;
	env->fractal[JULIA].x[0] = -2.5;
	env->fractal[JULIA].x[1] = 2.3;
	env->fractal[JULIA].y[0] = 2.5;
	env->fractal[JULIA].y[1] = -2.6;
	env->fractal[JULIA].zo.re = 0.35;
	env->fractal[JULIA].zo.im = -0.8;
	env->fractal[TRICORN].x[0] = -3.92;
	env->fractal[TRICORN].x[1] = 3.58;
	env->fractal[TRICORN].y[0] = -3.85;
	env->fractal[TRICORN].y[1] = 3.63;
	env->fractal[TRICORN].t_exp = -5;
}

void				fill_offset(t_fractal *fractal, double offx, double offy)
{
	fractal->x[0] += offx;
	fractal->x[1] += offx;
	fractal->y[0] += offy;
	fractal->y[1] += offy;
}

void				fill_z(t_env *env, double re, double im)
{
	env->z.re = re;
	env->z.im = im;
	if (env->type == MANDELBROT)
		env->fractal[MANDELBROT].zo = env->z;
}

void				fill_juliaz(t_env *env, int keycode)
{
	static double	re[7] = {0.35, 0.35, -0.70176, -0.835, -0.8, -0.7269, 0};
	static double	im[7] = {0, 0.01, -0.3842, -0.2321, 0.156, 0.1889, -0.8};
	int				k;

	k = -1;
	if (env->type != JULIA)
		return ;
	(void)keycode;
	while (++k < 7)
		if (env->fractal[JULIA].zo.im == im[k])
		{
			if (k != 6)
			{
				env->fractal[JULIA].zo.im = im[k + 1];
				env->fractal[JULIA].zo.re = re[k + 1];
			}
			else
			{
				env->fractal[JULIA].zo.im = im[0];
				env->fractal[JULIA].zo.re = re[0];
			}
			break ;
		}
	k = k != 6 ? k++ : 0;
	print_manager(env);
}
