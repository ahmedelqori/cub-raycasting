/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:28:34 by ael-qori          #+#    #+#             */
/*   Updated: 2024/09/08 15:56:18 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

t_parsing *ft_paring(void)
{
    t_parsing *data;

    data = malloc(sizeof(t_parsing));
    data->north = ft_strdup("images/N.xpm");
    data->east = ft_strdup("images/E.xpm");
    data->west = ft_strdup("images/W.xpm");
    data->south = ft_strdup("images/S.xpm");

    data->floor = (255 << 24) | (210 << 16) | (180 << 8) | 140;
    data->ceil = (255 << 24) | (135 << 16) | (206 << 8) | 235;
    //
    data->map = malloc(sizeof(char *) * 18);
    data->map[0] = ft_strdup("        11111111111111          11111111111111111111111");
    data->map[1] = ft_strdup("        10000000000001          10000001000000000000001");
    data->map[2] = ft_strdup("        10000000000001111111111111110000000000000000001");
    data->map[3] = ft_strdup("        10000000000000000010000000000000000000000000001");
    data->map[4] = ft_strdup("        10000000000000000010000000000000000000000000001");
    data->map[5] = ft_strdup("        10000000000000000010000000000000000000000000001");
    data->map[6] = ft_strdup("        10000000000000000010000000000000000000000000001");
    data->map[7] = ft_strdup("        10000000000000000010000000000000000000000000001");
    data->map[8] = ft_strdup("        11111111001111111110000000000000000000000000001");
    data->map[9] = ft_strdup("        10000000000000000010000000000000000000000000001");
    data->map[10] = ft_strdup("1111111110000000000000000010000000000000000000000000001");
    data->map[11] = ft_strdup("1000000010000000000000000010000000000000000000000000001");
    data->map[12] = ft_strdup("1000N00010000000000000000010000000000000000000000000001");
    data->map[13] = ft_strdup("1000000010000000000000000010000000000000000000000000001");
    data->map[14] = ft_strdup("1000100010000000000000000000000000000000000000000000001");
    data->map[15] = ft_strdup("1000000000000000000000000000000000000000000000000000001");
    data->map[16] = ft_strdup("1111111111111111111111111111111111111111111111111111111");
    data->map[17] = NULL;

    data->map_x = 4;
    data->map_y = 12;
    //
    // data->map = malloc(sizeof(char *) * 6);
    // data->map[0] = ft_strdup("111111");
    // data->map[1] = ft_strdup("100001");
    // data->map[2] = ft_strdup("100001");
    // data->map[3] = ft_strdup("10N001");
    // data->map[4] = ft_strdup("111111");
    // data->map[5] = NULL;
    //
    // data->map_x = 2;
    // data->map_y = 3;

    // data->map = malloc(sizeof(char *) * 10);  // Adjust the number of rows
    // data->map[0] = ft_strdup("1111111111");
    // data->map[1] = ft_strdup("1000100001");
    // data->map[2] = ft_strdup("1000100001");
    // data->map[3] = ft_strdup("1000100001");
    // data->map[4] = ft_strdup("1000100001");
    // data->map[5] = ft_strdup("1000100N01");
    // data->map[6] = ft_strdup("1000100001");
    // data->map[7] = ft_strdup("1000000001");
    // data->map[8] = ft_strdup("1111111111");
    // data->map[9] = NULL;  // Null-terminate the map
    //
    // // Update map dimensions
    // data->map_x = 5;  // Player's initial x-coordinate
    // data->map_y = 5;  // Player's initial y-coordinate
    data->direction = 'N';
    return data;
}

void ft_free_parsing(t_parsing *data)
{
    int i;

    i = 0;
    free(data->north);
    free(data->south);
    free(data->east);
    free(data->west);
    while (data->map[i])
        free(data->map[i++]);
    free(data->map);
    free(data);
}