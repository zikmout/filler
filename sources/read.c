/* read.c */
#include "../includes/filler.h"

int debug3 = 0;

int			algo2(t_grid *e, int w)
{
	int		i;
	int		j;

	i = e->row - e->prow;
	while (i > 0)
	{
		j = e->col - e->pcol;
		while (j > 0)
		{
			if (debug3)
				printf("%c", e->grid[i][j]);
			if (debug3)
			{
				printf("Possible en i = %d, j = %d?\n", i, j);
				printf("%c", e->grid[i][j]);
			}
			if (piece_fit_map(e, i, j))// && i <= (e->row - e->prow) && j <= (e->col - e->pcol))
			{
				if (debug3)
					printf("--------------------->>>>>piece_fit_map : ok for i = %d et j = %d\n", i, j);
				if (piece_one_cross(e, i, j))
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
			j--;
		}
		i--;
	}
	return (9);
}

int			algo1(t_grid *e, int w)
{
	int		i;
	int		j;

	i = 0;
	while (i <= e->row - e->prow)
	{
		j = 0;
		while (j <= e->col - e->pcol)
		{
			if (debug3)
				printf("%c", e->grid[i][j]);
			if (debug3)
			{
				printf("Possible en i = %d, j = %d?\n", i, j);
				printf("%c", e->grid[i][j]);
			}
			if (piece_fit_map(e, i, j))// && i <= (e->row - e->prow) && j <= (e->col - e->pcol))
			{
				if (debug3)
					printf("--------------------->>>>>piece_fit_map : ok for i = %d et j = %d\n", i, j);
				if (piece_one_cross(e, i, j))
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
	return (9);
}

int			piece_fit_map(t_grid *e, int i, int j)
{
	if (debug3)
		printf("entre i et %d et j et %d\n", e->row - e->prow, e->col - e->pcol);
	while (i < e->row - e->prow)
	{
		if (debug3)
			printf("**** i = %d\n", i);
		if ((i + e->prow) > e->row)
			return (0);
		while (j < e->col - e->pcol)
		{
			if ((j + e->pcol > e->col))
				return (0);
			if (debug3)
				printf("**** j = %d\n", j);
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
	int		count_x;

	//printf("e->row - e->prow = %d\n", e->row - e->prow);
	//printf("e->col - e->pcol = %d\n", e->col - e->pcol);
	count = 0;
	count_x = 0;
	pi = 0;
	while (pi < e->prow)
	{
		pj = 0;
		while (pj < e->pcol)
		{
			//printf("TESTe->piece[%d][%d] = -->%c<--\n", pi, pj, e->piece[pi][pj]);
			if (e->piece[pi][pj] == '*' && (e->grid[i + pi][j + pj] == 'X' || e->grid[i + pi][j + pj] == 'x'))
			{
				if (debug3)
				{
					printf("TESTe->piece[%d][%d] = -->%c<--\n", pi, pj, e->piece[pi][pj]);
					printf("count_X++\n");
				}
				count_x++;
			}
			else if (e->piece[pi][pj] == '*' && (e->grid[i + pi][j + pj] == e->bp || e->grid[i + pi][j + pj] == e->sp))
			{

				if (debug3)
				{
					printf("e->piece[%d][%d] = -->%c<--\n", pi, pj, e->piece[pi][pj]);
					printf("e->grid[%d][%d] = -->%c<--\n", i + pi, j + pj, e->grid[i + pi][j + pj]);
					printf("count++\n");
				}
				count++;
				if (count > 1 || count_x != 0)
					return (0);
			}
			pj++;
		}
		pi++;
	}
	if (count != 1 || count_x != 0)
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
