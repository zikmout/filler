/* init2.c */
#include "../includes/filler.h"

int debug = 0;

void		malloc_s_piece(t_grid *e)
{
	int		i;
	int		j;
	int		pi;
	char	*tmp;

	e->ru = get_ru(e);
	e->rl = get_rl(e);
	if (debug)
	{
		ft_putstr("*e->ru = ");
		ft_putnbr(e->ru);
		ft_putstr("\n*e->rl = ");
		ft_putnbr(e->rl);
		ft_putchar('\n');
		//printf("e->ru = %d\ne->rl = %d\n", e->ru, e->rl);
	}
	//if (!(e->s_piece = malloc(sizeof(char *) * (e->pcol - e->rl) + 1)))
	if (!(e->s_piece = malloc(sizeof(char *) * (e->prow - e->ru) + 1)))
		return ;
	pi = 0;
	i = e->ru;
	while (i < e->prow)
	{
		if (debug)
		{
			write(1, "DEBUG1\n", 7);
			//printf("MSPe->piece[%d][%d] = %c\n", i, j, e->piece[i][j]);
		}
		tmp = ft_strdup("\0");
		j = e->rl;
		while (j < e->pcol)
		{
			if (debug)
			{
				write(1, "->DEBUG\n", 8);
				ft_putstr("e->rl = ");
				ft_putnbr(e->rl);
				ft_putchar('\n');

				ft_putstr("i = ");
				ft_putnbr(i);
				ft_putstr("\nj =");
				ft_putnbr(j);
				ft_putstr("\ne->piece[i][j] = ");
				ft_putchar(e->piece[i][j]);
				ft_putchar('\n');
			}

			tmp = ft_strjoina(tmp, e->piece[i][j]);
			if (debug)
				printf("tmp = %s, pi = %d\n", tmp, pi);
			j++;
		}
		e->s_piece[pi] = tmp;
		pi++;
		i++;
		//free(tmp);
	}
	e->piece[i] = NULL;
	if (debug)
		print_s_piece(e);
}

int			get_ru(t_grid *e)
{
	int		ru;
	int		i;
	int		j;
	int		count;

	ru = 0;
	count = 0;
	i = 0;
	while (i < e->prow)
	{
		if (count == e->pcol)
		{
			ru += 1;
			count = 0;
		}
		j = 0;
		while (j < e->pcol)
		{
			if (debug)
			{
				printf("_get_rU e->piece[%d][%d] = %c\n", i, j, e->piece[i][j]);
				printf("U count = %d\n", count);
				//usleep(300000);
			}
			if (e->piece[i][j] == '.')
				count++;
			if (e->piece[i][j] != '.')
				return (ru);
			j++;
		}
		i++;
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

	i = 0;
	while (i < e->pcol)
	{
		j = i;
		while (j < e->prow)
		{
			if (debug)
			{
				printf("_get_rL e->piece[%d][0] = %c\n", j, e->piece[j][0]);
				printf("L count = %d\n", count);
				//usleep(300000);
			}
			if (e->piece[j][0] == '.')
				count++;
			if (e->piece[j][0] != '.')
				return (rl);

			if (count == e->prow)
			{
				rl += 1;
				count = 0;
			}
			j++;
		}
		i++;
	}
	return (rl);
}

