/* init2.c */
#include "../includes/filler.h"

void		malloc_s_piece(t_grid *e)
{
	int		i;
	int		j;
	int		pi;
	char	*tmp;

	e->ru = get_ru(e);
	e->rl = get_rl(e);
	if (!(e->s_piece = malloc(sizeof(char *) * (e->pcol - e->rl))))
		return ;
	pi = 0;
	i = e->ru;
	while (i < e->prow)
	{
		tmp = ft_strdup("\0");
		j = e->rl;
		while (j < e->pcol)
		{
			tmp = ft_strjoina(tmp, e->piece[i][j]);
			j++;
		}
		e->s_piece[pi] = tmp;
		pi++;
		i++;
	}
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
//		printf("e->piece[%d][%d] = %c\n", i, j, e->piece[i][j]);
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
		//printf("e->piece[%d][%d] = %c\n", i, j, e->piece[i][j]);
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
