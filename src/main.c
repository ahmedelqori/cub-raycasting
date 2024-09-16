/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:11:25 by ael-qori          #+#    #+#             */
/*   Updated: 2024/09/09 20:04:05 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int main(void)
{
    t_parsing  *data;

    data = NULL;
    data = ft_paring();
    ft_execute(data);
    ft_free_parsing(data);
    return (1);
}

