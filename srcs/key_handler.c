/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 23:53:01 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/06 11:15:43 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

static void			key_escap(t_env *env, int keycode)
{
	(void)keycode;
	delenv(env);
	exit(1);
}

static void			key_move(t_env *env, int keycode)
{
	double			offsetx;
	double			offsety;

	offsetx = (getx(env, 1) - getx(env, 0)) / SCREENX * 10;
	offsety = (gety(env, 1) - gety(env, 0)) / SCREENY * 10;
	if (keycode == KLEFT)
		fill_offset(&env->fractal[env->type], -offsetx, 0);
	else if (keycode == KRIGHT)
		fill_offset(&env->fractal[env->type], offsetx, 0);
	else if (keycode == KUP)
		fill_offset(&env->fractal[env->type], 0, -offsety);
	else if (keycode == KDOWN)
		fill_offset(&env->fractal[env->type], 0, offsety);
	print_manager(env);
}

static void			key_julia(t_env *env, int keycode)
{
	int				status;

	if (env->type != JULIA)
		return ;
	status = env->fractal[JULIA].j_status;
	if (keycode == STATUS)
	{
		if (status == 1)
			status = 0;
		else if (!status)
			status = 1;
	}
	else if (keycode == BLOCK)
		status = status == -1 ? 0 : -1;
	env->fractal[JULIA].j_status = status;
}

static void			key_t(t_env *env, int keycode)
{
	(void)keycode;
	if (env->type != TRICORN)
		return ;
	env->fractal[TRICORN].t_exp += 0.05;
	if (env->fractal[TRICORN].t_exp > 2)
		env->fractal[TRICORN].t_exp = -10.0;
	print_manager(env);
}

int					key_press(int keycode, void *param)
{
	static int		tkey[9] = {KESCAP, KLEFT, KRIGHT, KDOWN, KUP,
		STATUS, BLOCK, CHANGEI, KEYT};
	static void		(*lst_function[9])(t_env*, int) = {
		key_escap, key_move, key_move, key_move, key_move, key_julia,
		key_julia, fill_juliaz, key_t};
	int				i;

	i = -1;
	while (++i < 9)
		if (tkey[i] == keycode)
			lst_function[i]((t_env*)param, keycode);
	return (0);
}
