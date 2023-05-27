/*
** EPITECH PROJECT, 2022
** little_ducks.c
** File description:
** little_ducks
*/

#include "my_hunter.h"

void little_ducks_texture2(var_t *var)
{
    if (var->l_ducks->duck6)
        sfSprite_setTexture(var->l_ducks->s_duck6, var->l_ducks->red, 0);
    else
        sfSprite_setTexture(var->l_ducks->s_duck6, var->l_ducks->white, 0);
    if (var->l_ducks->duck7)
        sfSprite_setTexture(var->l_ducks->s_duck7, var->l_ducks->red, 0);
    else
        sfSprite_setTexture(var->l_ducks->s_duck7, var->l_ducks->white, 0);
    if (var->l_ducks->duck8)
        sfSprite_setTexture(var->l_ducks->s_duck8, var->l_ducks->red, 0);
    else
        sfSprite_setTexture(var->l_ducks->s_duck8, var->l_ducks->white, 0);
    if (var->l_ducks->duck9)
        sfSprite_setTexture(var->l_ducks->s_duck9, var->l_ducks->red, 0);
    else
        sfSprite_setTexture(var->l_ducks->s_duck9, var->l_ducks->white, 0);
    if (var->l_ducks->duck10)
        sfSprite_setTexture(var->l_ducks->s_duck10, var->l_ducks->red, 0);
    else
        sfSprite_setTexture(var->l_ducks->s_duck10, var->l_ducks->white, 0);
}

void little_ducks_texture1(var_t *var)
{
    if (var->l_ducks->duck1)
        sfSprite_setTexture(var->l_ducks->s_duck1, var->l_ducks->red, 0);
    else
        sfSprite_setTexture(var->l_ducks->s_duck1, var->l_ducks->white, 0);
    if (var->l_ducks->duck2)
        sfSprite_setTexture(var->l_ducks->s_duck2, var->l_ducks->red, 0);
    else
        sfSprite_setTexture(var->l_ducks->s_duck2, var->l_ducks->white, 0);
    if (var->l_ducks->duck3)
        sfSprite_setTexture(var->l_ducks->s_duck3, var->l_ducks->red, 0);
    else
        sfSprite_setTexture(var->l_ducks->s_duck3, var->l_ducks->white, 0);
    if (var->l_ducks->duck4)
        sfSprite_setTexture(var->l_ducks->s_duck4, var->l_ducks->red, 0);
    else
        sfSprite_setTexture(var->l_ducks->s_duck4, var->l_ducks->white, 0);
    if (var->l_ducks->duck5)
        sfSprite_setTexture(var->l_ducks->s_duck5, var->l_ducks->red, 0);
    else
        sfSprite_setTexture(var->l_ducks->s_duck5, var->l_ducks->white, 0);
}

void little_ducks_position(var_t *var)
{
    sfVector2f position_duck1 = {555, var->size.y - 77};
    sfVector2f position_duck2 = {575, var->size.y - 77};
    sfVector2f position_duck3 = {595, var->size.y - 77};
    sfVector2f position_duck4 = {615, var->size.y - 77};
    sfVector2f position_duck5 = {635, var->size.y - 77};
    sfVector2f position_duck6 = {655, var->size.y - 77};
    sfVector2f position_duck7 = {675, var->size.y - 77};
    sfVector2f position_duck8 = {695, var->size.y - 77};
    sfVector2f position_duck9 = {715, var->size.y - 77};
    sfVector2f position_duck10 = {735, var->size.y - 77};
    sfSprite_setPosition(var->l_ducks->s_duck1, position_duck1);
    sfSprite_setPosition(var->l_ducks->s_duck2, position_duck2);
    sfSprite_setPosition(var->l_ducks->s_duck3, position_duck3);
    sfSprite_setPosition(var->l_ducks->s_duck4, position_duck4);
    sfSprite_setPosition(var->l_ducks->s_duck5, position_duck5);
    sfSprite_setPosition(var->l_ducks->s_duck6, position_duck6);
    sfSprite_setPosition(var->l_ducks->s_duck7, position_duck7);
    sfSprite_setPosition(var->l_ducks->s_duck8, position_duck8);
    sfSprite_setPosition(var->l_ducks->s_duck9, position_duck9);
    sfSprite_setPosition(var->l_ducks->s_duck10, position_duck10);
}

void little_ducks(var_t *var)
{
    little_ducks_position(var);
    little_ducks_texture1(var);
    little_ducks_texture2(var);
    sfRenderWindow_drawSprite(var->win, var->l_ducks->s_duck1, NULL);
    sfRenderWindow_drawSprite(var->win, var->l_ducks->s_duck2, NULL);
    sfRenderWindow_drawSprite(var->win, var->l_ducks->s_duck3, NULL);
    sfRenderWindow_drawSprite(var->win, var->l_ducks->s_duck4, NULL);
    sfRenderWindow_drawSprite(var->win, var->l_ducks->s_duck5, NULL);
    sfRenderWindow_drawSprite(var->win, var->l_ducks->s_duck6, NULL);
    sfRenderWindow_drawSprite(var->win, var->l_ducks->s_duck7, NULL);
    sfRenderWindow_drawSprite(var->win, var->l_ducks->s_duck8, NULL);
    sfRenderWindow_drawSprite(var->win, var->l_ducks->s_duck9, NULL);
    sfRenderWindow_drawSprite(var->win, var->l_ducks->s_duck10, NULL);
}
