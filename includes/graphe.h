/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphe.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 16:28:44 by eozdek            #+#    #+#             */
/*   Updated: 2016/03/26 16:54:18 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHE_H
# define GRAPHE_H
# include "lem_in.h"

typedef	struct			s_list_type
{
	int					data;
	char				*salles;
	struct s_list_type	*next;
	struct s_list_type	*prev;
}						t_list_type;

#endif
