/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 16:16:51 by eozdek            #+#    #+#             */
/*   Updated: 2016/03/28 23:45:20 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		tab_2(int **tab, int i, int *y, int s)
{
	int n;

	n = 0;
	if (*y > 1 && tab[0][0] == 0 && tab[1][0] == 0)
	{
		while (tab[n][0] == 0 && tab[n + 1][0] == 0)
		{
			tab[n][1] = -1;
			tab[n][0] = -1;
			n++;
		}
	}
	tab_4(tab, y);
	if ((tab[i][0] == 0 && tab[i][1] == s) && i > 1)
	{
		i--;
		while (i >= 0)
		{
			tab[i][1] = -1;
			tab[i][0] = -1;
			i--;
		}
		i = *y - 1;
	}
	return (i);
}

void	tab_3(int **tab, int i, int n)
{
	int j;

	j = 0;
	while (n > 1)
	{
		if (tab[n][0] != tab[n - 1][1] && tab[n][0] != -1
			&& tab[n - 1][1] != -1 && n > 0)
		{
			j++;
			i = n - 1;
			while (tab[n][0] != tab[i][1] && tab[i][0] != -1 && i > 0)
			{
				tab[i][0] = -1;
				tab[i][1] = -1;
				i--;
			}
			n = i;
		}
		j++;
		n--;
	}
}

int		check_tubes(t_graphe *g, t_p *p, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	g->q = 0;
	if (check_tubes_2(g, p, str) == 0)
		return (0);
	if ((lstcmp1(str, p->list, '-', &i)) != 1)
		return (0);
	if ((lstcmp2(str, p->list, &j)) != 1)
		return (0);
	p->tubes = 1;
	if (p->tubes == 1 && p->start == 1 && p->end == 1)
	{
		g->matrice[j][i] = 1;
		g->matrice[i][j] = 1;
		if (p->graphe == 1)
		{
			put_graphe(*g);
			print_matrice(p);
		}
	}
	return (1);
}

int		check_salles_2(char *str, t_p *p)
{
	int i;

	i = 0;
	while ((str[i] >= '!' && str[i] <= 44) || (str[i] >= 46 && str[i] <= '~'))
		i++;
	if (str[i] != ' ')
		return (0);
	i++;
	if (p->tubes == 1)
		return (0);
	if (ft_digit_mod(str + i) != 2)
		return (0);
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		i++;
	if (str[i] != ' ')
		return (0);
	i++;
	if (ft_digit_mod(str + i) != 1)
		return (0);
	while (((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
			|| str[i] == '-')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int		check_salles(t_p *p, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (((str[i] >= '!' && str[i] <= 44) || (str[i] >= 46 && str[i] <= '~')))
	{
		if (check_salles_2(str, p) == 0)
			return (0);
		if (p->start == 1 && p->s == 2 && ft_str(p->s_start, str) == 0)
			return (0);
		if (p->end == 1 && p->e == 2 && ft_str(p->s_end, str) == 0)
			return (0);
		if ((i = lstcmp1(str, p->list, ' ', &j)) != 0)
			return (0);
		stock_salles(p, str);
		return (1);
	}
	return (0);
}
