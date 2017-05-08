/* read.c */
#include "../includes/filler.h"

int			algo(t_grid *e, int w)
{
	int		i;
	int		j;

//	write(1, "top\n", 4);
	i = 0;
	while (e->grid[i])
	{
		j = 0;
		while (e->grid[i][j])
		{
//			printf("%c", e->grid[i][j]);
			if (check_piece(e, i - e->ru, j - e->rl, w) && i - e->ru >= 0 && j - e->rl >= 0 && i - e->ru <= e->prow && j - e->rl <= e->pcol)
			{
			//	printf("Possible en i = %d, j = %d\n", i, j);
//			ft_printf("%c", e->grid[i][j]);
//			if (e->grid[i][j] == e->bp)
//			{
				e->i = i - e->ru;
				e->j = j - e->rl;
				return (1);
			}
//			printf("\n");
			j++;
		}
//		ft_printf("\n");
		i++;
	}
	return (1);
}

int			check_piece(t_grid *e, int i, int j, int w)
{
	int		gi;
	int		gj;
	int		pi;
	int		pj;
	int		count;

//	print_piece(e);
//	printf("i = %d, j = %d\n", i, j);
	count = 0;
	pi = 0;
	gi = i;
//	printf("TEST pour i = %d et j = %d\n", i, j);
	while (e->piece[pi])
	{
//		write(1, "loop\n", 5);
		pj = 0;
		gj = j;
		while (e->piece[pi][pj])
		{
//			printf("%c", e->piece[pi][pj]);
//		printf("pi = %d, pj = %d, e->piece[pi][pj] = %c\n", pi, pj, e->piece[pi][pj]);
//			write(1, &e->piece[pi][pj], 1);
		if (e->piece[pi][pj] == '*' && (e->grid[(gi + pi) % e->row][(gj + pj) % e->col] == 'X' || e->grid[(gi + pi) % e->row][(gj + pj) % e->col] == 'x'))
				return (0);
		else if (e->piece[pi][pj] == '*' && (e->grid[(gi + pi) % e->row][(gj + pj) % e->col] == 'O'))
				count = count + 1;
//		if (pi == e->prow - 1 && pj == e->pcol - 1 && count == 1)
//			return (1);

//			if (e->piece[pi][pj] == '*')
//				e->grid[ABS(gi + pi) % e->row][ABS(gj + pj) % e->col] = 'T';
			pj++;
		}
//		printf("\n");
//		printf("\n");
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
	while (e->grid[e->i])
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
	}
	return (3);
}
