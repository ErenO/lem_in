/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 08:39:31 by eozdek            #+#    #+#             */
/*   Updated: 2016/03/28 23:48:12 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_tab_s(int *tab, int q)
{
	int j;

	j = 0;
	while (j < q)
	{
		ft_putnbr(tab[j]);
		ft_putchar(' ');
		j++;
	}
	ft_putchar('\n');
}

void	free_tabs(int **tab, int *tab1, int *tab2)
{
	free(tab);
	free(tab1);
	free(tab2);
}

int		path_resolve(t_graphe *g, t_p *p)
{
	int q;
	int **tab;
	int *tab1;
	int *tab2;

	tab = NULL;
	q = 0;
	if ((q = ft_path(g, 0, g->n - 1, &g->q)) == 1 && p->start && p->end)
	{
		p->error = 0;
		ft_putstr(p->line2);
		p->q = 1;
		tab = ft_path2(g, 0, g->n - 1, tab);
		q = tab_control(tab, &g->q, ft_list_size(p->list) - 1);
		tab1 = tab_put(tab, g->q, q);
		p->n = q;
		tab2 = init_tab(p);
		print_lem(p, tab2, tab1);
		if (p->path == 1)
			print_path(p, tab1);
		free_tabs(tab, tab1, tab2);
	}
	return (1);
}

void	list_maker(t_p *p, t_graphe *g)
{
	if (p->tubes == 0 && p->start == 1 && p->end == 1)
	{
		p->list = add_link(p->list, p->s_start);
		p->list = ft_insert_end(p->list, p->s_end);
		list_to_tab(p->list, p);
		init_graph(g, p);
	}
}

int		check_tubes_2(t_graphe *g, t_p *p, char *str)
{
	int i;

	i = 0;
	if (((str[i] >= '!' && str[i] <= 44) || (str[i] >= 46 && str[i] <= '~')))
	{
		while ((str[i] >= '!' && str[i] <= 44)
				|| (str[i] >= 46 && str[i] <= '~'))
			i++;
		if (str[i] != '-')
			return (0);
		i++;
		while (((str[i] >= '!' && str[i] <= 44)
				|| (str[i] >= 46 && str[i] <= '~')) && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			return (0);
		if (!(p->end) || !(p->start))
			return (0);
		list_maker(p, g);
		return (1);
	}
	return (0);
}
