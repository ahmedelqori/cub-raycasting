/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relhamma <relhamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:11:25 by ael-qori          #+#    #+#             */
/*   Updated: 2024/09/16 13:54:53 by relhamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_initialize_data(t_parsing *data)
{
	data->east = NULL;
	data->west = NULL;
	data->north = NULL;
	data->south = NULL;
}

int	main(int ac, char **av)
{
	t_parsing	data;

	ft_initialize_data(&data);
	if (ac == 2)
	{
		if (!ft_parsing(av[1], &data))
			return (ft_free_parsing(&data), 1);
		ft_execute(&data);
	}
	else
	{
		ft_putstr_fd("Error\nEnter a valid number of argument\n", 2);
		return (1);
	}
	return (ft_free_parsing(&data), 0);
}
