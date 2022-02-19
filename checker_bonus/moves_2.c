/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:38:24 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/02/18 15:23:37 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves.h"

void	rotate_(t_list *stack)
{
	unsigned int	len;
	t_item			item;

	len = stack->data.lenght;
	item = stack->items[--len];
	while (len > 0)
	{
		stack->items[len] = stack->items[len - 1];
		len--;
	}
	stack->items[0] = item;
}

void	rotate_stack(t_data *data, int to_do)
{
	int	len_a;
	int	len_b;

	len_a = data->stack_a.data.lenght;
	len_b = data->stack_b.data.lenght;
	if (to_do == 'a' && len_a > 1)
		rotate_(&data->stack_a);
	else if (to_do == 'b' && len_b > 1)
		rotate_(&data->stack_b);
	else if (to_do == '2' && len_b > 1 && len_a > 1)
	{
		rotate_(&data->stack_b);
		rotate_(&data->stack_a);
	}
}

void	rrotate_(t_list *stack)
{
	int		len;
	int		index;
	t_item	item;

	index = 0;
	len = stack->data.lenght;
	item = stack->items[index];
	while (index < len - 1)
	{
		stack->items[index] = stack->items[index + 1];
		index++;
	}
	stack->items[index] = item;
}

void	rrotate_stack(t_data *data, int to_do)
{
	int	len_a;
	int	len_b;

	len_a = data->stack_a.data.lenght;
	len_b = data->stack_b.data.lenght;
	if (to_do == 'a')
		rrotate_(&data->stack_a);
	else if (to_do == 'b' && len_b > 1)
		rrotate_(&data->stack_b);
	else if (to_do == '2' && len_b > 1 && len_a > 1)
	{
		rrotate_(&data->stack_b);
		rrotate_(&data->stack_a);
	}
}
