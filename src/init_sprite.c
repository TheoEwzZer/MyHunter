/*
** EPITECH PROJECT, 2022
** init_sprite.c
** File description:
** init_sprite
*/

#include "my_hunter.h"

void init_dog(var_t *var)
{
    var->dog->s_dog = sfSprite_create();
    var->dog->s_dog_laugh = sfSprite_create();
    var->dog->t_dog = sfTexture_createFromFile("assets/Dog_duck.png", NULL);
    var->dog->t_dogg = sfTexture_createFromFile("assets/Dog_duckg.png", NULL);
    var->dog->t_dog_laugh = sfTexture_createFromFile("assets/Dog_l.png", NULL);
    var->texture->round = sfTexture_createFromFile("assets/Round.png", NULL);
    var->texture->over = sfTexture_createFromFile("assets/Over.png", NULL);
    var->anim->dieg = sfTexture_createFromFile("assets/Dieg.png", NULL);
    var->anim->fallg = sfTexture_createFromFile("assets/Fallg.png", NULL);
}

void init_sprite2(var_t *var)
{
    sfVector2f new_position;
    if (var->random <= 1)
        new_position = (sfVector2f){my_rand(var), 530};
    if (var->random == 2)
        new_position = (sfVector2f){-110, my_rand2(var)};
    if (var->random == 3)
        new_position = (sfVector2f){var->size.x + 110, my_rand2(var)};
    sfSprite_setPosition(var->anim->s_duck, new_position);
    if (new_position.x > (var->size.x / 2))
        sfSprite_setScale(var->anim->s_duck, (sfVector2f){-1, 1});
    else
        sfSprite_setScale(var->anim->s_duck, (sfVector2f){1, 1});
    var->anim->side = (new_position.x > (var->size.x / 2) ? 1 : 0);
    var->sprite->fly_away = sfSprite_create();
    var->sprite->menu = sfSprite_create();
    var->sprite->round = sfSprite_create();
    var->texture->fly_away = sfTexture_createFromFile("assets/Fly_a.png", NULL);
    var->texture->menu = sfTexture_createFromFile("assets/menu.png", NULL);
    var->texture->menu2 = sfTexture_createFromFile("assets/menu2.png", NULL);
    save_highscore(var);
}

void init_s_bullet(var_t *var)
{
    var->bullet->s_bullet1 = sfSprite_create();
    var->bullet->s_bullet2 = sfSprite_create();
    var->bullet->s_bullet3 = sfSprite_create();
    var->bullet->t_bullet = sfTexture_createFromFile("assets/Bullet.png", NULL);
}

void init_s_little_ducks(var_t *var)
{
    var->l_ducks->s_duck1 = sfSprite_create();
    var->l_ducks->s_duck2 = sfSprite_create();
    var->l_ducks->s_duck3 = sfSprite_create();
    var->l_ducks->s_duck4 = sfSprite_create();
    var->l_ducks->s_duck5 = sfSprite_create();
    var->l_ducks->s_duck6 = sfSprite_create();
    var->l_ducks->s_duck7 = sfSprite_create();
    var->l_ducks->s_duck8 = sfSprite_create();
    var->l_ducks->s_duck9 = sfSprite_create();
    var->l_ducks->s_duck10 = sfSprite_create();
    var->l_ducks->white = sfTexture_createFromFile("assets/White.png", NULL);
    var->l_ducks->red = sfTexture_createFromFile("assets/Red.png", NULL);
}

void init_sprite(var_t *var)
{
    var->anim->s_duck = sfSprite_create();
    float x = sfSprite_getGlobalBounds(var->anim->s_duck).width / 2;
    float y = sfSprite_getGlobalBounds(var->anim->s_duck).height / 2;
    var->sprite->bg = sfSprite_create();
    var->sprite->cursor = sfSprite_create();
    var->sprite->fg = sfSprite_create();
    var->sprite->overlay = sfSprite_create();
    init_dog(var);
    init_s_little_ducks(var);
    init_s_bullet(var);
    var->anim->die = sfTexture_createFromFile("assets/Die.png", NULL);
    var->anim->duck = sfTexture_createFromFile("assets/Fly.png", NULL);
    var->anim->duck_x = sfTexture_createFromFile("assets/Fly_x.png", NULL);
    var->anim->fall = sfTexture_createFromFile("assets/Fall.png", NULL);
    var->texture->bg = sfTexture_createFromFile("assets/Background.png", NULL);
    var->texture->cursor = sfTexture_createFromFile("assets/Cursor.png", NULL);
    var->texture->fg = sfTexture_createFromFile("assets/Foreground.png", NULL);
    var->texture->overlay = sfTexture_createFromFile("assets/Ovrl.png", NULL);
    sfSprite_setOrigin(var->anim->s_duck, (sfVector2f){x, y});
    init_sprite2(var);
}
