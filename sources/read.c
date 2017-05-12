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

#include "../includes/filler.h"

void		print_zero_exit(t_grid *e)
{
	ft_putnbr(0);
	ft_putchar(' ');
	ft_putnbr(0);
	ft_putchar('\n');
	exit(0);
}

int			algo3(t_grid *e, int w)
{
	int		i;
	int		j;

	i = -1;
	while (++i <= e->row - e->prow)
	{
		j = 0;
		while (j <= e->col - e->pcol)
		{
			if (piece_fit_map(e, i, j) &&\
					i <= (e->row - e->prow) && j <= (e->col - e->pcol))
			{
				if (((i) == (e->row - e->prow)) && ((j) == (e->col - e->pcol)))
					print_zero_exit(e);
				if (piece_one_cross(e, i, j))
				{
					e->i = i - e->ru;
					e->j = j - e->rl;
					return (1);
				}
			}
			j++;
		}
	}
	return (2);
}

int			algo1(t_grid *e, int w)
{
	int		i;
	int		j;

	i = -1;
	while (++i <= e->row - e->prow)
	{
		j = 0;
		while (j <= e->col - e->pcol)
		{
			if (piece_fit_map(e, i, j) &&\
					i <= (e->row - e->prow) && j <= (e->col - e->pcol))
			{
				if (((i) == (e->row - e->prow)) && ((j) == (e->col - e->pcol)))
					print_zero_exit(e);
				if (piece_one_cross(e, i, j))
				{
					e->i = i - e->ru;
					e->j = j - e->rl;
					return (1);
				}
			}
			j++;
		}
	}
	return (2);
}

int			piece_fit_map(t_grid *e, int i, int j)
{
	if ((i + e->prow - e->ru) > e->row)
		return (0);
	if ((j + e->pcol - e->rl) > e->col)
		return (0);
	return (1);
}

int			exit_cross(int count)
{
	if (count != 1)
		return (0);
	else
		return (1);
}

int			piece_one_cross(t_grid *e, int i, int j)
{
	int		pi;
	int		pj;
	int		count;

	count = 0;
	pi = -1;
	while (++pi < e->prow - e->ru)
	{
		pj = -1;
		while (++pj < e->pcol - e->rl)
		{
			if ((e->s_piece[pi][pj] == '*' &&\
						(e->grid[i + pi][j + pj] == e->bs\
	|| e->grid[i + pi][j + pj] == e->ss)))
				return (0);
			else if (e->s_piece[pi][pj] == '*' &&\
					(e->grid[i + pi][j + pj] == e->bp\
	|| e->grid[i + pi][j + pj] == e->sp))
			{
				if (++count > 1)
					return (0);
			}
		}
	}
	return (exit_cross(count));
}

int			go_next(t_grid *e)
{
	if (e->j == e->col - 1)
	{
		e->i += 1;
		e->j = 0;
	}
	else if (e->i == e->row - 1)
		return (0);
	else
		e->j++;
	return (2);
}

int			algo2(t_grid *e, int w)
{
	int		i;
	int		j;

	i = e->row - e->prow;
	while (i >= 0)
	{
		j = e->col - e->pcol;
		while (j >= 0)
		{
			if (piece_fit_map(e, i, j))
			{
				if ((i == -e->ru) && (j == -e->ru))
					print_zero_exit(e);
				if (piece_one_cross(e, i, j))
				{
					e->i = i - e->ru;
					e->j = j - e->rl;
					return (1);
				}
			}
			j--;
		}
		i--;
	}
	return (9);
}
