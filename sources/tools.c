/* tools.c */
#include "../includes/filler.h"

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
			ft_printf("%c", e->grid[i][j]);
			j++;
		}
		ft_printf("\n");
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
			ft_printf("%c", e->piece[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void		print_s_piece(t_grid *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->row - e->ru)
	{
		j = 0;
		while (j < e->col - e->rl)
		{
			//ft_printf("************%c", e->s_piece[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
