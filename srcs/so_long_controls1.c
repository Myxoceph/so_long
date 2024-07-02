/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_controls1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:00:07 by abakirca          #+#    #+#             */
/*   Updated: 2024/05/21 18:00:17 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../libft/inc/libft.h"

int	check_map_len(t_map_data *data)
{
	size_t	i;
	int		j;

	j = 0;
	i = ft_strlen(data->map[0]);
	data->w = i;
	while (data->map[j])
	{
		if (i == ft_strlen(data->map[j]))
			ft_printf("%s\n", data->map[j++]);
		else
			return (ft_putstr_fd("The map is not rectangular or \
there are empty newlines.\n", 2), 1);
	}
	return (0);
}

int	check_one_map(t_map_data *data)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	k = data->w;
	ft_printf("Map data height is : %i\n", data->h);
	while (data->map[j][i])
	{
		if (data->map[j][i] == '1' && data->map[data->h - 1][i] == '1')
			i++;
		else
			return (ft_putstr_fd("The map is incomplete.\n", 2), 1);
	}
	j = 1;
	while (j < data->h - 1)
	{
		if (data->map[j][0] == '1' && data->map[j][k - 1] == '1')
			j++;
		else
			return (ft_putstr_fd("The map is incomplete.\n", 2), 1);
	}
	return (0);
}

int	is_player(t_global *data)
{
	int	i;
	int	j;
	int	num_player;

	num_player = 0;
	j = 0;
	i = 0;
	while (data->mdata->map[j])
	{
		i = 0;
		while (data->mdata->map[j][i])
		{
			if (data->mdata->map[j][i] == 'P')
			{
				num_player++;
				data->pdata->x = i;
				data->pdata->y = j;
			}
			i++;
		}
		j++;
	}
	if (num_player != 1)
		return (ft_putstr_fd("There must be and only one player.\n", 2), 1);
	return (0);
}

int	is_exit(t_map_data *data)
{
	int	i;
	int	j;
	int	num_exit;

	j = 0;
	i = 0;
	num_exit = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'E')
				num_exit++;
			i++;
		}
		j++;
	}
	if (num_exit != 1)
		return (ft_putstr_fd("There must be and only one exit.\n", 2), 1);
	return (0);
}

int	check_map_character(t_map_data *data)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] != 'P' && data->map[j][i] != '1'
				&& data->map[j][i] != '0' && data->map[j][i] != 'E'
				&& data->map[j][i] != 'C')
			{
				return (ft_putstr_fd("Invalid character(s) in map.\n",
						2), 1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
