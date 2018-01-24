/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 12:05:05 by eozdek            #+#    #+#             */
/*   Updated: 2016/03/28 23:09:52 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_p(t_p *p)
{
	p->line2 = ft_strnew(0);
	p->path = 0;
	p->q = 0;
	p->j = 0;
	p->salle = 0;
	p->start = 0;
	p->tubes = 0;
	p->end = 0;
	p->n = 0;
	p->f = 0;
	p->color = 0;
	p->graphe = 0;
	p->fourmi = 0;
	p->s = 0;
	p->e = 0;
	p->error = 1;
	p->line = 0;
	p->step = 0;
}

void	init_graph(t_graphe *g, t_p *p)
{
	int i;
	int j;

	i = 0;
	j = 0;
	g->n = ft_list_size(p->list);
	g->matrice = (int **)malloc(sizeof(int*) * (g->n + 1));
	while (i < g->n)
	{
		j = 0;
		g->matrice[i] = (int *)malloc(sizeof(int) * (g->n + 1));
		while (j < g->n)
		{
			g->matrice[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	put_graphe(t_graphe g)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_putchar('\n');
	ft_putendl("GRAPHE :");
	while (i < g.n)
	{
		j = 0;
		while (j < g.n)
		{
			ft_putnbr(g.matrice[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_continue(t_graphe *g, t_p *p, char *line, int *i)
{
	int j;
	int n;

	j = 0;
	n = 1;
	while (p->f == 0)
	{
		j = ft_first_line(p, line);
		if (j == 0 || n == 0)
		{
			error(g, p, *i, line);
		}
		if (j == 2)
			break ;
		n = get_next_line(0, &line);
		p->line2 = ft_strjoin(p->line2, ft_strjoin(line, "\n"));
		*i += 1;
	}
}

void	ft_continue_2(t_graphe *g, int i, t_p *p, char *line)
{
	if (i > 0 && p->j == 2)
	{
		p->j = check_salles(p, line);
		if (p->j == 0)
		{
			error(g, p, i, line);
		}
		p->j = -1;
	}
}
