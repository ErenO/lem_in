/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 04:17:12 by eozdek            #+#    #+#             */
/*   Updated: 2016/03/28 22:28:24 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_list(t_list_type *list)
{
	t_list_type *tmp;

	tmp = list;
	while (tmp != NULL)
	{
		ft_putstr(tmp->salles);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

int		*init_tab(t_p *p)
{
	int i;
	int j;
	int *tab;

	i = 1;
	j = 0;
	tab = (int *)malloc(sizeof(int) * p->n + 1);
	while (j < p->n)
	{
		tab[j] = i;
		i--;
		j++;
	}
	return (tab);
}

void	print_matrice(t_p *p)
{
	int i;

	i = 0;
	ft_putendl("MATRICE ");
	while (i < ft_list_size(p->list))
	{
		ft_putendl(p->matrice[i]);
		i++;
	}
}

void	list_to_tab(t_list_type *list, t_p *p)
{
	int i;

	i = 0;
	p->matrice = (char **)malloc(sizeof(char*) * ft_list_size(p->list));
	while (list != NULL)
	{
		p->matrice[i] = ft_strdup(list->salles);
		list = list->next;
		i++;
	}
}

void	print_lem(t_p *p, int *tab, int *tab1)
{
	if (p->color == 1)
	{
		print_color(p, tab, tab1);
	}
	else
	{
		print_without(p, tab, tab1);
	}
	if (p->step > 0)
	{
		putn(p->step - 1);
	}
}
