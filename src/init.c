/*
** EPITECH PROJECT, 2022
** init.c
** File description:
** init
*/

#include "my_hunter.h"

void init_ducks(var_t *var)
{
    var->l_ducks->duck1 = 0;
    var->l_ducks->duck2 = 0;
    var->l_ducks->duck3 = 0;
    var->l_ducks->duck4 = 0;
    var->l_ducks->duck5 = 0;
    var->l_ducks->duck6 = 0;
    var->l_ducks->duck7 = 0;
    var->l_ducks->duck8 = 0;
    var->l_ducks->duck9 = 0;
    var->l_ducks->duck10 = 0;
}

void init_int(var_t *var)
{
    var->anim->is_dead = 0;
    var->anim->is_falling = 0;
    var->anim->side = 0;
    var->anim->speed = 5;
    var->bullet->bullet = 3;
    var->dog->dog_down = 0;
    var->dog->dog_down_laugh = 0;
    var->dog->dog_place = 0;
    var->dog->dog_place_laugh = 0;
    var->in_pause = 0;
    var->menu = 0;
    var->next = 1;
    var->player->in_game = 0;
    var->player->level = 1;
    var->player->nbr_duck = 0;
    var->player->score = 0;
    var->random = rand() % 4;
    init_ducks(var);
}

void init_struct(var_t *var)
{
    var->anim = malloc(sizeof(animation_t));
    var->bullet = malloc(sizeof(bullet_t));
    var->dog = malloc(sizeof(dog_t));
    var->l_ducks = malloc(sizeof(little_ducks_t));
    var->music = malloc(sizeof(music_t));
    var->player = malloc(sizeof(player_t));
    var->sprite = malloc(sizeof(s_t));
    var->text = malloc(sizeof(text_t));
    var->texture = malloc(sizeof(t_t));
    var->rect = malloc(sizeof(rect_t));
}

var_t *init_var(void)
{
    var_t *var = malloc(sizeof(var_t));
    sfVideoMode mode = {1280, 769, 24};
    sfUint32 style = sfDefaultStyle;
    init_struct(var);
    read_highscore(var);
    var->win = sfRenderWindow_create(mode, "My Hunter", style, NULL);
    var->size = sfRenderWindow_getSize(var->win);
    var->anim->clock = sfClock_create();
    var->anim->clock2 = sfClock_create();
    var->anim->clock3 = sfClock_create();
    var->anim->clock4 = sfClock_create();
    var->cursor = (sfVector2i){var->size.x / 2, var->size.y / 2};
    sfRenderWindow_setFramerateLimit(var->win, 60);
    sfRenderWindow_setMouseCursorGrabbed(var->win, 1);
    sfRenderWindow_setMouseCursorVisible(var->win, 0);
    init_int(var);
    init_text(var);
    init_sprite(var);
    init_music(var);
    return var;
}
