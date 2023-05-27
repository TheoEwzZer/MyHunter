/*
** EPITECH PROJECT, 2022
** animation2.c
** File description:
** animation2
*/

#include "my_hunter.h"

void die(var_t *var)
{
    sfTime time = sfClock_getElapsedTime(var->anim->clock);
    float seconds = time.microseconds / 1000000.0;
    sfTexture *texture_d = var->random < 2 ? var->anim->die : var->anim->dieg;
    sfTexture *texture_f = var->random < 2 ? var->anim->fall : var->anim->fallg;
    if (!var->anim->is_falling) {
        sfSprite_setTexture(var->anim->s_duck, texture_d, 1);
        sfRenderWindow_drawSprite(var->win, var->anim->s_duck, NULL);
        var->dog->dog_down = 0;
        var->dog->dog_place = 0;
    }
    display_new_round(var);
    if (seconds > 1) {
        animation_falling(var);
        sfSprite_setTexture(var->anim->s_duck, texture_f, 1);
        sfSprite_setTextureRect(var->anim->s_duck, var->rect->rect2);
        sfRenderWindow_drawSprite(var->win, var->anim->s_duck, NULL);
        var->anim->is_falling = 1;
        falling_duck(var);
        var->bullet->bullet > 0 ? animation_dog(var) : NULL;
    }
}

void animation_falling(var_t *var)
{
    sfTime time = sfClock_getElapsedTime(var->anim->clock2);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.1) {
        if (var->rect->rect2.left == 110)
            var->rect->rect2.left = 0;
        else
            var->rect->rect2.left = 110;
        sfClock_restart(var->anim->clock2);
    }
}

void falling_duck(var_t *var)
{
    sfVector2f position = sfSprite_getPosition(var->anim->s_duck);
    sfVector2f new_position;
    if (position.y - (var->size.y * 2) >= var->size.y) {
        new_position = handle_side(var);
        sfSprite_setTextureRect(var->anim->s_duck, var->rect->rect2);
        var->anim->is_dead = 0;
        var->anim->is_falling = 0;
        sfSprite_setPosition(var->anim->s_duck, new_position);
        if (new_position.x > (var->size.x / 2))
            sfSprite_setScale(var->anim->s_duck, (sfVector2f){-1, 1});
        else
            sfSprite_setScale(var->anim->s_duck, (sfVector2f){1, 1});
        var->anim->side = (new_position.x > (var->size.x / 2) ? 1 : 0);
        sfClock_restart(var->anim->clock);
        sfRenderWindow_drawSprite(var->win, var->anim->s_duck, NULL);
        if (var->bullet->bullet == -1)
            lose(var);
    } else {
        sfSprite_move(var->anim->s_duck, (sfVector2f){0, 10});
    }
}

void animation_dog(var_t *var)
{
    sfVector2f duck_position = sfSprite_getPosition(var->anim->s_duck);
    sfVector2f dog_position = sfSprite_getPosition(var->dog->s_dog);
    sfVector2f new_dog_position = {duck_position.x, var->size.y - 100};
    sfTexture *texture = var->random < 2 ? var->dog->t_dog : var->dog->t_dogg;

    if (!var->dog->dog_place) {
        if (var->player->nbr_duck != 0)
            sfSound_play(var->music->dog_up);
        sfSprite_setPosition(var->dog->s_dog, new_dog_position);
        var->dog->dog_place = 1;
    } else {
        if (dog_position.y > var->size.y - 300 && !var->dog->dog_down) {
            sfSprite_move(var->dog->s_dog, (sfVector2f){0, -2});
        } else {
            var->dog->dog_down = 1;
            sfSprite_move(var->dog->s_dog, (sfVector2f){0, 2});
        }
    }
    sfSprite_setTexture(var->dog->s_dog, texture, 1);
    sfRenderWindow_drawSprite(var->win, var->dog->s_dog, NULL);
}

void animation_dog_laugh(var_t *var)
{
    sfTime time = sfClock_getElapsedTime(var->anim->clock4);
    float seconds = time.microseconds / 1000000.0;
    sfVector2f position = {var->size.x / 2 - 82, var->size.y / 4};

    if (seconds > 0.2) {
        if (var->rect->rect3.left == 64)
            var->rect->rect3.left -= 64;
        else
            var->rect->rect3.left += 64;
        sfClock_restart(var->anim->clock4);
    }
    animation_dog_laugh_move(var);
    sfSprite_setTextureRect(var->dog->s_dog_laugh, var->rect->rect3);
    sfSprite_setTexture(var->dog->s_dog_laugh, var->dog->t_dog_laugh, 0);
    sfRenderWindow_drawSprite(var->win, var->dog->s_dog_laugh, NULL);
    if (var->bullet->bullet > 0) {
        sfSprite_setTexture(var->sprite->fly_away, var->texture->fly_away, 0);
        sfSprite_setPosition(var->sprite->fly_away, position);
        sfRenderWindow_drawSprite(var->win, var->sprite->fly_away, NULL);
    }
}
