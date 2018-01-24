/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 11:12:51 by eozdek            #+#    #+#             */
/*   Updated: 2016/03/28 23:17:04 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(t_graphe *g, t_p *p, int i, char *str)
{
	path_resolve(g, p);
	if (p->line == 1)
	{
		ft_putstr("LINE ");
		ft_putnbr(i);
		ft_putchar('\n');
		ft_putstr("\033[92m");
		ft_putendl(str);
		ft_putstr("\033[0m");
	}
	if (p->error == 1)
	{
		write(1, "ERROR\n", 6);
	}
	exit(0);
}

void	print_path(t_p *p, int *tab)
{
	int i;
	int j;

	i = 1;
	j = p->n;
	ft_putchar('\n');
	ft_putstr("PATH : ");
	ft_putstr("\033[96m[\033[0m\033[93m");
	ft_putstr(p->matrice[0]);
	ft_putstr("\033[0m\033[96m]\033[0m \033[94m=>\033[0m ");
	if (p->n > 1)
	{
		while (i < p->n)
		{
			ft_putstr("\033[96m[\033[0m\033[93m");
			ft_putstr(p->matrice[tab[i]]);
			ft_putstr("\033[0m\033[96m]\033[0m");
			if (i != p->n - 1)
				ft_putstr("\033[94m => \033[0m");
			i++;
		}
		ft_putchar('\n');
	}
}

char	*ft_stock(char *str, int i)
{
	int		n;
	char	*s;

	n = 0;
	s = (char *)malloc(sizeof(char) * (i + 1));
	while (str[n] != ' ')
	{
		s[n] = str[n];
		n++;
	}
	s[n] = '\0';
	return (s);
}

void	stock_salles(t_p *p, char *str)
{
	int i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	if (p->start == 1 && p->s == 1)
	{
		p->s_start = ft_stock(str, i);
		p->s = 2;
	}
	else if (p->end == 1 && p->e == 1)
	{
		p->s_end = ft_stock(str, i);
		p->e = 2;
	}
	else
		p->list = ft_insert(p, str, i);
}

int		ft_str(char *s1, char *s2)
{
	int		i;
	char	*s;

	i = 0;
	while (s2[i] != ' ')
		i++;
	s = ft_cutstring_1(s2, i, ' ');
	if (ft_strcmp(s1, s) == 0 || ft_strcmp(s1, s2) == 0)
		return (0);
	return (1);
}
