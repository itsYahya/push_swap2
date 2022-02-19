/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:31:23 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/02/19 15:19:46 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	make_moves_3(t_data *data, char *move, int number)
{
	if (ft_strncmp(move, "rra\n", number) == 0)
	{
		rrotate_stack(data, 'a');
		return (1);
	}
	else if (ft_strncmp(move, "rrb\n", number) == 0)
	{
		rrotate_stack(data, 'b');
		return (1);
	}
	else if (ft_strncmp(move, "rrr\n", number) == 0)
	{
		rrotate_stack(data, '2');
		return (1);
	}
	return (0);
}

int	make_moves_2(t_data *data, char *move, int number)
{
	if (ft_strncmp(move, "rb\n", number) == 0)
	{
		rotate_stack(data, 'b');
		return (1);
	}
	else if (ft_strncmp(move, "rr\n", number) == 0)
	{
		rotate_stack(data, '2');
		return (1);
	}
	else
		return (make_moves_3(data, move, number));
}

int	make_moves_1(t_data *data, char *move, int number)
{
	if (ft_strncmp(move, "pa\n", number) == 0)
	{
		push_stack(data, 'a');
		return (1);
	}
	else if (ft_strncmp(move, "pb\n", number) == 0)
	{
		push_stack(data, 'b');
		return (1);
	}
	if (ft_strncmp(move, "ra\n", number) == 0)
	{
		rotate_stack(data, 'a');
		return (1);
	}
	else
		return (make_moves_2(data, move, number));
}

int	make_moves(t_data *data, char *move, int number)
{
	if (ft_strncmp(move, "sa\n", number) == 0)
	{
		swap_stack(data, 'a');
		return (1);
	}
	else if (ft_strncmp(move, "sb\n", number) == 0)
	{
		swap_stack(data, 'b');
		return (1);
	}
	else if (ft_strncmp(move, "ss\n", number) == 0)
	{
		swap_stack(data, '2');
		return (1);
	}
	else
		return (make_moves_1(data, move, number));
}

int	ft_read(char *str)
{
	int		index;
	int		number;
	char	ch;
	
	number = 0;
	index = 0;
	ch = 0;
	while (1)
	{
		index += read(0, &ch, 1);
		str[number++] = ch;
		if (number > 4 || ch == '\n' || index == 0)
		{
			str[number] = 0;
			break;
		}
	}
	return (index);
}

void	check_moves(t_data *data)
{
	int		number;
	char	buffer[6];
	
	number = 0;
	while (1)
	{
		number = ft_read(buffer);
		if (number == 0)
			break ;
		if (!make_moves(data, buffer, number))
			ft_free(data, 0, 1);
	}
	if (!ft_sorted(data) && data->stack_b.data.lenght == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
