/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:11:21 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/02/19 14:00:28 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	ft_isit_there(t_list stack, int pos)
{
	int	index;

	index = 0;
	while (index < stack.data.lenght)
	{
		if (stack.items[index].position >= pos)
			return (1);
		index++;
	}
	return (0);
}

void	ft_rotate_b(t_data *data, int position, int pos)
{
	if (data->stack_a.data.lenght > 0)
	{
		position = data->stack_a.items[data->stack_a.data.lenght - 1].position;
		if (position < pos)
			rotate_stack(data, '2');
		else
			rotate_stack(data, 'b');
	}
	else
		rotate_stack(data, 'b');
}

void	filter_stack(t_data *data, int pos)
{
	int	len;
	int	midlle;
	int	position;

	len = data->stack_a.data.lenght;
	midlle = (len - pos) / 2 + pos;
	while (ft_isit_there(data->stack_a, pos))
	{
		position = data->stack_a.items[data->stack_a.data.lenght - 1].position;
		if (position >= pos)
		{
			push_stack(data, 'b');
			if (position > midlle)
				ft_rotate_b(data, position, pos);
		}
		else
			rotate_stack(data, 'a');
	}
}

void	ft_gethem_back(t_data *data)
{
	t_positions	positions;
	int			index;

	index = 0;
	while (data->stack_b.data.lenght > 0)
	{
		positions = find_two(data, index);
		if (positions.position1 != -1)
		{
			ft_pushback(data, positions.position1);
			index++;
		}
		if (positions.position2 != -1)
		{
			ft_pushback(data, positions.position2);
			index++;
		}
		if (data->stack_a.items[data->stack_a.data.lenght - 1].position
			< data->stack_a.items[data->stack_a.data.lenght - 2].position)
			swap_stack(data, 'a');
	}
}

void	main_sort(t_data *data, int number)
{
	unsigned int	len;
	unsigned int	num;

	len = data->stack_a.data.lenght;
	num = number;
	while (number-- > 0)
	{
		filter_stack(data, number * len / num);
	}
	ft_gethem_back(data);
}
