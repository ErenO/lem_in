/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 12:24:57 by eozdek            #+#    #+#             */
/*   Updated: 2016/03/28 23:20:13 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		tab_control(int **tab, int *y, int s)
{
	int i;
	int j;
	int n;
	int m;

	j = 0;
	i = *y - 1;
	i = tab_2(tab, i, y, s);
	while (tab[i][1] != s)
	{
		tab[i][1] = -1;
		tab[i][0] = -1;
		i--;
	}
	m = *y;
	n = i;
	*y = i;
	tab_3(tab, i, n);
	i = 0;
	while (m > i)
	{
		j += tab[i][0] != -1 ? 1 : 0;
		i++;
	}
	return (j + 1);
}

int		*tab_put(int **tab, int y, int size)
{
	int i;
	int *ret;

	i = y;
	ret = (int*)malloc(sizeof(int) * (size));
	ret[size - 1] = tab[i][1];
	size--;
	while (i > 0 && size > 0)
	{
		if (tab[i][0] != -1 && tab[i][1] != -1)
		{
			ret[size - 1] = tab[i][0];
			size--;
		}
		i--;
	}
	return (ret);
}

void	print_tab(int **tab, int g)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_putchar('\n');
	while (i < g)
	{
		j = 0;
		while (j < 2)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

char	*ft_cutstring_1(char *str, int i, char c)
{
	char	*s;
	int		n;

	n = 0;
	s = (char *)malloc(sizeof(char) * (i + 1));
	while (str[n] != c && str[n] != '\0')
	{
		s[n] = str[n];
		n++;
	}
	s[n] = '\0';
	return (s);
}

char	*ft_cutstring_2(char *str, int i)
{
	char	*s;
	int		n;

	n = 0;
	s = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	while (str[i + n] != '\0')
	{
		s[n] = str[i + n];
		n++;
	}
	s[n] = '\0';
	return (s);
}
