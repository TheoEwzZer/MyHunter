/*
** EPITECH PROJECT, 2022
** destroy2.c
** File description:
** destroy2
*/

#include "my_hunter.h"

void destroy_music(var_t *var)
{
    sfSoundBuffer_destroy(var->music->bg_buf);
    sfSoundBuffer_destroy(var->music->dog_laugh_buf);
    sfSoundBuffer_destroy(var->music->dog_up_buf);
    sfSoundBuffer_destroy(var->music->fall_buf);
    sfSoundBuffer_destroy(var->music->lose_buf);
    sfSoundBuffer_destroy(var->music->next_buf);
    sfSoundBuffer_destroy(var->music->shot_buf);
    sfSoundBuffer_destroy(var->music->start_buf);
    sfSound_destroy(var->music->bg);
    sfSound_destroy(var->music->dog_laugh);
    sfSound_destroy(var->music->dog_up);
    sfSound_destroy(var->music->fall);
    sfSound_destroy(var->music->lose);
    sfSound_destroy(var->music->next);
    sfSound_destroy(var->music->shot);
    sfSound_destroy(var->music->start);
    free(var->music);
}

void destroy_sprite(var_t *var)
{
    sfSprite_destroy(var->sprite->bg);
    sfSprite_destroy(var->sprite->cursor);
    sfSprite_destroy(var->sprite->fg);
    sfSprite_destroy(var->sprite->fly_away);
    sfSprite_destroy(var->sprite->menu);
    sfSprite_destroy(var->sprite->overlay);
    sfSprite_destroy(var->sprite->round);
    free(var->sprite);
}

void destroy_texture(var_t *var)
{
    sfTexture_destroy(var->texture->bg);
    sfTexture_destroy(var->texture->cursor);
    sfTexture_destroy(var->texture->fg);
    sfTexture_destroy(var->texture->fly_away);
    sfTexture_destroy(var->texture->menu);
    sfTexture_destroy(var->texture->menu2);
    sfTexture_destroy(var->texture->over);
    sfTexture_destroy(var->texture->overlay);
    sfTexture_destroy(var->texture->round);
    free(var->texture);
}

void destroy_text(var_t *var)
{
    free(var->text->highscore_str);
    free(var->text->level_str);
    free(var->text->score_str);
    sfFont_destroy(var->text->font);
    sfText_destroy(var->text->highscore);
    sfText_destroy(var->text->level);
    sfText_destroy(var->text->round);
    sfText_destroy(var->text->score);
    free(var->text);
}
