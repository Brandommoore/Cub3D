/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:02:22 by marvin            #+#    #+#             */
/*   Updated: 2023/03/05 20:02:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Raw data printer
*/
static void	data_printer(t_mapdata map_data)
{
	printf("NO data from RAW_DATA --> %s\n", map_data.raw_data.no_route);
	printf("EA data from RAW_DATA --> %s\n", map_data.raw_data.ea_route);
	printf("WE data from RAW_DATA --> %s\n", map_data.raw_data.we_route);
	printf("SO data from RAW_DATA --> %s\n", map_data.raw_data.so_route);
}

/* Free of data raw_map
*/
static void	datafree(t_mapdata map_data)
{
	free(map_data.raw_data.no_route);
	free(map_data.raw_data.ea_route);
	free(map_data.raw_data.we_route);
	free(map_data.raw_data.so_route);
}

void	parser(char *cub_file)
{
	t_mapdata	map_data;
	int			fd_map;

	map_data.init = 1;
	printf("Parser\n");
	fd_map = open_file_and_check_ext(cub_file, ".cub");
	//printf("Map fd --> %d\n", fd_map);
	read_file(fd_map, &map_data);
	data_printer(map_data);
	close_file(fd_map);
	datafree(map_data);
	(void)map_data;
	(void)cub_file;
}
