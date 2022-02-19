/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:37:31 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/02/18 13:00:18 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_listdata
{
	int	size;
	int	lenght;
}	t_listdata;

typedef struct s_item
{
	int	value;
	int	position;	
}	t_item;

typedef struct s_list
{
	t_item		*items;
	t_listdata	data;
}	t_list;

typedef struct s_data
{
	t_list	stack_a;
	t_list	stack_b;
}	t_data;

typedef struct s_var
{
	long	number;
	int		index;
	int		ko;
	int		go_up;
}	t_var;

typedef struct s_positions
{
	int	position1;
	int	position2;
}	t_positions;

#endif