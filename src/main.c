/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 07:23:32 by eozdek            #+#    #+#             */
/*   Updated: 2016/03/28 23:20:58 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	int			i;
	t_graphe	*g;
	t_p			*p;
	char		*line;

	i = 1;
	p = (t_p*)malloc(sizeof(t_p));
	g = (t_graphe*)malloc(sizeof(t_graphe));
	init_p(p);
	while (get_next_line(0, &line) == 1)
	{
		p->j = 0;
		ft_continue(g, p, line, &i);
		ft_continue_2(g, i, p, line);
		if (i > 1 && p->j != -1 && (p->j = ft_reste_line(g, p, line)) == 0)
			error(g, p, i, line);
		p->line2 = ft_strjoin(p->line2, ft_strjoin(line, "\n"));
		i++;
	}
	path_resolve(g, p);
	if (p->e != 2 || p->s != 2 || p->f != 1 || p->q == 0)
		error(g, p, i, line);
	free(p);
	free(g);
	return (0);
}
