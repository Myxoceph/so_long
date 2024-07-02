/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:49:20 by abakirca          #+#    #+#             */
/*   Updated: 2024/05/27 15:12:12 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "../mlx/mlx.h"
#include "../inc/so_long.h"
#include "../libft/inc/libft.h"
#include "../get_next_line/get_next_line.h"

static int	map_controls(t_global *gdata)
{
	if (end_of_file(gdata->mdata))
		return (1);
	if (check_map_len(gdata->mdata))
		return (1);
	if (check_one_map(gdata->mdata))
		return (1);
	if (is_player(gdata))
		return (1);
	if (is_exit(gdata->mdata))
		return (1);
	if (is_coll(gdata->mdata))
		return (1);
	if (check_map_character(gdata->mdata))
		return (1);
	if (gdata->mdata->h > 128 || gdata->mdata->w > 128)
		return (ft_putstr_fd("Too big of a map for MLX\n", 2), 1);
	return (0);
}

int	ft_controls(char *av, t_global *gdata, int i)
{
	int	fd;

	check_map_name(av);
	gdata->mdata->h = count_lines(av);
	gdata->mdata->map = malloc(sizeof(char *) * (gdata->mdata->h + 1));
	if (!gdata->mdata->map)
		return (ft_putstr_fd("Malloc failed.\n", 2), 1);
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (ft_putstr_fd("Open function failed.\n", 2), 1);
	}
	while (i < gdata->mdata->h)
	{
		gdata->mdata->map[i] = get_next_line(fd);
		if (!gdata->mdata->map[i])
			ft_free(gdata->mdata, -1);
		i++;
	}
	if (map_controls(gdata))
		return (close (fd), 1);
	close(fd);
	return (0);
}

void	ft_free(t_map_data *data, int h)
{
	int	i;

	i = 0;
	if (h == -1)
	{
		free(data->map);
		ft_putstr_fd("Get_next_line failed.\n", 2);
		exit (1);
	}
	if (data)
	{
		while (i < h)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	return ;
}

int	can_move(t_global *g, t_map_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		return (0);
	else if (data->map[y][x] == 'C')
	{
		data->map[y][x] = '0';
		data->coll--;
	}
	else if (data->map[y][x] == 'E' && data->coll != 1)
	{
		return (0);
	}
	else if (data->map[y][x] == 'E' && data->coll == 1)
	{
		ft_printf("Congrats! You finished the level!\n", 0, 0);
		ft_free(data, data->h);
		mlx_destroy_window(g->mlx, g->win);
		exit(0);
	}
	return (1);
}

void	collectible_counter(t_map_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->h && j < data->w)
	{
		while (j < data->w)
		{
			if (data->map[i][j] == 'C' || data->map[i][j] == 'E')
				data->coll++;
			j++;
		}
		j = 0;
		i++;
	}
}
