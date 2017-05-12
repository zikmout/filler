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

void		malloc_s_piece(t_grid *e)
{
	int		i;
	int		j;
	int		pi;
	char	*tmp;

	e->ru = get_ru(e);
	e->rl = get_rl(e);
	if (!(e->s_piece = malloc(sizeof(char *) * (e->prow - e->ru) + 1)))
		return ;
	pi = 0;
	i = e->ru;
	while (i < e->prow)
	{
		tmp = ft_strdup("\0");
		j = e->rl;
		while (j < e->pcol)
		{
			tmp = ft_strjoina(tmp, e->piece[i][j]);
			j++;
		}
		e->s_piece[pi] = tmp;
		pi++;
		i++;
	}
	e->piece[i] = NULL;
}

int			get_ru(t_grid *e)
{
	int		ru;
	int		i;
	int		j;
	int		count;

	ru = 0;
	count = 0;
	i = -1;
	while (++i < e->prow)
	{
		if (count == e->pcol)
		{
			ru += 1;
			count = 0;
		}
		j = -1;
		while (++j < e->pcol)
		{
			if (e->piece[i][j] == '.')
				count++;
			if (e->piece[i][j] != '.')
				return (ru);
		}
	}
	return (ru);
}

int			get_rl(t_grid *e)
{
	int		rl;
	int		i;
	int		j;
	int		count;

	rl = 0;
	count = 0;
	i = -1;
	while (++i < e->pcol)
	{
		j = -1;
		while (++j < e->prow)
		{
			if (e->piece[j][i] == '.')
				count++;
			if (e->piece[j][i] != '.')
				return (rl);
			if (count == e->prow)
			{
				rl += 1;
				count = 0;
			}
		}
	}
	return (rl);
}
