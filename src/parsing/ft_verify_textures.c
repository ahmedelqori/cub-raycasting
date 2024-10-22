/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relhamma <relhamma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:01:48 by relhamma          #+#    #+#             */
/*   Updated: 2024/10/21 15:03:03 by relhamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	verify_west(char **buffer, t_parsing *data, t_parsing_helper *helper)
{
	char **temp;
	char *temp_2;

	temp_2 = NULL;
	if (!ft_strcmp_1("WE", *buffer))
		return (0);
	temp = buffer + 1;
	while (*temp)
		temp_2 = ft_strjoin(*temp, *(temp + 1));
	if (!helper->we_found)
		data->west = ft_strdup(temp_2);
	free(temp_2);
	helper->we_found++;
	return (1);
}

int	verify_east(char **buffer, t_parsing *data, t_parsing_helper *helper)
{
	char **temp;
	char *temp_2;

	temp_2 = NULL;
	if (!ft_strcmp_1("EA", *buffer))
		return (0);
	temp = buffer + 1;
	while (*temp)
		temp_2 = ft_strjoin(*temp, *(temp + 1));
	if (!helper->ea_found)
		data->east = ft_strdup(temp_2);
	free(temp_2);
	helper->ea_found++;
	return (1);
}

int	verify_south(char **buffer, t_parsing *data, t_parsing_helper *helper)
{
	char **temp;
	char *temp_2;

	temp_2 = NULL;
	if (!ft_strcmp_1("SO", *buffer))
		return (0);
	temp = buffer + 1;
	while (*temp)
		temp_2 = ft_strjoin(*temp, *(temp + 1));
	if (!helper->so_found)
		data->south = ft_strdup(temp_2);
	free(temp_2);
	helper->so_found++;
	return (1);
}

int	verify_north(char **buffer, t_parsing *data, t_parsing_helper *helper)
{
	char **temp;
	char *temp_2;

	temp_2 = NULL;
	if (!ft_strcmp_1("NO", *buffer))
		return (0);
	temp = buffer + 1;
	while (*temp)
		temp_2 = ft_strjoin(*temp, *(temp + 1));
	if (!helper->no_found)
		data->north = ft_strdup(temp_2);
	free(temp_2);
	helper->no_found++;
	return (1);
}

int	ft_verify_textures(char **buffer, t_parsing *data, t_parsing_helper *helper)
{
	if (!verify_east(buffer, data, helper) && !verify_west(buffer, data, helper)
		&& !verify_north(buffer, data, helper) && !verify_south(buffer, data,
			helper))
		return (0);
	return (1);
}
