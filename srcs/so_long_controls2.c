/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_controls2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:27:50 by abakirca          #+#    #+#             */
/*   Updated: 2024/05/27 15:09:44 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "../inc/so_long.h"
#include "../libft/inc/libft.h"
#include "../get_next_line/get_next_line.h"

void	check_map_name(const char *str)
{
	int	i;

	i = ft_strlen(str);
	i--;
	if (str[i] == 'r')
	{
		i--;
		if (str[i] == 'e')
		{
			i--;
			if (str[i] == 'b')
			{
				i--;
				if (str[i] == '.')
					return ;
			}
		}
	}
	else
	{
		ft_putstr_fd("Map extension must be '.ber'\n", 2);
		exit (1);
	}
}

static int	count_lines_extension(char *buf, int fd)
{
	size_t	numlines;

	numlines = 0;
	while (buf != NULL)
	{
		numlines++;
		free(buf);
		buf = get_next_line(fd);
	}
	close(fd);
	return (numlines);
}

int	count_lines(const char *map)
{
	size_t		numlines;
	char		*buf;
	int			fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("The map you have entered does not exist.\n", 2);
		close(fd);
		exit(1);
	}
	numlines = 0;
	buf = get_next_line(fd);
	if (!buf)
	{
		ft_putstr_fd("File's empty, or get_next_line isn't working.\n", 2);
		close(fd);
		exit(1);
	}
	numlines = count_lines_extension(buf, fd);
	return (numlines);
}

int	end_of_file(t_map_data *data)
{
	int	i;
	int	j;

	j = 0;
	data->map[data->h] = NULL;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == '\n')
				data->map[j][i] = '\0';
			i++;
		}
		j++;
	}
	return (0);
}

int	is_coll(t_map_data *data)
{
	int	i;
	int	j;
	int	num_coll;

	j = 0;
	i = 0;
	num_coll = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'C')
				num_coll++;
			i++;
		}
		j++;
	}
	if (num_coll < 1)
		return (ft_putstr_fd("There must be at least one collecible.\n", 2), 1);
	return (0);
}
