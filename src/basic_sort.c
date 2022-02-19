/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:01:32 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/02/18 12:43:07 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	basic_puah_b(t_data *data, int index, int len, int pos)
{
	if (index > data->stack_a.data.lenght / 2)
	{
		while (1)
		{
			if (data->stack_a.items[len - 1].position == pos)
				break ;
			rotate_stack(data, 'a');
		}
	}
	else
	{
		while (1)
		{
			if (data->stack_a.items[len - 1].position == pos)
				break ;
			rrotate_stack(data, 'a');
		}
	}
	push_stack(data, 'b');
}

void	basic_push(t_data *data, int position)
{
	int	index;
	int	len;

	index = 0;
	len = data->stack_a.data.lenght;
	while (index < len)
	{
		if (data->stack_a.items[index].position == position)
			break ;
		index++;
	}
	basic_puah_b(data, index, len, position);
}

int	ft_basic_getindex(t_data *data)
{
	int	index;

	index = 0;
	while (index < 3)
	{
		if (data->stack_a.items[index].position == 0)
			break ;
		index++;
	}
	return (index);
}

void	basic_3_sort(t_data *data)
{
	int	index;

	index = ft_basic_getindex(data);
	if (index == 0)
		swap_stack(data, 'a');
	else if (index == 1)
	{
		if (data->stack_a.items[2].position > data->stack_a.items[0].position)
		{
			swap_stack(data, 'a');
			rotate_stack(data, 'a');
		}
		else
			rrotate_stack(data, 'a');
	}
	else
	{
		rotate_stack(data, 'a');
		if (data->stack_a.items[2].position < data->stack_a.items[1].position)
			swap_stack(data, 'a');
	}
}

void	basic_sort(t_data *data)
{
	int	index;

	index = data->stack_a.data.lenght;
	while (index-- > 3)
	{
		basic_push(data, index);
	}
	if (ft_sorted(data))
	{
		if (data->stack_a.data.lenght == 2)
			rotate_stack(data, 'a');
		else
			basic_3_sort(data);
	}
	while (data->stack_b.data.lenght > 0)
		push_stack(data, 'a');
}
