/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 12:35:25 by eozdek            #+#    #+#             */
/*   Updated: 2016/03/26 17:49:17 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lstcmp(char *str, t_list_type *list, int *i)
{
	t_list_type *tmp;
	int			j;
	int			q;

	tmp = list;
	j = 0;
	q = 0;
	if (list == NULL)
		return (-1);
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->salles, str) == 0)
		{
			j++;
			*i = q;
		}
		tmp = tmp->next;
		q++;
	}
	if (ft_strcmp(tmp->salles, str) == 0)
	{
		j++;
		*i = q;
	}
	return (j);
}

int		lstcmp1(char *str, t_list_type *list, char c, int *i)
{
	int		j;
	char	*s;

	j = 0;
	*i = 0;
	while (str[j] != c)
		j++;
	if (list == NULL)
		return (0);
	s = ft_cutstring_1(str, j, c);
	if ((j = lstcmp(s, list, i)) == -1)
	{
		return (-1);
	}
	return (j);
}

int		lstcmp2(char *str, t_list_type *list, int *i)
{
	int		j;
	char	*s;

	j = 0;
	*i = 0;
	if (list == NULL)
		return (0);
	while (str[j] != '-')
		j++;
	s = ft_cutstring_2(str, j + 1);
	if ((j = lstcmp(s, list, i)) == -1)
		return (-1);
	return (j);
}

int		ft_digit_mod(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		i++;
	}
	if (str[i] == ' ')
		return (2);
	if (str[i] == '\0')
		return (1);
	return (0);
}

int		ft_digit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}
