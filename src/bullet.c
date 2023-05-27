/*
** EPITECH PROJECT, 2022
** bullet.c
** File description:
** bullet
*/

#include "my_hunter.h"

void bullet(var_t *var)
{
    sfSprite_setTexture(var->bullet->s_bullet1, var->bullet->t_bullet, 0);
    sfSprite_setTexture(var->bullet->s_bullet2, var->bullet->t_bullet, 0);
    sfSprite_setTexture(var->bullet->s_bullet3, var->bullet->t_bullet, 0);
    sfVector2f position_bullet1 = {384, var->size.y - 77};
    sfVector2f position_bullet2 = {404, var->size.y - 77};
    sfVector2f position_bullet3 = {424, var->size.y - 77};
    sfSprite_setPosition(var->bullet->s_bullet1, position_bullet1);
    sfSprite_setPosition(var->bullet->s_bullet2, position_bullet2);
    sfSprite_setPosition(var->bullet->s_bullet3, position_bullet3);
    if (var->bullet->bullet > 0)
        sfRenderWindow_drawSprite(var->win, var->bullet->s_bullet1, NULL);
    if (var->bullet->bullet > 1)
        sfRenderWindow_drawSprite(var->win, var->bullet->s_bullet2, NULL);
    if (var->bullet->bullet > 2)
        sfRenderWindow_drawSprite(var->win, var->bullet->s_bullet3, NULL);
    if (!var->bullet->bullet) {
        var->bullet->bullet = -1;
        sfSound_play(var->music->lose);
    }
}
