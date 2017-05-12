/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 21:16:45 by ssicard           #+#    #+#             */
/*   Updated: 2016/06/02 18:10:37 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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
