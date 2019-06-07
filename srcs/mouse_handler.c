/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 04:53:29 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/06 11:59:16 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			get_offset(t_env *env, t_zoom *zoom, int x, int y)
{
	static double	zo[2] = {0.9, 1.1};

	zoom->offx = (x - SCREENX / 2) * (1.0 - zo[zoom->type]);
	zoom->offy = (y - SCREENY / 2) * (1.0 - zo[zoom->type]);
	zoom->offx = getdx(env) * zoom->offx / SCREENX;
	zoom->offy = getdy(env) * zoom->offy / SCREENY;
}

static void			get_zoom(t_env *env, t_zoom *zoom)
{
	static double	zo[2] = {0.9, 1.1};

	zoom->zoom[0] = getdx(env) * (1.0 - zo[zoom->type]);
	zoom->zoom[1] = getdy(env) * (1.0 - zo[zoom->type]);
}

int					mouse_press(int button, int x, int y, void *param)
{
	t_env			*env;
	t_zoom			zoom;
	static int		tmouse[2] = {MOLU, MOLD};

	zoom.type = -1;
	env = (t_env*)param;
	while (++zoom.type < 2)
		if (tmouse[zoom.type] == button)
		{
			get_offset(env, &zoom, x, y);
			get_zoom(env, &zoom);
			env->fractal[env->type].x[0] += zoom.zoom[0] / 2;
			env->fractal[env->type].x[1] -= zoom.zoom[0] / 2;
			env->fractal[env->type].y[0] += zoom.zoom[1] / 2;
			env->fractal[env->type].y[1] -= zoom.zoom[1] / 2;
			fill_offset(&env->fractal[env->type], zoom.offx, zoom.offy);
		}
	print_manager(env);
	return (0);
}

int					mouse_move(int x, int y, void *param)
{
	double			offset;
	t_env			*env;

	(void)x;
	(void)y;
	env = (t_env*)param;
	if (env->type != JULIA || env->fractal[JULIA].j_status == -1)
		return (0);
	offset = env->fractal[JULIA].j_status ? 0.0005 : -0.0005;
	env->fractal[JULIA].zo.re += offset;
	print_manager(env);
	return (1);
}
