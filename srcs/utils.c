/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 03:18:37 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/06 10:14:26 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double				getx(t_env *env, int born)
{
	return (env->fractal[env->type].x[born]);
}

double				gety(t_env *env, int born)
{
	return (env->fractal[env->type].y[born]);
}

double				getzo(t_env *env, int part)
{
	if (!part)
		return (env->fractal[env->type].zo.re);
	return (env->fractal[env->type].zo.im);
}

double				getdx(t_env *env)
{
	return (getx(env, 1) - getx(env, 0));
}

double				getdy(t_env *env)
{
	return (gety(env, 1) - gety(env, 0));
}
