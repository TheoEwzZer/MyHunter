/*
** EPITECH PROJECT, 2022
** animation.c
** File description:
** Manage animations
*/

#include "my_hunter.h"

void move_duck_in_window(var_t *var)
{
    sfVector2f offset0;
    sfVector2f offset1;

    if (var->random <= 1) {
        sfSprite_setTexture(var->anim->s_duck, var->anim->duck, 0);
        offset0 = (sfVector2f){var->anim->speed, -var->anim->speed};
        offset1 = (sfVector2f){-var->anim->speed, -var->anim->speed};
    } else {
        sfSprite_setTexture(var->anim->s_duck, var->anim->duck_x, 0);
        offset0 = (sfVector2f){var->anim->speed, 0};
        offset1 = (sfVector2f){-var->anim->speed, 0};
    }
    if (var->anim->side)
        sfSprite_move(var->anim->s_duck, offset1);
    else
        sfSprite_move(var->anim->s_duck, offset0);
}

void launch_animation_dog_laugh(var_t *var, sfVector2f position)
{
    if (check_in_win(var, position, 331) && var->bullet->bullet > 0)
        animation_dog_laugh(var);
}

sfVector2f handle_side(var_t *var)
{
    sfVector2f new_position;

    var->random = rand() % 4;
    if (var->random <= 1)
        new_position = (sfVector2f){my_rand(var), 530};
    if (var->random == 2)
        new_position = (sfVector2f){-110, my_rand2(var)};
    if (var->random == 3)
        new_position = (sfVector2f){var->size.x + 110, my_rand2(var)};
    return new_position;
}

void move_duck(var_t *var)
{
    sfVector2f position = sfSprite_getPosition(var->anim->s_duck);
    sfVector2f new_position;
    if (check_in_win(var, position, 1000)) {
        new_position = handle_side(var);
        if (new_position.x > (var->size.x / 2))
            sfSprite_setScale(var->anim->s_duck, (sfVector2f){-1, 1});
        else
            sfSprite_setScale(var->anim->s_duck, (sfVector2f){1, 1});
        var->anim->side = (new_position.x > (var->size.x / 2) ? 1 : 0);
        (var->bullet->bullet > 0) ? var->bullet->bullet -= 1 : 0;
        var->player->nbr_duck += 1;
        sfSprite_setPosition(var->anim->s_duck, new_position);
        sfSound_stop(var->music->fall);
        var->dog->dog_down_laugh = 0;
        var->dog->dog_place_laugh = 0;
        if (var->bullet->bullet == -1)
            lose(var);
    } else
        move_duck_in_window(var);
    launch_animation_dog_laugh(var, position);
}

void animation(var_t *var)
{
    sfTime time = sfClock_getElapsedTime(var->anim->clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > (2.0 / var->anim->speed)) {
        if (var->rect->rect1.left == 220)
            var->rect->rect1.left -= 220;
        else
            var->rect->rect1.left += 110;
        sfClock_restart(var->anim->clock);
    }
    move_duck(var);
    sfSprite_setTextureRect(var->anim->s_duck, var->rect->rect1);
    sfRenderWindow_drawSprite(var->win, var->anim->s_duck, NULL);
}
