/*
** EPITECH PROJECT, 2022
** rand.c
** File description:
** rand
*/

#include "my_hunter.h"

int my_rand(var_t *var)
{
    var->next = var->next * 1103515245 + 12345;
    return ((unsigned int)(var->next / 65536) % (var->size.x - 301));
}

int my_rand2(var_t *var)
{
    var->next = var->next * 1103515245 + 12345;
    return ((unsigned int)(var->next / 65536) % (var->size.y - 300));
}

void my_srand(var_t *var, unsigned long seed)
{
    var->next = seed;
}

unsigned int mix(unsigned long a, unsigned long b)
{
    a = a - b;
    b = b - a;
    b = b ^ (a << 8);
    a = a - b;
    b = b - a;
    b = b ^ (a << 16);
    a = a - b;
    b = b - a;
    b = b ^ (a << 10);
    return b;
}
