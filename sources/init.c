/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 21:11:02 by ssicard           #+#    #+#             */
/*   Updated: 2016/06/02 18:10:39 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			get_info(t_grid *e)
{
	int		ret;
	char	*line;
	int		i;

	while ((ret = (get_next_line(0, &line)) > 0))
	{
		if (ft_strncmp(line, "$$$", 3) == 0)
			get_p_num(e, line);
		else if (ft_strncmp(line, "Plateau", 7) == 0)
		{
			get_rc(e, line);
			break ;
		}
	}
	if (e->p_num == 1)
	{
		e->sp = 'o';
		e->bp = 'O';
	}
	else if (e->p_num == 2)
	{
		e->sp = 'x';
		e->bp = 'X';
	}
	return (42);
}
void		get_p_num(t_grid *e, char *line)
{
	char	**split;
	int		i;
	char	*nb;

	nb = ft_strdup("\0");
	split = ft_strsplit(line, ' ');
	//printf("LINE = %s\n", line);
	if (ft_strcmp(split[4], "[./filler]") == 0)
	{
		i = 0;
		while (split[2][i])
		{
			while (ft_isdigit(split[2][i]))
			{
				nb = ft_strjoina(nb, split[2][i]);
				i++;
			}
			i++;
		}
		e->p_num = ft_atoi(nb);
		free(nb);
	}
}

void		get_rc(t_grid *e, char *line)
{
	char	*tmp;
	int		i;
	char	**split;

	tmp = ft_strdup("\0");
	i = 8;
	while (line[i] != ':')
	{
		tmp = ft_strjoina(tmp, line[i]);
		i++;
	}
	split = ft_strsplit(tmp, ' ');
	e->row = ft_atoi(split[0]);
	e->col = ft_atoi(split[1]);
	free(tmp);
}

int			malloc_grid(t_grid *e)
{
	int		ret;
	char	*line;
	int		r;

	if (!(e->grid = malloc(sizeof(char *) * e->row)))
		return (0);
	r = 0;
	while ((ret = (get_next_line(0, &line)) > 0))
	{
		if (ft_isdigit(line[0]))
		{
			e->grid[r] = ft_strdup(line + 4);
			r = r + 1;
		}
		else if (ft_strncmp(line, "Piece", 5) == 0)
		{
			malloc_piece(e, line, ret);
			break ;
		}
	}
	return (2);
}

void		malloc_piece(t_grid *e, char *line, int ret)
{
	char	**split;
	int		r;

	split = ft_strsplit(line, ' ');
	e->prow = ft_atoi(split[1]);
	e->pcol = ft_atoi(split[2]);
	if (!(e->piece = malloc(sizeof(char *) * e->prow)))
		return ;
	r = 0;
	while ((ret = (get_next_line(0, &line)) > 0))
	{
		if (line[0] == '.' || line[0] == '*')
		{
			e->piece[r] = ft_strdup(line);
			r = r + 1;
		}
		if (r == e->prow)
			break ;
	}
}
