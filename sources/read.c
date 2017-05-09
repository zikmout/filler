/* read.c */
#include "../includes/filler.h"

int debug3 = 0;

int			algo(t_grid *e, int w)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
			if (debug3)
				printf("%c", e->grid[i][j]);
			if (debug3)
			{
				printf("Possible en i = %d, j = %d?\n", i, j);
				printf("%c", e->grid[i][j]);
			}
			if (piece_fit_map(e, i, j))// && check_piece(e, i, j, w))
			{
				if (debug3)
					printf("--------------------->>>>>piece_fit_map : ok for i = %d et j = %d\n", i, j);
				if (piece_one_cross(e, i, j))// && check_piece(e, i, j, w))
				{
					if (debug3)
					{
						printf("piece_one_cross = OK\n");
						printf("---------------------XXXXXpiece_once_cross : ok for i = %d et j = %d\n", i, j);
						printf("FINAL NUMBER: i = %d et j = %d\n", i, j);
					}
					e->i = i;
					e->j = j;
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int			piece_fit_map(t_grid *e, int i, int j)
{
	while (i < e->row - e->prow)
	{
		if ((i + e->prow) > e->row)
			return (0);
		while (j < e->col - e->pcol)
		{
			if ((j + e->pcol > e->col))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			piece_one_cross(t_grid *e, int i, int j)
{
	int		pi;
	int		pj;
	int		count;

	//printf("e->row - e->prow = %d\n", e->row - e->prow);
	//printf("e->col - e->pcol = %d\n", e->col - e->pcol);
	count = 0;
			pi = 0;
			while (pi < e->prow)
			{
				pj = 0;
				while (pj < e->pcol)
				{
					if (e->piece[pi][pj] == '*' && e->grid[i + pi][j + pj] == e->bp)
					{
						if (debug3)
						{
							printf("e->piece[%d][%d] = -->%c<--\n", pi, pj, e->piece[pi][pj]);
							printf("e->grid[%d][%d] = -->%c<--\n", i + pi, j + pj, e->grid[i + pi][j + pj]);
							printf("count++\n");
						}
						count++;
						if (count > 1)
							return (0);
					}
					pj++;
				}
				pi++;
	}
	if (count != 1)
		return (0);
	return (1);
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
/*	while (e->grid[e->i])
	{
		if (e->j == e->col)
			e->j = 0;
		while (e->grid[e->i][e->j])
		{
			if (e->grid[e->i][e->j] == e->bp)
				return (3);
			e->j++;
		}
		e->i++;
	}*/
	return (3);
}
