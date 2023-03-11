/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:00:46 by mcordoba          #+#    #+#             */
/*   Updated: 2023/03/05 19:00:46 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{

	printf("\t\033[0;35m----> Cub3d <----\n\033[0m");
	errmanag(argc, argv);
	//system("leaks cub3d");
	printf("\033[0;35m      ----> Cub3d END <----\n\033[0m");
	(void)argc;
	(void)argv;
	return (0);
}
