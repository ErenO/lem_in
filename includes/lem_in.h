/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 07:42:24 by eozdek            #+#    #+#             */
/*   Updated: 2016/03/29 00:39:20 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <unistd.h>
# include "../libft/includes/libft.h"
# include "./get_next_line.h"
# include "./graphe.h"

typedef struct	s_p
{
	int			step;
	int			path;
	int			q;
	int			j;
	int			end;
	int			start;
	int			e;
	int			s;
	int			salle;
	int			tubes;
	int			color;
	int			error;
	int			fourmi;
	int			n;
	int			line;
	int			f;
	int			graphe;
	char		*s_start;
	char		*line2;
	char		*s_end;
	char		**salles;
	char		**matrice;
	t_list_type *list;
}				t_p;

typedef struct
{
	int			m;
}				t_somm;

typedef struct
{
	int			n;
	int			j;
	int			q;
	int			s;
	int			p;
	t_somm		*tab;
	int			**matrice;
	int			**matrice1;
}				t_graphe;

long long int	ft_latoi(char *str);
void			tab_4(int **tab, int *y);
void			putn(int nb);
int				ft_care_3(t_graphe *g, t_p *p, char *str);
void			list_maker(t_p *p, t_graphe *g);
void			tab_3(int **tab, int i, int n);
int				tab_2(int **tab, int i, int *y, int s);
int				ft_care_2(t_p *p, char *str);
void			free_tabs(int **tab, int *tab1, int *tab2);
int				check_tubes_2(t_graphe *g, t_p *p, char *str);
int				check_salles_2(char *str, t_p *p);
int				check_tubes(t_graphe *g, t_p *p, char *str);
int				path_resolve(t_graphe *g, t_p *p);
int				ft_care(t_graphe *g, t_p *p, char *str);
int				ft_visit(t_graphe *g, int s, int s2, int *j);
int				ft_visit2(t_graphe *g, int s, int s2, int **tab);
int				ft_path(t_graphe *g, int s1, int s2, int *j);
int				**ft_path2(t_graphe *g, int s1, int s2, int **tab);
int				ft_reste_line(t_graphe *g, t_p *p, char *str);
void			init_graph(t_graphe *g, t_p *p);
void			put_graphe(t_graphe g);
void			init_graph_s(t_graphe *g);
void			error(t_graphe *g, t_p *p, int i, char *str);
void			ft_continue_2(t_graphe *g, int i, t_p *p, char *line);
void			ft_continue(t_graphe *g, t_p *p, char *line, int *i);
char			*ft_sert(char *str, int i, int y);
char			*ft_stock(char *str, int i);
char			*ft_cutstring_2(char *str, int i);
char			*ft_cutstring_1(char *str, int i, char c);
int				ft_str(char *s1, char *s2);
int				*init_tab(t_p *p);
int				ft_list_size(t_list_type *begin_list);
int				lstcmp2(char *str, t_list_type *list, int *i);
int				lstcmp(char *str, t_list_type *list, int *i);
int				lstcmp1(char *str, t_list_type *list, char c, int *i);
int				ft_digit_mod(char *str);
int				check_salles(t_p *p, char *str);
int				ft_digit(char *str);
int				tab_control(int **tab, int *y, int s);
int				*tab_put(int **tab, int y, int size);
int				ft_first_line(t_p *p, char *str);
int				lem_check(int *tab, t_p *p);
void			stock_salles(t_p *p, char *str);
void			print_path(t_p *p, int *tab);
void			init_p(t_p *p);
void			print_tab_s(int *tab, int q);
void			print_tab(int **tab, int g);
void			list_to_tab(t_list_type *list, t_p *p);
void			print_matrice(t_p *p);
void			print_lem(t_p *p, int *tab, int *tab1);
void			print_without(t_p *p, int *tab, int *tab1);
void			print_tab(int **tab, int g);
void			handle_print(t_p *p, int *tab, int *tab1);
void			print_color(t_p *p, int *tab, int *tab1);
void			print_list(t_list_type *list);
void			handle_print_color(t_p *p, int *tab, int *tab1, int i);
t_list_type		*ft_insert_end(t_list_type *list, char *str);
t_list_type		*ft_insert(t_p *p, char *str, int i);
t_list_type		*add_link(t_list_type *list, char *str);

#endif
