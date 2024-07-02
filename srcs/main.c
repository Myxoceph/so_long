/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:56:35 by abakirca          #+#    #+#             */
/*   Updated: 2024/05/22 16:05:19 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../libft/inc/libft.h"

int	main(int ac, char **av)
{
	t_pos		pdata;
	t_sprite	sdata;
	t_map_data	mdata;
	t_global	gdata;

	gdata.pdata = &pdata;
	gdata.sdata = &sdata;
	gdata.mdata = &mdata;
	if (ac != 2)
		return (ft_putstr_fd("Usage = './so_long [map]'\n", 2), 1);
	if (ft_controls(av[1], &gdata, 0))
		return (ft_free(gdata.mdata, gdata.mdata->h), 1);
	if (start_game(&gdata))
	{
		ft_free(gdata.mdata, gdata.mdata->h);
		return (1);
	}
	return (0);
}
