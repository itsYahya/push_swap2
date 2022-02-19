/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:45:17 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/02/19 15:38:56 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_free(t_data *data, int ko)
{
	if (data->stack_b.items)
		free(data->stack_b.items);
	if (data->stack_a.items)
		free(data->stack_a.items);
	if (ko)
	{
		write(2, "Error\n", 6);
		exit(1);
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
				ft_free(data, 1);
			i++;
		}
		index++;
	}
}

int	ft_sorted(t_data *data)
{
	int	index;
	int	len;

	len = data->stack_a.data.lenght;
	index = 0;
	while (index < len)
	{
		if (data->stack_a.items[index].position != index)
			return (1);
		index++;
	}
	return (0);
}
