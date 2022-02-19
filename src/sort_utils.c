/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:03:12 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/02/17 19:00:03 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	find_position(t_data *data, int *pos, int *positions_)
{
	int	index;
	int	len;

	index = 0;
	len = data->stack_b.data.lenght;
	while (index < len)
	{
		if (*pos == data->stack_b.items[index].position)
		{
			*positions_ = *pos;
			*pos += 1;
			return (index);
		}
		index++;
	}
	return (index);
}

void	ft_swap_ifneeded(t_positions *pos, int index, int j, int len)
{
	int	swap;

	if (index > len / 2)
		index = len - index;
	if (j > len / 2)
		j = len - j;
	if (j < index)
	{
		swap = pos->position1;
		pos->position1 = pos->position2;
		pos->position2 = swap;
	}
}

t_positions	find_two(t_data *data, int i)
{
	t_positions	pos;
	int			index;
	int			j;
	int			len;

	index = 0;
	j = 0;
	len = data->stack_b.data.lenght;
	pos.position1 = -1;
	pos.position2 = -1;
	index = find_position(data, &i, &pos.position1);
	j = find_position(data, &i, &pos.position2);
	ft_swap_ifneeded(&pos, index, j, len);
	return (pos);
}

void	ft_bringit_top(t_data *data, int up, int len, int position)
{
	if (up)
	{
		while (1)
		{
			if (data->stack_b.items[len - 1].position == position)
				break ;
			rotate_stack(data, 'b');
		}
	}
	else
	{
		while (1)
		{
			if (data->stack_b.items[len - 1].position == position)
				break ;
			rrotate_stack(data, 'b');
		}
	}
	push_stack(data, 'a');
}

void	ft_pushback(t_data *data, int position)
{
	int	index;
	int	len;

	len = data->stack_b.data.lenght;
	index = 0;
	while (index < len)
	{
		if (data->stack_b.items[index].position == position)
			break ;
		index++;
	}
	ft_bringit_top(data, (index > len / 2), len, position);
}
