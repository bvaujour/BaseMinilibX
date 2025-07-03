/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:48:01 by bvaujour          #+#    #+#             */
/*   Updated: 2025/07/03 18:54:24 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "stdbool.h"
#include "stdlib.h"

#define WIDTH 800
#define HEIGHT 600

typedef struct	s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
}				t_keys;

typedef struct	s_data
{
    void	*mlx;
	void	*win;
	t_keys	keys;
}				t_data;

int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}


void	init(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->keys.a = false;
	data->keys.w = false;
	data->keys.s = false;
	data->keys.d = false;
}

int	keypress(int key, t_data *data)
{
	if (key == 'a')
		data->keys.a = true;
	if (key == 's')
		data->keys.s = true;
	if (key == 'd')
		data->keys.d = true;
	if (key == 'w')
		data->keys.w = true;
	return (0);
}

int	keyrelease(int key, t_data *data)
{
	if (key == 'a')
		data->keys.a = false;
	if (key == 's')
		data->keys.s = false;
	if (key == 'd')
		data->keys.d = false;
	if (key == 'w')
		data->keys.w = false;
	return (0);
}

int	frame(t_data *data)
{
	(void)data;
	return (0);
}

int	main()
{
	t_data data;

	init(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "BSP");
	mlx_hook(data.win, 17, 1L << 17, destroy, &data);
	mlx_hook(data.win, 2, 1L << 0, keypress, &data);
	mlx_hook(data.win, 3, 1L << 1, keyrelease, &data);
	mlx_loop_hook(data.mlx, frame, &data);
	mlx_loop(data.mlx);
}