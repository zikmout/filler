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

void		print_zero_exit(t_grid *e)
{
	ft_putnbr(0);
	ft_putchar(' ');
	ft_putnbr(0);
	ft_putchar('\n');
	exit(0);
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
