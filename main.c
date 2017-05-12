/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 21:16:45 by ssicard           #+#    #+#             */
/*   Updated: 2016/06/02 18:10:37 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void		set_adverse(t_grid *e)
{
	if (e->p_num == 1)
	{
		e->ss = 'x';
		e->bs = 'X';
	}
	else if (e->p_num == 2)
	{
		e->ss = 'o';
		e->bs = 'O';
	}
}

void		init_t_grid(t_grid *e)
{
	e->p_num = 1;
	e->i = 0;
	e->j = 0;
}

int			main(void)
{
	t_grid	*e;
	int		w;
	int		p;

	e = malloc(sizeof(t_grid));
	init_t_grid(e);
	p = 0;
	w = 0;
	while (1)
	{
		p = (p == 1000) ? (0) : (p);
		if (w == 0)
			w = get_info(e);
		if (w == 1 || w == 42)
		{
			w = malloc_grid(e);
			malloc_s_piece(e);
			set_adverse(e);
		}
		if (w == 2 || w == 43)
			w = algos_start(e, w, p++);
		free_stuff(e);
	}
	free(e);
	return (0);
}

int			algos_start(t_grid *e, int w, int p)
{
	w = go_next(e);
	if (p % 7 == 0)
		w = algo3(e, w);
	if (p % 2 == 1)
		w = algo1(e, w);
	else
		w = algo2(e, w);
	if (w == 9)
		exit(0);
	ft_putnbr(e->i);
	ft_putchar(' ');
	ft_putnbr(e->j);
	ft_putchar('\n');
	return (1);
}

void		free_stuff(t_grid *e)
{
	if (e->grid)
	{
		free(e->grid);
		e->grid = NULL;
	}
	if (e->s_piece)
	{
		free(e->s_piece);
		e->s_piece = NULL;
	}
	if (e->piece)
	{
		free(e->piece);
		e->piece = NULL;
	}
}
