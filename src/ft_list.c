/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 11:20:19 by eozdek            #+#    #+#             */
/*   Updated: 2016/03/27 16:07:07 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list_type		*add_link(t_list_type *list, char *str)
{
	t_list_type *tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->salles = ft_strdup(str);
		tmp->next = list;
		tmp->prev = NULL;
	}
	return (tmp);
}

char			*ft_sert(char *str, int i, int y)
{
	int		n;
	char	*s;

	n = 0;
	if (i == 0)
		s = (char *)malloc(sizeof(char) * (ft_strlen(str)));
	if (i == 1)
		s = (char *)malloc(sizeof(char) * (y + 1));
	while (str[n] != ' ' && str[n] != '\0')
	{
		s[n] = str[n];
		n++;
	}
	s[n] = '\0';
	return (s);
}

t_list_type		*ft_insert_end(t_list_type *list, char *str)
{
	t_list_type *tmp;
	t_list_type *tmp1;

	tmp = (t_list_type *)malloc(sizeof(t_list_type));
	tmp->salles = ft_sert(str, 0, 0);
	tmp->next = NULL;
	tmp1 = list;
	if (list == NULL)
	{
		tmp->prev = NULL;
		return (tmp);
	}
	else
	{
		while (tmp1->next != NULL)
			tmp1 = tmp1->next;
		tmp1->next = tmp;
		tmp->prev = tmp1;
	}
	return (list);
}

t_list_type		*ft_insert(t_p *p, char *str, int i)
{
	t_list_type *tmp;
	t_list_type *tmp1;

	tmp = (t_list_type*)malloc(sizeof(t_list_type));
	tmp->salles = ft_sert(str, 1, i);
	tmp->next = NULL;
	tmp1 = p->list;
	if (p->list == NULL)
	{
		tmp->prev = NULL;
		return (tmp);
	}
	else
	{
		while (tmp1->next != NULL)
			tmp1 = tmp1->next;
		tmp1->next = tmp;
		tmp->prev = tmp1;
	}
	return (p->list);
}

int				ft_list_size(t_list_type *begin_list)
{
	t_list_type *tmp;
	int			i;

	i = 1;
	tmp = begin_list;
	if (begin_list == NULL)
	{
		return (0);
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
