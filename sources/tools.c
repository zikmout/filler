/* tools.c */
#include "../includes/filler.h"

void		print_grid(t_grid *e)
{
	int		i;
	int		j;

	i = 0;
	while (e->grid[i])
	{
		j = 0;
		while (e->grid[i][j])
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
	while (e->piece[i])
	{
		j = 0;
		while (e->piece[i][j])
		{
			ft_printf("%c", e->piece[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
