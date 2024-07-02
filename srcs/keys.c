/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:07:25 by abakirca          #+#    #+#             */
/*   Updated: 2024/05/27 15:11:43 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long.h"
#include "../libft/inc/libft.h"

static void	move_right(t_global *g, t_map_data *data, char *add)
{
	int		x;
	int		y;

	x = g->pdata->x;
	y = g->pdata->y;
	if (can_move(g, data, x + 1, y))
	{
		add = ft_itoa(g->mdata->steps);
		protection_itoa(g, add, data);
		mlx_put_image_to_window(g->mlx, g->win, g->sdata->wall, 0, 0);
		mlx_string_put(g->mlx, g->win, 10, 10, 0xFFFFFF, add);
		free(add);
		ft_printf("total steps so far : %i\n", g->mdata->steps);
		g->mdata->steps++;
		mlx_put_image_to_window(g->mlx, g->win, g->sdata->bground,
			g->pdata->x * 64, g->pdata->y * 64);
		g->pdata->x = g->pdata->x + 1;
		mlx_put_image_to_window(g->mlx, g->win, g->sdata->p_right,
			g->pdata->x * 64, g->pdata->y * 64);
	}
}

static void	move_left(t_global *g, t_map_data *data, char *add)
{
	int		x;
	int		y;

	x = g->pdata->x;
	y = g->pdata->y;
	if (can_move(g, data, x - 1, y))
	{
		add = ft_itoa(g->mdata->steps);
		protection_itoa(g, add, data);
		mlx_put_image_to_window(g->mlx, g->win, g->sdata->wall, 0, 0);
		mlx_string_put(g->mlx, g->win, 10, 10, 0xFFFFFF, add);
		free(add);
		ft_printf("total steps so far : %i\n", g->mdata->steps);
		g->mdata->steps++;
		mlx_put_image_to_window(g->mlx, g->win, g->sdata->bground,
			g->pdata->x * 64, g->pdata->y * 64);
		g->pdata->x = g->pdata->x - 1;
		mlx_put_image_to_window(g->mlx, g->win, g->sdata->p_left,
			g->pdata->x * 64, g->pdata->y * 64);
	}
}

static void	move_front(t_global *g, t_map_data *data, char *add)
{
	int		x;
	int		y;

	x = g->pdata->x;
	y = g->pdata->y;
	if (can_move(g, data, x, y + 1))
	{
		add = ft_itoa(g->mdata->steps);
		protection_itoa(g, add, data);
		mlx_put_image_to_window(g->mlx, g->win, g->sdata->wall, 0, 0);
		mlx_string_put(g->mlx, g->win, 10, 10, 0xFFFFFF, add);
		free(add);
		ft_printf("total steps so far : %i\n", g->mdata->steps);
		g->mdata->steps++;
		mlx_put_image_to_window(g->mlx, g->win, g->sdata->bground,
			g->pdata->x * 64, g->pdata->y * 64);
		g->pdata->y = g->pdata->y + 1;
		mlx_put_image_to_window(g->mlx, g->win, g->sdata->p_front,
			g->pdata->x * 64, g->pdata->y * 64);
	}
}

static void	move_back(t_global *g, t_map_data *data, char *add)
{
	int		x;
	int		y;

	x = g->pdata->x;
	y = g->pdata->y;
	if (can_move(g, data, x, y - 1))
	{
		add = ft_itoa(g->mdata->steps);
		protection_itoa(g, add, data);
		mlx_put_image_to_window(g->mlx, g->win, g->sdata->wall, 0, 0);
		mlx_string_put(g->mlx, g->win, 10, 10, 0xFFFFFF, add);
		free(add);
		ft_printf("total steps so far : %i\n", g->mdata->steps);
		g->mdata->steps++;
		mlx_put_image_to_window(g->mlx, g->win, g->sdata->bground,
			g->pdata->x * 64, g->pdata->y * 64);
		g->pdata->y = g->pdata->y - 1;
		mlx_put_image_to_window(g->mlx, g->win, g->sdata->p_back,
			g->pdata->x * 64, g->pdata->y * 64);
	}
}

int	key_hook(int keycode, t_global *g)
{
	char	*add;

	if (keycode == 13)
		move_back(g, g->mdata, add);
	if (keycode == 1)
		move_front(g, g->mdata, add);
	if (keycode == 0)
		move_left(g, g->mdata, add);
	if (keycode == 2)
		move_right(g, g->mdata, add);
	if (keycode == 53)
		button_hook(g);
	return (0);
}
