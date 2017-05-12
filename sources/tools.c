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

void		print_s_piece(t_grid *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->prow - e->ru)
	{
		j = 0;
		while (j < e->pcol - e->rl)
		{
			printf("%c", e->s_piece[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void		print_grid(t_grid *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
			printf("%c", e->grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void		print_piece(t_grid *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->prow)
	{
		j = 0;
		while (j < e->pcol)
		{
			printf("%c", e->piece[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void		print_structure(t_grid *e)
{
	ft_printf("------- structure ----------\n");
	ft_printf("p_num -> %d\n", e->p_num);
	ft_printf("sp = %c\nbp = %c\n", e->sp, e->bp);
	ft_printf("col = %d\nrow = %d\n", e->col, e->row);
	ft_printf("i = %d\nj = %d\n", e->i, e->j);
	ft_printf("prow = %d\npcol = %d\nru = %d\nrl =\
			%d\n", e->prow, e->pcol, e->ru, e->rl);
	ft_printf("-----------------------------\n");
}
