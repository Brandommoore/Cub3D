/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:00:09 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/09 15:25:09 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	draw_line(t_game *game)
{
	float	radian;
	int		x;
	int		y;
	int		i;

	radian = game->p_angle * (PI / 180); /* converts de angle to a radians */
	i = -1;
	while (i++ < 10)
	{
		x = game->p_x + i * cos(radian);
		y = game->p_y + i * sin(radian);
		mlx_pixel_put(game->mlx, game->wido, x, y, 0xFFFFFF);
	}
}

void	draw_square(t_game *game)
{
	int start_x;
	int start_y;
	int x;
	int y;

	start_x = game->p_x - 2.5;
	start_y = game->p_y - 2.5;
	y = start_y - 0.5;
	while (++y < start_y + 5)
	{
		x = start_x - 0.5;
		while (++x < start_x + 5)
			mlx_pixel_put(game->mlx, game->wido, x, y, 0xFFFFFF);
	}
}

void	draw_sky_floor(t_game *game)
{
	int x;
	int y;

	y = -1;
	while (++y < 360)
	{
		for (x = 0; x < 1080; x++)
		{
			int position = (y * game->l_size) + (x * (game->bpp / 8));
			game->bkgrn_data[position] = (unsigned char)255; // Asignar componente rojo (0-255)
			game->bkgrn_data[position + 1] = (unsigned char)100; // Asignar componente verde (0-255)
			game->bkgrn_data[position + 2] = (unsigned char)100; // Asignar componente azul (0-255)
		}
	}
	y = 359;
	while (++y < 720)
	{
		for (x = 0; x < 1080; x++)
		{
			int position = (y * game->l_size) + (x * (game->bpp / 8));
			game->bkgrn_data[position] = 100; // Asignar componente rojo (0-255)
			game->bkgrn_data[position + 1] = 100; // Asignar componente verde (0-255)
			game->bkgrn_data[position + 2] = 100; // Asignar componente azul (0-255)
		}
	}
}

void draw_rays(t_game *game)
{
	int	cord;
	int column;
	float radian;
	float p_x;
	float p_y;
	int tex_x, tex_y;

	cord = 1;
	radian = game->p_angle * (PI / 180);
	p_x = game->p_x;
	p_y = game->p_y;
	column = -1;
	while (++column < 1080)
	{
		float angle = radian + atan((column - 540) / 480.0); // modifica anchura del bloque
		float distance = 0.0;
		float delta_x = cos(angle);
		float delta_y = sin(angle);
		while (game->map[(int)p_y / 16][(int)p_x / 16] != 1)
		{
			p_x += delta_x * 0.01;
			p_y += delta_y * 0.01;
			distance += sqrt(delta_x * delta_x + delta_y * delta_y) * 0.000001;
		}
		float cell_x = (p_x / 16) - (int)(p_x / 16);
		float cell_y = (p_y / 16) - (int)(p_y / 16);
		if (cell_x < 0.5)
		{
			if (cell_y < 0.5)
				cord = 1;
			else
			cord = 4;
		}
		else
		{
			if (cell_y < 0.5)
				cord = 2;
			else
        		cord = 3;
		}
		float wall_height = (720 / (distance * cos(angle - radian))) * 0.001;
		int wall_start = (720 - wall_height) / 2;
		int wall_end = wall_start + wall_height;
		int y = -1;
		while (++y < 720)
		{
			if (y >= wall_start && y <= wall_end && cord > 0 && cord < 5)
			{
				tex_y = (int)(64 * ((y - wall_start) / wall_height));
				if (cord % 2 == 0) // norte y sur
    				tex_x = (int)(64 * ((p_x / 16) - (int)(p_x / 16)));
				else // este y oeste
    				tex_x = (int)(64 * ((p_y / 16) - (int)(p_y / 16)));
				if (tex_x < 0) tex_x = 0;
				if (tex_x > 63) tex_x = 63;
				int color = ((int *)game->new_text_data[cord - 1])[tex_y * 64 + tex_x];
				mlx_pixel_put(game->mlx, game->wido, column, y, color);
			}
		}
		p_x = game->p_x;
		p_y = game->p_y;
	}
}

