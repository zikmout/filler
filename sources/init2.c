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
	if (!(e->s_piece = malloc(sizeof(char *) * (e->pcol - e->rl) + 1)))
		return ;
	pi = 0;
	i = e->ru;
	while (i < e->prow)
	{
		//if (debug)
		//	printf("e->piece[%d][%d] = %c\n", i, j, e->piece[i][j]);
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

	i = 0;
	j = 0;
	ru = 0;
	while (i < e->prow - 1)
	{
		if (debug)
		{
			printf("e->piece[%d][%d] = %c\n", i, j, e->piece[i][j]);
			usleep(300000);
		}
		if (j == e->pcol - 1 && e->piece[i][j] == '.')
		{
			ru += 1;
			i++;
			j = 0;
		}
		else if (e->piece[i][j] == '.')
			j++;
		else
			break ;
	}
	return (ru);
}

int			get_rl(t_grid *e)
{
	int		rl;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rl = 0;
	while (j < e->pcol - 1)
	{
		if (debug)
			printf("e->piece[%d][%d] = %c\n", i, j, e->piece[i][j]);
		if (i == e->prow - 1 && e->piece[i][j] == '.')
		{
			rl += 1;
			j++;
			i = 0;
		}
		else if (e->piece[i][j] == '.')
			i++;
		else
			break ;
	}
	return (rl);
}
