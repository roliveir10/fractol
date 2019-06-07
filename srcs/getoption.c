/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getoption.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 00:04:57 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/06 12:25:28 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			usage(void)
{
	int				i;

	i = -1;
	ft_putendl_fd("usage: ./fractol [type]", 2);
	ft_putendl_fd("type: mandelbrot | julia | tricorn", 2);
	return (0);
}

int					getoption(int argc, char **argv, t_env *env)
{
	static char		*type[3] = {"mandelbrot", "julia", "tricorn"};
	int				i;

	i = -1;
	if (argc < 2)
		return (usage());
	else
	{
		while (++i < NTYPE)
			if (!ft_strcmp(type[i], argv[1]))
			{
				env->type = i;
				break ;
			}
		if (i == NTYPE)
			return (usage());
	}
	return (1);
}
