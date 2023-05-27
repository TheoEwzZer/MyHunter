/*
** EPITECH PROJECT, 2022
** menu.c
** File description:
** menu
*/

#include "my_hunter.h"

void menu(var_t *var)
{
    sfSound_stop(var->music->bg);
    sfTime time = sfClock_getElapsedTime(var->anim->clock);
    float seconds = time.microseconds / 1000000.0;
    if (seconds > 0.7) {
        var->menu = var->menu ? 0 : 1;
        sfClock_restart(var->anim->clock);
    }
    if (var->menu)
        sfSprite_setTexture(var->sprite->menu, var->texture->menu, 0);
    else
        sfSprite_setTexture(var->sprite->menu, var->texture->menu2, 0);
    sfRenderWindow_drawSprite(var->win, var->sprite->menu, NULL);
    sfRenderWindow_drawText(var->win, var->text->highscore, NULL);
}

void enter_menu(var_t *var)
{
    mouse_button_pressed_menu(var);
    int_to_str(var->player->score, 0, var->text->score_str);
    sfText_setString(var->text->score, put_zero(var->text->score_str));
}

void mouse_button_pressed_menu(var_t *var)
{
    init_int(var);
    init_text(var);
    init_sprite(var);
    var->player->in_game = 1;
    sfSound_stop(var->music->start);
}
