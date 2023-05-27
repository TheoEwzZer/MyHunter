/*
** EPITECH PROJECT, 4022
** event.c
** File description:
** Manage events
*/

#include "my_hunter.h"

void update_ducks(var_t *var)
{
    if (var->player->nbr_duck == 1)
        var->l_ducks->duck1 = 1;
    if (var->player->nbr_duck == 2)
        var->l_ducks->duck2 = 1;
    if (var->player->nbr_duck == 3)
        var->l_ducks->duck3 = 1;
    if (var->player->nbr_duck == 4)
        var->l_ducks->duck4 = 1;
    if (var->player->nbr_duck == 5)
        var->l_ducks->duck5 = 1;
    if (var->player->nbr_duck == 6)
        var->l_ducks->duck6 = 1;
    if (var->player->nbr_duck == 7)
        var->l_ducks->duck7 = 1;
    if (var->player->nbr_duck == 8)
        var->l_ducks->duck8 = 1;
    if (var->player->nbr_duck == 9)
        var->l_ducks->duck9 = 1;
    if (var->player->nbr_duck == 10)
        var->l_ducks->duck10 = 1;
}

void touch(var_t *var)
{
    var->anim->is_dead = 1;
    var->player->score += var->random < 2 ? 1000 : 500;
    var->player->nbr_duck += 1;
    var->bullet->bullet < 3 ? var->bullet->bullet += 1 : 0;
    sfSound_play(var->music->fall);
    update_ducks(var);
}

void mouse_button_pressed(var_t *var, sfEvent event)
{
    sfMouseButtonEvent mouse = event.mouseButton;
    sfVector2f position = sfSprite_getPosition(var->anim->s_duck);

    sfSound_play(var->music->shot);
    if (mouse.y - position.y < 80 && mouse.y - position.y > -80
    && !var->anim->is_dead && mouse.x - position.x < 80
    && mouse.x - position.x > -80) {
        touch(var);
    } else {
        (var->bullet->bullet > 0) ? var->bullet->bullet -= 1 : 0;
    }
}

void analyse_event_pressed2(var_t *var, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed
    || (event.type == sfEvtJoystickButtonPressed
    && sfJoystick_isButtonPressed(0, 0))) {
        if (var->player->in_game) {
            check_pressed(var, event);
            int_to_str(var->player->score, 0, var->text->score_str);
            sfText_setString(var->text->score, put_zero(var->text->score_str));
        } else {
            enter_menu(var);
        }
    }
    if (event.type == sfEvtJoystickButtonPressed) {
        if (sfJoystick_isButtonPressed(0, 1) && var->player->in_game)
            lose(var);
    }
}

void analyse_events(var_t *var, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape && var->player->in_game)
            lose(var);
    }
    if (event.type == sfEvtClosed)
        closed(var);
    if (event.type == sfEvtMouseMoved) {
        sfVector2f position = {event.mouseMove.x - 50, event.mouseMove.y - 50};
        sfSprite_setTexture(var->sprite->cursor, var->texture->cursor, 1);
        sfSprite_setPosition(var->sprite->cursor, position);
    }
    analyse_event_pressed2(var, event);
}
