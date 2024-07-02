/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:16:36 by abakirca          #+#    #+#             */
/*   Updated: 2024/05/27 15:11:37 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long.h"
#include "../libft/inc/libft.h"

void	destroy_img(t_global *g)
{
	if (g->sdata->bground)
		mlx_destroy_image(g->mlx, g->sdata->bground);
	if (g->sdata->bground)
		mlx_destroy_image(g->mlx, g->sdata->coins);
	if (g->sdata->finish)
		mlx_destroy_image(g->mlx, g->sdata->finish);
	if (g->sdata->p_back)
		mlx_destroy_image(g->mlx, g->sdata->p_back);
	if (g->sdata->p_front)
		mlx_destroy_image(g->mlx, g->sdata->p_front);
	if (g->sdata->p_left)
		mlx_destroy_image(g->mlx, g->sdata->p_left);
	if (g->sdata->p_right)
		mlx_destroy_image(g->mlx, g->sdata->p_right);
	if (g->sdata->wall)
		mlx_destroy_image(g->mlx, g->sdata->wall);
}

int	load_img(void *mlx_ptr, t_sprite *s, t_global *g)
{
	int	w;
	int	h;

	s->wall = mlx_xpm_file_to_image(mlx_ptr, "./img/wall.xpm", &w, &h);
	s->bground = mlx_xpm_file_to_image(mlx_ptr, "./img/empty.xpm", &w, &h);
	s->finish = mlx_xpm_file_to_image(mlx_ptr, "./img/end.xpm", &w, &h);
	s->p_front = mlx_xpm_file_to_image(mlx_ptr, "./img/front.xpm", &w, &h);
	s->p_left = mlx_xpm_file_to_image(mlx_ptr, "./img/left.xpm", &w, &h);
	s->p_right = mlx_xpm_file_to_image(mlx_ptr, "./img/right.xpm", &w, &h);
	s->p_back = mlx_xpm_file_to_image(mlx_ptr, "./img/back.xpm", &w, &h);
	s->coins = mlx_xpm_file_to_image(mlx_ptr, "./img/ring.xpm", &w, &h);
	if (!s->wall || !s->bground || !s->finish || !s->coins || !s->p_left
		|| !s->p_right || !s->p_back || !s->p_front)
	{
		ft_putstr_fd("Failed to load images.", 2);
		return (destroy_img(g), 1);
	}
	return (0);
}

static void	process_map_tile(t_global *g, t_pos po, char tile_char)
{
	if (tile_char == '0' || tile_char == 'P')
		mlx_put_image_to_window(g->mlx, g->win,
			g->sdata->bground, po.x * 64, po.y * 64);
	if (tile_char == '1')
		mlx_put_image_to_window(g->mlx, g->win,
			g->sdata->wall, po.x * 64, po.y * 64);
	if (tile_char == 'E')
		mlx_put_image_to_window(g->mlx, g->win,
			g->sdata->finish, po.x * 64, po.y * 64);
	if (tile_char == 'P')
		mlx_put_image_to_window(g->mlx, g->win,
			g->sdata->p_front, po.x * 64, po.y * 64);
	if (tile_char == 'C')
		mlx_put_image_to_window(g->mlx, g->win,
			g->sdata->coins, po.x * 64, po.y * 64);
}

static void	xpm_to_win(t_global *global)
{
	t_pos	p;

	p.y = 0;
	while (p.y < global->mdata->h)
	{
		p.x = 0;
		while (p.x < global->mdata->w)
		{
			process_map_tile(global, p, global->mdata->map[p.y][p.x]);
			p.x++;
		}
		p.y++;
	}
}

int	start_game(t_global *g)
{
	g->mdata->steps = 1;
	g->mdata->coll = 0;
	collectible_counter(g->mdata);
	if (prep_path_find(g->mdata, g->pdata->x, g->pdata->y, 0))
		return (1);
	if (init_new_window(g))
		return (1);
	ft_bzero(g->sdata, sizeof(t_sprite));
	if (load_img(g->mlx, g->sdata, g))
		return (1);
	xpm_to_win(g);
	mlx_hook(g->win, 2, 0, key_hook, g);
	mlx_hook(g->win, 17, 0, button_hook, g);
	mlx_loop(g->mlx);
	return (0);
}
