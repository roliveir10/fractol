/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 23:11:14 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/06 05:53:28 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void			delenv(t_env *env)
{
	mlx_destroy_image(env->mlx.mlx, env->mlx.image);
}

static void		init_mlx(t_env *env)
{
	env->mlx.mlx = mlx_init();
	env->mlx.image = mlx_new_image(env->mlx.mlx, SCREENX, SCREENY);
	env->mlx.id = mlx_new_window(env->mlx.mlx, SCREENX, SCREENY, "fractol");
	env->mlx.mem_image = (unsigned int*)mlx_get_data_addr(env->mlx.image,
			&env->mlx.pix, &env->mlx.size_line, &env->mlx.endian);
}

int				main(int argc, char **argv)
{
	t_env		env;

	ft_bzero(&env, sizeof(t_env));
	if (!getoption(argc, argv, &env))
		return (1);
	init_mlx(&env);
	fill_struct(&env);
	print_manager(&env);
	mlx_hook(env.mlx.id, KEYPRESS, 0, key_press, (void*)&env);
	mlx_hook(env.mlx.id, MOUSEPRESS, 0, mouse_press, (void*)&env);
	mlx_hook(env.mlx.id, MOUSEMOVE, 0, mouse_move, (void*)&env);
	mlx_loop(env.mlx.mlx);
	return (0);
}
