/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 09:45:02 by eozdek            #+#    #+#             */
/*   Updated: 2016/03/28 21:44:39 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_visit(t_graphe *g, int s, int s2, int *j)
{
	int i;
	int ret;

	g->tab[s].m = 1;
	if (s == s2)
		return (1);
	i = 0;
	ret = 0;
	while (i < g->n)
	{
		if ((g->matrice[s][i] == 1) && (g->tab[i].m == 0))
		{
			*j += 1;
			ret = ret || ft_visit(g, i, s2, j);
		}
		i++;
	}
	return (ret);
}

int		ft_path(t_graphe *g, int s1, int s2, int *j)
{
	int i;

	i = 0;
	g->tab = malloc(sizeof(int) * (g->n));
	while (i < g->n)
	{
		g->tab[i].m = 0;
		i++;
	}
	return (ft_visit(g, s1, s2, j));
}

int		ft_visit2(t_graphe *g, int s, int s2, int **tab)
{
	int i;
	int ret;

	g->tab[s].m = 1;
	if (s == s2)
		return (1);
	i = 0;
	ret = 0;
	while (i < g->n)
	{
		if ((g->matrice[s][i] == 1) && (g->tab[i].m == 0))
		{
			tab[g->j][0] = s;
			tab[g->j][1] = i;
			g->j++;
			ret = ret || ft_visit2(g, i, s2, tab);
		}
		i++;
	}
	return (ret);
}

int		**ft_path2(t_graphe *g, int s1, int s2, int **tab)
{
	int i;

	i = 0;
	g->j = 0;
	tab = (int**)malloc(sizeof(int*) * g->q + 1);
	while (i < g->q)
	{
		tab[i] = (int*)malloc(sizeof(int) * 2);
		tab[i][1] = 0;
		tab[i][0] = 0;
		i++;
	}
	i = 0;
	while (i < g->n)
	{
		g->tab[i].m = 0;
		i++;
	}
	ft_visit2(g, s1, s2, tab);
	return (tab);
}
