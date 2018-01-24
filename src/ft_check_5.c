/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 23:31:50 by eozdek            #+#    #+#             */
/*   Updated: 2016/03/29 00:38:13 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			tab_4(int **tab, int *y)
{
	int j;

	j = 0;
	if (*y > 1 && tab[*y - 1][0] == tab[*y - 2][0])
	{
		j = *y - 2;
		while (tab[*y - 1][0] == tab[j][0])
		{
			tab[j][1] = -1;
			tab[j][0] = -1;
			j--;
		}
	}
}

void			putn(int nb)
{
	ft_putstr("NOMBRE D'ETAPES : \033[92m");
	ft_putnbr(nb);
	ft_putchar('\n');
	ft_putstr("\033[0m");
}

long long int	ft_latoi(char *str)
{
	long long int i;
	long long int nb;
	long long int neg;

	i = 0;
	nb = 0;
	neg = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	neg += str[i] == '-' ? 1 : 0;
	if (ft_strcmp(str + i, "-2147483648\0") == 0)
	{
		return (-2147483648);
	}
	i += str[i] == '-' || str[i] == '+' ? 1 : 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += (str[i] - '0');
		i++;
	}
	return (neg == 1) ? -(nb) : (nb);
}
