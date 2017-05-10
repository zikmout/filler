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

int debug2 = 1;

int			main(void)
{
	t_grid	*e;
	int		w;
	int		p;

	e = malloc(sizeof(t_grid));
	e->p_num = 1;
	e->i = 0;
	e->j = 0;

	p = 0;
	w = 0;
	while (1)
	{
		if (p == 1000)
			p = 0;
		p++;
		if (w == 0)
			w = get_info(e);
		if (w == 1 || w == 42)
		{
			if (debug2)
				ft_putstr("-->malloc_grid\n");
			malloc_grid(e);
			w += 1;
			if (debug2)
			{
				printf("ru = %d, rl = %d\n", e->ru, e->rl);
				write(1, "print_grid()\n", 14);
				print_grid(e);
				write(1, "print_piece()\n", 15);
				print_piece(e);
				write(1, "fin_print_piece()\n", 18);
				
				print_structure(e);
				write(1, "malloc_s_piece()\n", 19);
				malloc_s_piece(e);
				
				write(1, "print_structure()\n", 18);
				print_structure(e);

				write(1, "print_s_piece()\n", 18);
				//print_s_piece(e);
				write(1, "fin_print_w ->", 14);
				ft_putnbr(w);
				write(1, "<-fin_print_w\n", 15);
			}
		}
		if (w == 2 || w == 43)
		{
			if (debug2)
				ft_putstr("-->debut algo\n");
//			if (p % 2 == 0)
				w = algo1(e, w);
//			else
//				w = algo2(e, w);
			if (w == 9)
			{
				if (debug2)
					printf("FINITO\n");
				exit(0);
			}
			if (debug2)
				ft_putstr("-->fin algo\n");
			ft_putnbr(e->i);
			ft_putchar(' ');
			ft_putnbr(e->j);
			ft_putchar('\n');
			if (debug2)
				print_grid(e);
			if (debug2)
				printf("before w = 1/ w = %d\n", w);
			w = 1;
		}
		w = go_next(e);
		if (debug2)
			printf("after go_net w = %d\n", w);
	}
	return (0);
}
