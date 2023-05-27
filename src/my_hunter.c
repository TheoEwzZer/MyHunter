/*
** EPITECH PROJECT, 2022
** my_hunter.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

void lose(var_t *var)
{
    if (var->player->score > var->player->highscore)
        var->player->highscore = var->player->score;
    int_to_str(var->player->highscore, 0, var->text->highscore_str);
    save_highscore(var);
    sfRenderWindow_setMouseCursorGrabbed(var->win, 0);
    sfText_setString(var->text->highscore, put_zero(var->text->highscore_str));
    var->player->in_game = 0;
}

void new_level(var_t *var)
{
    int size = var->player->level < 10 ? 25 : 20;

    init_ducks(var);
    var->player->level += 1;
    int_to_str(var->player->level, 0, var->text->level_str);
    sfSound_play(var->music->next);
    sfText_setString(var->text->level, var->text->level_str);
    var->anim->speed += 1;
    var->player->nbr_duck = 0;
    if (var->player->level < 10)
        sfText_setPosition(var->text->level, (sfVector2f){420, 644});
    else
        sfText_setPosition(var->text->level, (sfVector2f){415, 647});
    sfText_setCharacterSize(var->text->level, size);
    sfText_setCharacterSize(var->text->round, 25);
    sfText_setString(var->text->round, var->text->level_str);
    if (var->player->level < 10)
        sfText_setPosition(var->text->round, (sfVector2f){632, 237});
    else
        sfText_setPosition(var->text->round, (sfVector2f){622, 237});
}

void play(var_t *var)
{
    sfVector2f position = {0, var->size.y - 135};
    if (var->player->nbr_duck >= 10)
        new_level(var);
    sfSprite_setTexture(var->sprite->bg, var->texture->bg, 0);
    sfSprite_setTexture(var->sprite->fg, var->texture->fg, 0);
    sfSprite_setTexture(var->sprite->overlay, var->texture->overlay, 0);
    sfRenderWindow_drawSprite(var->win, var->sprite->bg, NULL);
    if (var->bullet->bullet == -1)
        display_game_over(var);
    if (!var->anim->is_dead)
        animation(var);
    else
        die(var);
    sfSprite_setPosition(var->sprite->overlay, position);
    sfRenderWindow_drawSprite(var->win, var->sprite->fg, NULL);
    sfRenderWindow_drawSprite(var->win, var->sprite->overlay, NULL);
    bullet(var);
    little_ducks(var);
    sfRenderWindow_drawText(var->win, var->text->level, NULL);
    sfRenderWindow_drawText(var->win, var->text->score, NULL);
}

void my_hunter(var_t *var, sfEvent event)
{
    srand(mix(clock(), time(NULL)));
    my_srand(var, mix(clock(), time(NULL)));
    while (sfRenderWindow_isOpen(var->win)) {
        if (sfJoystick_isConnected(0)) {
            var->cursor.x += sfJoystick_getAxisPosition(0, sfJoystickX) / 4;
            var->cursor.y += sfJoystick_getAxisPosition(0, sfJoystickY) / 4;
            sfMouse_setPositionRenderWindow(var->cursor, var->win);
        }
        sfRenderWindow_clear(var->win, sfBlack);
        if (var->player->in_game)
            play(var);
        else
            menu(var);
        while (sfRenderWindow_pollEvent(var->win, &event))
            analyse_events(var, event);
        sfSprite_setScale(var->sprite->cursor, (sfVector2f){0.2, 0.2});
        sfRenderWindow_drawSprite(var->win, var->sprite->cursor, NULL);
        sfRenderWindow_display(var->win);
    }
}
