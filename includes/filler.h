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
struct		s_grid
{
	int		p_num;		//player number initialized to 1
	char	sp;			// o if p1 , x if p2
	char	bp;			// O if p1 , X if p2
	char	ss;
	char	bs;
	int		row;		// plateau nb of rows
	int		col;		// plateau nb of columns
	int		i;
	int		j;
	char	**grid;
	char	**piece;
	char	**s_piece;
	int		prow;		//piece nb of raws
	int		pcol;		// piece nb of columns
	int		ru;
	int		rl;
};

//int debug1 = 1;

/* read.c */
void	print_zero_exit(t_grid *e);
int		algo1(t_grid *e, int w);
int		algo2(t_grid *e, int w);
int		algo3(t_grid *e, int w);
int		go_next(t_grid *e);
int		piece_fit_map(t_grid *e, int i, int j);
int		piece_one_cross(t_grid *e, int i, int j);
int		exit_cross(int count);

/* init.c */
int		get_info(t_grid *e);
void	get_rc(t_grid *e, char *line);
void	get_p_num(t_grid *e, char *line);
int		malloc_grid(t_grid *e);
void	malloc_piece(t_grid *e, char *line, int ret);

/* tools.c */
void	print_grid(t_grid *e);
void	print_piece(t_grid *e);
void	print_structure(t_grid *e);
void	print_s_piece(t_grid *e);

/* init2.c */
int		get_rl(t_grid *e);
int		get_ru(t_grid *e);
void	malloc_s_piece(t_grid *e);
void	set_adverse(t_grid *e);

/* main.c */
void	free_stuff(t_grid *e);
#endif
