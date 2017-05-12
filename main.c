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

int			main(void)
{
	t_grid	*e;
	int		w;
	int		p;

	e = malloc(sizeof(t_grid));
	e->p_num = 1;
	e->i = 0;
	e->j = 0;
	e->p1s = 'o';
	e->p1b = 'O';
	e->p2s = 'x';
	e->p2b = 'X';

	p = 0;
	w = 0;
	while (1)
	{
//		if (p == 1000)
//			p = 0;
		if (w == 0)
			w = get_info(e);
		if (w == 1 || w == 42)
		{
			w = malloc_grid(e);
			malloc_s_piece(e);
		}
		if (w == 2 || w == 43)
		{
			w = go_next(e);
//			if (p % 7 == 0)
//				w = algo3(e, w);
//			if (p % 2 == 1)
				w = algo1(e, w);
//			else
//				w = algo2(e, w);
			if (w == 9)
				exit(0);
			ft_putnbr(e->i);
			ft_putchar(' ');
			ft_putnbr(e->j);
			ft_putchar('\n');
			w = 1;
//			p++;
		}
		free_stuff(e);
	}
	free(e);
	return (0);
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
