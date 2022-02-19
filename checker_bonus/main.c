/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:08:26 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/02/18 15:20:54 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_var	ft_atoi(char *number)
{
	t_var	var;
	int		sign;

	var.index = 0;
	var.number = 0;
	var.ko = 0;
	sign = 1;
	if (number[var.index] == '-')
	{
		var.index++;
		sign = -1;
	}
	while (number[var.index] <= '9' && number[var.index] >= '0')
	{
		var.number = var.number * 10 + (number[var.index] - 48);
		var.index++;
	}
	var.number *= sign;
	if (number[var.index] != 0 || var.number > INT_MAX
		|| var.number < INT_MIN || number[var.index - 1] == '-')
		var.ko = 1;
	return (var);
}

void	ft_init(t_data *data, char **args, int count)
{
	int		index;
	t_var	var;

	index = 0;
	while (index < count)
	{
		var = ft_atoi(args[count - index - 1]);
		if (var.ko == 1)
			break ;
		data->stack_a.items[index].value = var.number;
		data->stack_b.items[index].value = 0;
		data->stack_a.items[index].position = -1;
		data->stack_a.data.lenght++;
		index++;
	}
	if (var.ko != 1)
	{
		data->stack_a.data.size = count;
		data->stack_b.data.size = count;
		data->stack_b.data.lenght = 0;
	}
	else
		ft_free(data, 0, var.ko);
}

t_item	ft_get_start(t_data *data)
{
	int		index;
	t_item	item;

	index = 0;
	item.position = 0;
	item.value = 0;
	while (index < data->stack_a.data.lenght)
	{
		if (data->stack_a.items[index].position == -1)
		{
			item.position = index;
			item.value = data->stack_a.items[index].value;
			break ;
		}
		index++;
	}
	return (item);
}

void	ft_get_positions(t_data *data)
{
	t_item	item;
	int		index;
	int		position;

	position = 0;
	while (position < data->stack_a.data.lenght)
	{
		index = 0;
		item = ft_get_start(data);
		while (index < data->stack_a.data.lenght)
		{
			if (data->stack_a.items[index].value > item.value
				&& data->stack_a.items[index].position == -1)
			{
				item.value = data->stack_a.items[index].value;
				item.position = index;
			}
			index++;
		}
		data->stack_a.items[item.position].position = position;
		position++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		data.stack_a.items = (t_item *)malloc(sizeof(t_list) * (argc - 1));
		data.stack_b.items = (t_item *)malloc(sizeof(t_list) * (argc - 1));
		ft_init(&data, argv + 1, argc - 1);
		ft_checkdup(&data);
		ft_get_positions(&data);
		check_moves(&data);
		ft_free(&data, 0, 0);
	}
	return (0);
}
