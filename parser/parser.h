/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:55:14 by mcordoba          #+#    #+#             */
/*   Updated: 2023/06/21 13:13:28 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../cub3d.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "../libs/libft/libft.h"
# include "utils/map_functions_data.h"

typedef struct s_cubdat	t_cubdat;

// Struct for util find_map
typedef struct s_fmap
{
	int			l_start;
	int			l_end;
	int			height;
	int			width;
}				t_fmap;

// Struct for save color in rgb mode
typedef struct s_rgbcol
{
	int			r;
	int			g;
	int			b;
}				t_rgbcol;

// Struct for check if data (RAWDATA) is already assigned
typedef struct s_dac
{
	int			no_rut;
	int			so_rut;
	int			we_rut;
	int			ea_rut;
	int			f_col;
	int			c_col;
	int			play_or;
}				t_dac;

// Struct for save RAW data from .cub file
typedef struct s_rawdata
{
	char		*no_route;
	char		*so_route;
	char		*we_route;
	char		*ea_route;
	char		play_orient;
	int			p_pos_x;
	int			p_pos_y;
	int			**map;
	t_rgbcol	f_col;
	t_rgbcol	c_col;
}				t_rawdata;

// Main struct of parser
typedef struct s_mapdata
{
	t_rawdata	raw_data;
	t_dac		dac;
	t_fmap		fmap;
	int			fd_map;
	int			init;
	char		*filename;
}				t_mapdata;

///////////////////////////////////////////
//	parser.c
///////////////////////////////////////////
t_cubdat	parser(char *cub_file);
t_cubdat	mapdat_to_cubdat(t_mapdata *mapdata);

///////////////////////////////////////////
//	parser_err_msg.c
///////////////////////////////////////////
void		errmsg_two_ids(char *type_err);

///////////////////////////////////////////
//	read_file.c
///////////////////////////////////////////
void		read_file(int file_fd, t_mapdata *map_data);
void		print_map_values(t_mapdata *map_data);

///////////////////////////////////////////
//	find_map.c
///////////////////////////////////////////
int			mapl_compat(char *data_line);
int			compare_line_size(int l_len, char *data_line);
t_fmap		find_map(char *filename);

///////////////////////////////////////////
//	save_map.c
///////////////////////////////////////////
void		save_map(t_mapdata *map_data);
void		set_gnl_to_mapinit(char *filename, int init_line, t_smu *smu);
void		allocate_data_map(t_mapdata *map_data, t_smu *smu);
int			trans_map(char c, int char_pos, t_mapdata *mdat, t_smu *sm);

///////////////////////////////////////////
//	other_utils.c
///////////////////////////////////////////
int			ft_hasany(char c, char *set);
int			char_to_int(char c);
void		map_copyer(int **map, int ***map_cpy, int height, int width);

///////////////////////////////////////////
//	data_assigner.c
///////////////////////////////////////////
int			data_assigner(char *data, t_mapdata *map_data);
void		assigner(char *identifier, char *data, t_mapdata *map_data);
void		col_asign(t_rgbcol *col, char *data, int *id_dac);
void		rute_asign(char **rawmap_id, char *data, int *id_dac);

///////////////////////////////////////////
//	assigner_checkers.c
///////////////////////////////////////////
void		init_checker_dac(t_mapdata *map_data);
int			check_id(char *identifier);
int			check_color(char *color);

///////////////////////////////////////////
//	map_checker.c
///////////////////////////////////////////
int			map_checker(int **map, int ply_px, int ply_py);
void		renormalize_map(int **map, int width, int height);

#endif
