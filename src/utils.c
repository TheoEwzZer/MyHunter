/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** utils
*/

#include "my_hunter.h"

int int_to_str(long nbr, int count, char *str)
{
    int rest;
    int quotient;

    if (nbr < 0) {
        str[count] = '-';
        count++;
        count = int_to_str(-nbr, count, str);
    } else {
        rest = nbr % 10;
        quotient = nbr / 10;
        if (quotient != 0) {
            count = int_to_str(quotient, count, str);
        }
        str[count] = rest + 48;
        count++;
    }
    return count;
}

char *put_zero(char *string)
{
    char *string2 = malloc(sizeof(char) * 7);
    int len = my_strlen(string);

    for (int i = 0; i < 7; i++)
        string2[i] = '\0';
    for (int i = 0; i < 6 - len; i++)
        my_strcat(string2, "0");
    my_strcat(string2, string);
    return string2;
}

int check_in_win(var_t *var, sfVector2f position, int number)
{
    return (position.y <= -number || position.x <= -number
    || position.x >= var->size.x + number);
}
