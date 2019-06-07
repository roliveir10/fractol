/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 02:42:40 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/06 11:15:45 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int				choose_color(int k, double r)
{
	if (k == 70)
	{
		return (1);
	}
	else if (k < 15)
		return (2 * 209674 + 239674);
	return (k * 209674 + 100000 / r);
}

static void		print(t_env *env, int x, int y, int color)
{
	int			sline;

	sline = env->mlx.size_line;
	if (x < 0 || x > SCREENX || y < 0 || y > SCREENY)
		return ;
	env->mlx.mem_image[y * (sline / 4) + x] = color;
}

void			print_manager(t_env *env)
{
	int			i;
	int			j;
	double		x;
	double		y;
	static int	(*lst_function[3])(t_env*) = {iter_julia, iter_julia,
		iter_tricorn};

	i = 0;
	while (++i < SCREENY)
	{
		y = gety(env, 0) + (gety(env, 1) - gety(env, 0)) / SCREENY * i;
		j = 0;
		while (++j < SCREENX)
		{
			x = getx(env, 0) + (getx(env, 1) - getx(env, 0)) / SCREENX * j;
			fill_z(env, x, y);
			print(env, j, i, lst_function[env->type](env));
		}
	}
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.id, env->mlx.image, 0, 0);
}
