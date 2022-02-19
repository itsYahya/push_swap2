/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:08:13 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/02/18 14:13:19 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <limits.h>
# include "moves.h"

t_var		ft_atoi(char *number);
void		ft_init(t_data *data, char **args, int count);
t_item		ft_get_start(t_data *data);
void		ft_get_positions(t_data *data);
void		main_sort(t_data *data, int number);
void		ft_pushback(t_data *data, int position);
void		ft_bringit_top(t_data *data, int up, int len, int position);
t_positions	find_two(t_data *data, int i);
void		ft_swap_ifneeded(t_positions *pos, int index, int j, int len);
int			find_position(t_data *data, int *pos, int *positions_);
void		ft_gethem_back(t_data *data);
void		filter_stack(t_data *data, int pos);
void		ft_rotate_b(t_data *data, int position, int pos);
int			ft_isit_there(t_list stack, int pos);
t_item		ft_get_start(t_data *data);
void		ft_free(t_data *data, int ko);
void		ft_checkdup(t_data *data);
int			ft_sorted(t_data *data);
void		basic_sort(t_data *data);
void		basic_3_sort(t_data *data);
int			ft_basic_getindex(t_data *data);
void		basic_push(t_data *data, int position);
void		basic_puah_b(t_data *data, int index, int len, int pos);

#endif