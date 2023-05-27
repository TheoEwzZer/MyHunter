/*
** EPITECH PROJECT, 4022
** event2.c
** File description:
** Manage events
*/

#include "my_hunter.h"

void joystick_button_pressed(var_t *var)
{
    sfVector2f position = sfSprite_getPosition(var->anim->s_duck);

    sfSound_play(var->music->shot);
    if (var->cursor.y- position.y < 80 && var->cursor.y- position.y > -80
    && !var->anim->is_dead && var->cursor.x- position.x < 80) {
        if (var->cursor.x- position.x > -80)
            touch(var);
    } else {
        (var->bullet->bullet > 0) ? var->bullet->bullet -= 1 : 0;
    }
}

void check_pressed(var_t *var, sfEvent event)
{
    if (var->bullet->bullet > 0) {
        if (sfJoystick_isConnected(0))
            joystick_button_pressed(var);
        else
            mouse_button_pressed(var, event);
    }
}

void closed(var_t *var)
{
    lose(var);
    sfRenderWindow_close(var->win);
}
