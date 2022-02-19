/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:42:53 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/02/17 18:27:56 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

# include "data.h"
# include <unistd.h>
# include <stdio.h>

void	swap_stack(t_data *data, int to_do);
void	push_stack(t_data *data, int to_do);
void	rotate_stack(t_data *data, int to_do);
void	rrotate_stack(t_data *data, int to_do);

#endif