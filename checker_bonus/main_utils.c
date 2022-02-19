/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:45:17 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/02/18 15:26:48 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_free(t_data *data, char *buffer, int ko)
{
	if (data->stack_b.items)
		free(data->stack_b.items);
	if (data->stack_a.items)
		free(data->stack_a.items);
	if (buffer)
		free(buffer);
	if (ko)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	ft_checkdup(t_data *data)
{
	int	index;
	int	i;
	int	len;

	index = 0;
	len = data->stack_a.data.lenght;
	while (index < len)
	{
		i = 0;
		while (i < index)
		{
			if (data->stack_a.items[index].value
				== data->stack_a.items[i].value)
				ft_free(data, 0, 1);
			i++;
		}
		index++;
	}
}

int	ft_sorted(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->stack_a.data.lenght)
	{
		if (data->stack_a.items[index].position != index)
			return (1);
		index++;
	}
	return (0);
}
