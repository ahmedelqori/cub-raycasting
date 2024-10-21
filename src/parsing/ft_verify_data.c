#include "../../includes/cub.h"

int buffer_counting(char **string)
{
    int i;

    i = 0;
    while (string[i])
        i++;
    return i;
}


int ft_verify_line(char *string, t_parsing *data, t_parsing_helper *helper)
{
    char **buffer;

    buffer = ft_split(string, ' ');
    if (buffer_counting(buffer) != 2)
    {
        free_buffer(buffer, 1);
        return (0);
    }
    if (!ft_verify_textures(buffer, data, helper) && !ft_verify_floor_ceil(buffer, data, helper))
    {
        free_buffer(buffer, 1);
        return (0);
    }
    free_buffer(buffer, 1);
    return (1);
}

int ft_verify_data(char **file, t_parsing *data)
{
    int i;
    t_parsing_helper helper;

    helper.no_found = 0;
    helper.so_found = 0;
    helper.we_found = 0;
    helper.ea_found = 0;
    helper.c_found = 0;
    helper.f_found = 0;
    i = 0;
    if (buffer_counting(file) > 6)
        return (0);
    while (file[i])
    {
        if (!ft_verify_line(file[i], data, &helper))
            return (0);
        i++;
    }
    if (!helper.no_found || helper.no_found > 1 || !helper.ea_found || helper.ea_found > 1)
        return (0);
    if (!helper.we_found || helper.we_found > 1 || !helper.so_found || helper.so_found > 1)
        return (0);
    if (!helper.c_found || helper.c_found > 1 || data->ceil < 0 || !helper.f_found || helper.f_found > 1 || data->floor < 0)
        return (0);
    return (1);
}