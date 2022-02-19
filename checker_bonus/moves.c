/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:22:24 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/02/18 16:22:45 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves.h"

void	swap_(t_list *stack)
{
	t_item			item;
	unsigned int	len;

	len = stack->data.lenght - 1;
	item = stack->items[len];
	stack->items[len] = stack->items[len - 1];
	stack->items[len - 1] = item;
}

void	swap_stack(t_data *data, int to_do)
{
	int	len_a;
	int	len_b;

	len_a = data->stack_a.data.lenght;
	len_b = data->stack_b.data.lenght;
	if (to_do == 'a' && len_a > 1)
		swap_(&data->stack_a);
	else if (to_do == 'b' && len_b > 1)
		swap_(&data->stack_b);
	else if (to_do == '2' && len_a > 1 && len_b > 1)
	{
		swap_(&data->stack_b);
		swap_(&data->stack_a);
	}
}

void	push_to(t_list *stack_from, t_list *stack_to)
{
	unsigned int	len_from;
	unsigned int	len_to;

	len_from = stack_from->data.lenght - 1;
	len_to = stack_to->data.lenght;
	stack_to->items[len_to] = stack_from->items[len_from];
	stack_from->data.lenght--;
	stack_to->data.lenght++;
}

void	push_stack(t_data *data, int to_do)
{
	if (to_do == 'a')
		push_to(&data->stack_b, &data->stack_a);
	else if (to_do == 'b')
		push_to(&data->stack_a, &data->stack_b);
}
