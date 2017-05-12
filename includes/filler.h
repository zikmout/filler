/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 21:11:02 by ssicard           #+#    #+#             */
/*   Updated: 2016/06/02 18:10:39 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# include "../libft/printf.h"
# define ABS(X) (X < 0) ? (-X) : (X)

typedef struct s_grid	t_grid;
struct			s_grid
{
	int			p_num;
	char		sp;
	char		bp;
	char		ss;
	char		bs;
	int			row;
	int			col;
	int			i;
	int			j;
	char		**grid;
	char		**piece;
	char		**s_piece;
	int			prow;
	int			pcol;
	int			ru;
	int			rl;
};

void			print_zero_exit(t_grid *e);
int				algo1(t_grid *e, int w);
int				algo2(t_grid *e, int w);
int				algo3(t_grid *e, int w);
int				go_next(t_grid *e);
int				piece_fit_map(t_grid *e, int i, int j);
int				piece_one_cross(t_grid *e, int i, int j);
int				exit_cross(int count);
int				get_info(t_grid *e);
void			get_rc(t_grid *e, char *line);
void			get_p_num(t_grid *e, char *line);
int				malloc_grid(t_grid *e);
void			malloc_piece(t_grid *e, char *line, int ret);
void			print_grid(t_grid *e);
void			print_piece(t_grid *e);
void			print_structure(t_grid *e);
void			print_s_piece(t_grid *e);
int				get_rl(t_grid *e);
int				get_ru(t_grid *e);
void			malloc_s_piece(t_grid *e);
void			set_adverse(t_grid *e);
void			free_stuff(t_grid *e);
int				algos_start(t_grid *e, int w, int p);
#endif
