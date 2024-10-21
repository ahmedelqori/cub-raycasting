#include "../../includes/cub.h"

int ft_strcmp_1(char *s1, char *s2)
{
    if (!*s1 && !*s2)
        return (1);
    else if (*s1 != *s2)
        return (0);
    else
        return (ft_strcmp_1(s1 + 1, s2 + 1));
}