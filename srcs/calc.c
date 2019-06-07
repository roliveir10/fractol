/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:57:56 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/06 11:15:47 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int				iter_julia(t_env *env)
{
	int			k;
	double		r;
	double		tmp;

	k = -1;
	while (++k < 70)
	{
		tmp = env->z.re;
		env->z.re = pow(env->z.re, 2) - pow(env->z.im, 2) + getzo(env, 0);
		env->z.im = 2 * tmp * env->z.im + getzo(env, 1);
		r = pow(env->z.re, 2) + pow(env->z.im, 2);
		if (r > 4)
			return (choose_color(k, r));
	}
	return (choose_color(k, r));
}

int				iter_tricorn(t_env *env)
{
	int			k;
	double		r;
	double		tmp;

	k = -1;
	ft_bzero(&(env->fractal[TRICORN].zo), sizeof(t_nbr));
	while (++k < 200)
	{
		tmp = env->z.re;
		env->z.re = pow(env->z.re, 2) - pow(env->z.im, 2) + getzo(env, 0);
		env->z.im = env->fractal[TRICORN].t_exp * tmp
			* env->z.im + getzo(env, 1);
		env->fractal[TRICORN].zo = env->z;
		r = pow(env->z.re, 2) + pow(env->z.im, 2);
		if (r > 4)
			return (choose_color(k, r));
	}
	return (choose_color(k, r));
}
