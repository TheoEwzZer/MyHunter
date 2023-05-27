/*
** EPITECH PROJECT, 2022
** animation3.c
** File description:
** animation3
*/

#include "my_hunter.h"

void animation_dog_laugh_move(var_t *var)
{
    sfVector2f dog_position = sfSprite_getPosition(var->dog->s_dog_laugh);
    sfVector2f new_dog_position = {var->size.x / 2 - 32, var->size.y - 200};

    if (!var->dog->dog_place_laugh) {
        sfSprite_setPosition(var->dog->s_dog_laugh, new_dog_position);
        var->dog->dog_place_laugh = 1;
    } else {
        if (dog_position.y > var->size.y - 300 && !var->dog->dog_down_laugh)
            sfSprite_move(var->dog->s_dog_laugh, (sfVector2f){0, -2});
        else {
            var->dog->dog_down_laugh = 1;
            sfSprite_move(var->dog->s_dog_laugh, (sfVector2f){0, 2});
        }
        if (dog_position.y == var->size.y - 226 && !var->dog->dog_down_laugh) {
            sfSound_play(var->music->dog_laugh);
        }
    }
}

void display_new_round(var_t *var)
{
    if (!var->player->nbr_duck) {
        sfVector2f position = {var->size.x / 2 - 55, var->size.y / 4};
        sfSprite_setPosition(var->sprite->round, position);
        sfSprite_setTexture(var->sprite->round, var->texture->round, 1);
        sfRenderWindow_drawSprite(var->win, var->sprite->round, NULL);
        sfRenderWindow_drawText(var->win, var->text->round, NULL);
    }
}

void display_game_over(var_t *var)
{
    sfVector2f position = {var->size.x / 2 - 55, var->size.y / 4};
    sfSprite_setPosition(var->sprite->round, position);
    sfSprite_setTexture(var->sprite->round, var->texture->over, 1);
    sfRenderWindow_drawSprite(var->win, var->sprite->round, NULL);
    animation_dog_laugh(var);
}
