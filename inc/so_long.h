/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:44:29 by abakirca          #+#    #+#             */
/*   Updated: 2024/05/27 15:12:51 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_sprite
{
	void	*wall;
	void	*finish;
	void	*p_left;
	void	*p_right;
	void	*p_back;
	void	*p_front;
	void	*bground;
	void	*coins;
}				t_sprite;

typedef struct s_map_data
{
	int		h;
	int		w;
	char	**map;
	int		steps;
	int		coll;
}				t_map_data;

typedef struct s_global
{
	void		*win;
	void		*mlx;
	t_sprite	*sdata;
	t_pos		*pdata;
	t_map_data	*mdata;
}				t_global;

int				load_img(void *mlx_ptr, t_sprite *s, t_global *g);
int				key_hook(int keycode, t_global *g);
int				button_hook(t_global *gdata);
int				init_new_window(t_global *g);
void			destroy_img(t_global *g);
void			protection_itoa(t_global *g, char *s, t_map_data *mdata);

int				ft_controls(char *av, t_global *gdata, int i);
int				check_map_len(t_map_data *data);
int				check_one_map(t_map_data *data);
int				is_player(t_global *data);
int				is_exit(t_map_data *data);
int				check_map_character(t_map_data *data);
int				count_lines(const char *map);
void			check_map_name(const char *str);
int				end_of_file(t_map_data *data);
int				start_game(t_global *g);
int				can_move(t_global *g, t_map_data *data, int x, int y);
int				prep_path_find(t_map_data *data, int x, int y, int i);
int				is_coll(t_map_data *data);
void			ft_free(t_map_data *data, int h);
void			collectible_counter(t_map_data *data);

#endif
