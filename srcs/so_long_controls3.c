/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_controls3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:11:45 by abakirca          #+#    #+#             */
/*   Updated: 2024/05/27 15:12:03 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long.h"
#include "../libft/inc/libft.h"

void	protection_itoa(t_global *g, char *s, t_map_data *mdata)
{
	if (s == NULL)
	{
		ft_putstr_fd("Itoa Failed.", 2);
		destroy_img(g);
		ft_free(mdata, mdata->h);
		exit (1);
	}
	return ;
}

int	init_new_window(t_global *g)
{
	g->mlx = mlx_init();
	if (g->mlx == NULL)
		return (ft_putstr_fd("Couldn't initialize the mlx.\n", 2), 1);
	g->win = mlx_new_window(g->mlx, g->mdata->w * 64,
			g->mdata->h * 64, "Sonic The Hedgehog");
	if (g->win == NULL)
		return (ft_putstr_fd("Failed to create a new window.\n", 2), 1);
	return (0);
}

int	button_hook(t_global *gdata)
{
	ft_printf("Thanks for playing!\n");
	if (gdata->mdata->map)
		ft_free(gdata->mdata, gdata->mdata->h);
	destroy_img(gdata);
	mlx_destroy_window(gdata->mlx, gdata->win);
	exit (0);
}

static void	pathfind(t_map_data *count, char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x])
		return ;
	if (map[y][x] == 'V' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		count->coll++;
	if (map[y][x] == 'E')
	{
		count->coll++;
		map[y][x] = 'V';
		return ;
	}
	map[y][x] = 'V';
	pathfind(count, map, x - 1, y);
	pathfind(count, map, x + 1, y);
	pathfind(count, map, x, y - 1);
	pathfind(count, map, x, y + 1);
}

int	prep_path_find(t_map_data *data, int x, int y, int i)
{
	t_map_data	*temp;

	temp = malloc(sizeof(t_map_data));
	temp->map = malloc(sizeof(char *) * (data->h));
	if (!temp->map)
		return (ft_putstr_fd("Malloc Failed.\n", 2), 1);
	while (i < data->h)
	{
		temp->map[i] = ft_strdup(data->map[i]);
		if (!temp->map[i])
			return (free(temp->map), free(temp),
				ft_putstr_fd("Pathfind failed.\n", 2), 1);
		i++;
	}
	temp->coll = 0;
	pathfind(temp, temp->map, x, y);
	if (temp->coll != data->coll)
	{
		ft_free(temp, data->h);
		free(temp);
		return (ft_putstr_fd("Cannot reach a collectible or exit.\n", 2), 1);
	}
	ft_free(temp, data->h);
	free(temp);
	return (0);
}
