/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 16:56:32 by eozdek            #+#    #+#             */
/*   Updated: 2016/03/29 00:36:38 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_care_2(t_p *p, char *str)
{
	if (str[0] == 'L' || str[0] == '\0')
		return (0);
	if (ft_strcmp(str, "##line\0") == 0)
	{
		p->line = 1;
		return (1);
	}
	if (ft_strcmp(str, "##graphe\0") == 0)
	{
		p->graphe = 1;
		return (1);
	}
	if (ft_strcmp(str, "##color\0") == 0)
	{
		p->color = 1;
		return (1);
	}
	if (ft_strcmp(str, "##path\0") == 0)
	{
		p->path = 1;
		return (1);
	}
	return (2);
}

int		ft_first_line(t_p *p, char *str)
{
	int i;

	i = 0;
	if ((i = ft_care_2(p, str)) != 2)
		return (i);
	if (str[0] == '#' && (ft_strcmp(str, "##start\0") != 0)
		&& (ft_strcmp(str, "##end\0") != 0))
		return (1);
	if (ft_digit(str) == 1)
	{
		p->fourmi = ft_latoi(str);
		p->f = 1;
		if (p->fourmi > 0 && p->fourmi <= 2147483647)
			return (2);
		else
			return (0);
	}
	return (0);
}

int		ft_care_3(t_graphe *g, t_p *p, char *str)
{
	if (ft_strcmp(str, "##line\0") == 0 && p->s != 1 && p->e != 1)
	{
		p->line = 1;
		return (1);
	}
	if (ft_strcmp(str, "##step\0") == 0 && p->s != 1 && p->e != 1)
	{
		p->step = 1;
		return (1);
	}
	if (ft_strcmp(str, "##end\0") == 0 && p->end == 0 && p->s != 1 && p->e != 1)
	{
		p->end = 1;
		p->e = 1;
		return (2);
	}
	if (((check_salles(p, str) == 1)
		|| (check_tubes(g, p, str) == 1)) && p->s != 1 && p->e != 1)
		return (1);
	if (ft_strcmp(str, "##graphe\0") == 0 && p->s != 1 && p->e != 1)
	{
		p->graphe = 1;
		return (1);
	}
	return (3);
}

int		ft_care(t_graphe *g, t_p *p, char *str)
{
	int i;

	i = 0;
	if ((i = ft_care_3(g, p, str)) != 3)
		return (i);
	if (ft_strcmp(str, "##path\0") == 0 && p->s != 1 && p->e != 1)
	{
		p->path = 1;
		return (1);
	}
	if (str[0] == '#' && (ft_strcmp(str, "##start\0") != 0)
		&& (ft_strcmp(str, "##end\0") != 0) && p->s != 1 && p->e != 1)
	{
		return (1);
	}
	return (3);
}

int		ft_reste_line(t_graphe *g, t_p *p, char *str)
{
	int i;

	i = 0;
	if (str[0] == 'L' || str[0] == '\0')
		return (0);
	if (ft_strcmp(str, "##color\0") == 0 && p->s != 1 && p->e != 1)
	{
		p->color = 1;
		return (1);
	}
	if (ft_strcmp(str, "##start\0") == 0 && p->start == 0
		&& p->s != 1 && p->e != 1)
	{
		p->start = 1;
		p->s = 1;
		return (2);
	}
	if ((i = ft_care(g, p, str)) != 3)
		return (i);
	return (0);
}
