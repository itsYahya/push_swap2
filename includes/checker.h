/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:55:57 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/02/19 16:08:39 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "data.h"
# include "moves.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_free(t_data *data, char *buffer, int ko);
void	ft_checkdup(t_data *data);
int		ft_sorted(t_data *data);
void	ft_get_positions(t_data *data);
t_item	ft_get_start(t_data *data);
void	ft_init(t_data *data, char **args, int count);
t_var	ft_atoi(char *number);
void	check_moves(t_data *data);
int		ft_strncmp(const char *str1, const char *str2, size_t n);

#endif