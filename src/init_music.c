/*
** EPITECH PROJECT, 2022
** init_music.c
** File description:
** init_music
*/

#include "my_hunter.h"

void init_music2(var_t *var)
{
    var->music->lose = sfSound_create();
    var->music->lose_buf = sfSoundBuffer_createFromFile("assets/Gameover.wav");
    sfSound_setBuffer(var->music->lose, var->music->lose_buf);
    var->music->dog_up = sfSound_create();
    var->music->dog_up_buf = sfSoundBuffer_createFromFile("assets/Dog_up.wav");
    sfSound_setBuffer(var->music->dog_up, var->music->dog_up_buf);
    var->music->dog_laugh = sfSound_create();
    var->music->dog_laugh_buf = sfSoundBuffer_createFromFile("assets/Dogl.wav");
    sfSound_setBuffer(var->music->dog_laugh, var->music->dog_laugh_buf);
}

void init_music(var_t *var)
{
    var->music->bg = sfSound_create();
    var->music->bg_buf = sfSoundBuffer_createFromFile("assets/Bgmusic.wav");
    sfSound_setBuffer(var->music->bg, var->music->bg_buf);
    sfSound_setLoop(var->music->bg, 1);
    var->music->shot = sfSound_create();
    var->music->shot_buf = sfSoundBuffer_createFromFile("assets/Gunshot.wav");
    sfSound_setBuffer(var->music->shot, var->music->shot_buf);
    var->music->fall = sfSound_create();
    var->music->fall_buf = sfSoundBuffer_createFromFile("assets/Fall.wav");
    sfSound_setBuffer(var->music->fall, var->music->fall_buf);
    var->music->next = sfSound_create();
    var->music->next_buf = sfSoundBuffer_createFromFile("assets/Next.wav");
    sfSound_setBuffer(var->music->next, var->music->next_buf);
    var->music->start = sfSound_create();
    var->music->start_buf = sfSoundBuffer_createFromFile("assets/Start.wav");
    sfSound_setBuffer(var->music->start, var->music->start_buf);
    sfSound_play(var->music->bg);
    sfSound_play(var->music->start);
    init_music2(var);
}
