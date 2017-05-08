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

int debug2 = 0;

int			main(void)
{
	t_grid	*e;
	int		w;

	e = malloc(sizeof(t_grid));
	e->p_num = 1;
//	e->row = 30;
//	e->col = 15;
			e->i = 0;
			e->j = 0;

	w = 0;
	while (1)
	{

		if (w == 0)
			w = get_info(e);
		if (w == 1 || w == 42)
		{
			if (debug2)
				ft_putstr("-->malloc_grid\n");
			malloc_grid(e);
			if (debug2)
				ft_putstr("-->malloc_s_piece\n");
			malloc_s_piece(e);
			if (debug2)
				print_s_piece(e);
			w += 1;
		}
		else if (w == 2 || w == 43)
		{
			if (debug2)
				ft_putstr("-->debut algo\n");
			w = algo(e, w);
			if (debug2)
				ft_putstr("-->fin algo\n");
			ft_putnbr(e->i);
			ft_putchar(' ');
			ft_putnbr(e->j);
			ft_putchar('\n');
			if (debug2)
				print_grid(e);
			//break ;
			w = 1;
		}
	//	e->i = -1;
	//	e->j = -4;
		if (debug2)
			printf("Ret CP = %d\n", check_piece(e, e->i, e->j, w));
		w += 1;
		w = go_next(e);
		if (w == 3)
		{
			//ft_putchar(e->bp);
			usleep(1000000);
			ft_putnbr(e->i);
			ft_putchar(' ');
			ft_putnbr(e->j);
			ft_putchar('\n');
			w = 1;
		}
	}
//	get_grid();
	return (0);
}
