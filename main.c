/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:00:46 by mcordoba          #+#    #+#             */
/*   Updated: 2023/05/24 10:35:04 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{

	printf("\t\033[0;35m----> Cub3d <----\033[0m\n");
	errmanag(argc, argv);
	//system("leaks cub3d");
	raycast();
	printf("\033[0;35m      ----> Cub3d END <----\033[0m\n");
	(void)argc;
	(void)argv;
	return (0);
}
