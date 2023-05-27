/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** destroy
*/

#include "my_hunter.h"

void destroy_animation(var_t *var)
{
    sfClock_destroy(var->anim->clock);
    sfClock_destroy(var->anim->clock2);
    sfClock_destroy(var->anim->clock3);
    sfClock_destroy(var->anim->clock4);
    sfSprite_destroy(var->anim->s_duck);
    sfTexture_destroy(var->anim->die);
    sfTexture_destroy(var->anim->dieg);
    sfTexture_destroy(var->anim->duck);
    sfTexture_destroy(var->anim->duck_x);
    sfTexture_destroy(var->anim->fall);
    sfTexture_destroy(var->anim->fallg);
    free(var->anim);
}

void destroy_bullet(var_t *var)
{
    sfSprite_destroy(var->bullet->s_bullet1);
    sfSprite_destroy(var->bullet->s_bullet2);
    sfSprite_destroy(var->bullet->s_bullet3);
    sfTexture_destroy(var->bullet->t_bullet);
    free(var->bullet);
}

void destroy_dog(var_t *var)
{
    sfSprite_destroy(var->dog->s_dog);
    sfSprite_destroy(var->dog->s_dog_laugh);
    sfTexture_destroy(var->dog->t_dog);
    sfTexture_destroy(var->dog->t_dog_laugh);
    sfTexture_destroy(var->dog->t_dogg);
    free(var->dog);
}

void destroy_l_ducks(var_t *var)
{
    sfSprite_destroy(var->l_ducks->s_duck1);
    sfSprite_destroy(var->l_ducks->s_duck2);
    sfSprite_destroy(var->l_ducks->s_duck3);
    sfSprite_destroy(var->l_ducks->s_duck4);
    sfSprite_destroy(var->l_ducks->s_duck5);
    sfSprite_destroy(var->l_ducks->s_duck6);
    sfSprite_destroy(var->l_ducks->s_duck7);
    sfSprite_destroy(var->l_ducks->s_duck8);
    sfSprite_destroy(var->l_ducks->s_duck9);
    sfSprite_destroy(var->l_ducks->s_duck10);
    sfTexture_destroy(var->l_ducks->red);
    sfTexture_destroy(var->l_ducks->white);
    free(var->l_ducks);
}

void destroy(var_t *var)
{
    destroy_animation(var);
    destroy_bullet(var);
    destroy_dog(var);
    destroy_l_ducks(var);
    destroy_music(var);
    destroy_sprite(var);
    destroy_text(var);
    destroy_texture(var);
    sfRenderWindow_destroy(var->win);
    free(var);
}
