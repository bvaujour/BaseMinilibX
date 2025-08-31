/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injah <injah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:19:07 by injah             #+#    #+#             */
/*   Updated: 2025/08/31 14:21:30 by injah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "mlx.h"
# include "stdbool.h"
# include "stdlib.h"
# include "libft.h"

# define WIDTH 1000
# define HEIGHT 600

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

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

#endif