/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lem_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 16:14:42 by eozdek            #+#    #+#             */
/*   Updated: 2016/03/28 23:26:27 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lem_check(int *tab, t_p *p)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < p->n)
	{
		if (tab[i] <= p->fourmi && tab[i] > 0)
			j++;
		i++;
	}
	return (j);
}

void	handle_print(t_p *p, int *tab, int *tab1)
{
	int i;
	int j;

	i = p->n;
	j = lem_check(tab, p);
	while (i > 0)
	{
		if (p->fourmi >= tab[p->n - 1] && tab[i] >= 1)
		{
			if (tab[i] <= p->fourmi)
			{
				ft_putchar('L');
				ft_putnbr(tab[i]);
				ft_putchar('-');
				ft_putstr(p->matrice[tab1[i]]);
				if (j > 1)
					ft_putchar(' ');
				j--;
			}
		}
		i--;
	}
	ft_putchar('\n');
}

void	print_without(t_p *p, int *tab, int *tab1)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (1)
	{
		handle_print(p, tab, tab1);
		if (tab[p->n - 1] >= p->fourmi)
			break ;
		i = 0;
		while (i < p->n)
		{
			tab[i] += 1;
			i++;
		}
		i = 0;
		p->step += p->step > 0 ? 1 : 0;
	}
}

void	handle_print_color(t_p *p, int *tab, int *tab1, int i)
{
	int j;

	j = lem_check(tab, p);
	while (i > 0)
	{
		if (p->fourmi >= tab[p->n - 1] && tab[i] >= 1)
		{
			if (tab[i] <= p->fourmi)
			{
				ft_putstr("\033[93mL\033[0m");
				ft_putstr("\033[92m");
				ft_putnbr(tab[i]);
				ft_putstr("\033[0m");
				ft_putstr("\033[96m");
				ft_putchar('-');
				ft_putstr("\033[0m");
				ft_putstr("\033[91m");
				ft_putstr(p->matrice[tab1[i]]);
				ft_putstr("\033[0m");
				j > 1 ? ft_putchar(' ') : "";
				j--;
			}
		}
		i--;
	}
}

void	print_color(t_p *p, int *tab, int *tab1)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (1)
	{
		handle_print_color(p, tab, tab1, p->n);
		ft_putchar('\n');
		if (tab[p->n - 1] >= p->fourmi)
			break ;
		i = 0;
		while (i < p->n)
		{
			tab[i] += 1;
			i++;
		}
		i = 0;
		p->step += p->step > 0 ? 1 : 0;
	}
}
