/* tools.c */
#include "../includes/filler.h"

void		print_s_piece(t_grid *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->row - e->ru)
	{
		j = 0;
		while (j < e->pcol - e->rl)
		{
			printf("%c", e->s_piece[i][j]);
		}
		printf("\n");
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
	//ft_putstr("DEBUG\n");
}

void		print_structure(t_grid *e)
{
	printf("------- structure ----------\n");
	printf("p_num -> %d\n", e->p_num);
	printf("sp = %c\nbp = %c\n", e->sp, e->bp);
	printf("col = %d\nrow = %d\n", e->col, e->row);
	printf("i = %d\nj = %d\n", e->i, e->j);
	printf("prow = %d\npcol = %d\nru = %d\nrl = %d\n", e->prow, e->pcol, e->ru, e->rl);
	printf("-----------------------------\n");
}
