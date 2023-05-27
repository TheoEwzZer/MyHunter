/*
** EPITECH PROJECT, 2022
** my_hunter.h
** File description:
** my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my.h"

#ifndef MY_HUNTER_H_

    #define MY_HUNTER_H_

typedef struct anim {
    int is_dead;
    int is_falling;
    int side;
    int speed;
    sfClock *clock;
    sfClock *clock2;
    sfClock *clock3;
    sfClock *clock4;
    sfSprite *s_duck;
    sfTexture *die;
    sfTexture *dieg;
    sfTexture *duck;
    sfTexture *duck_x;
    sfTexture *fall;
    sfTexture *fallg;
} animation_t;

typedef struct bullet {
    int bullet;
    sfSprite *s_bullet1;
    sfSprite *s_bullet2;
    sfSprite *s_bullet3;
    sfTexture *t_bullet;
} bullet_t;

typedef struct dog {
    int dog_down;
    int dog_down_laugh;
    int dog_place;
    int dog_place_laugh;
    sfSprite *s_dog;
    sfSprite *s_dog_laugh;
    sfTexture *t_dog;
    sfTexture *t_dog_laugh;
    sfTexture *t_dogg;
} dog_t;

typedef struct l_ducks {
    int duck1;
    int duck2;
    int duck3;
    int duck4;
    int duck5;
    int duck6;
    int duck7;
    int duck8;
    int duck9;
    int duck10;
    sfSprite *s_duck1;
    sfSprite *s_duck2;
    sfSprite *s_duck3;
    sfSprite *s_duck4;
    sfSprite *s_duck5;
    sfSprite *s_duck6;
    sfSprite *s_duck7;
    sfSprite *s_duck8;
    sfSprite *s_duck9;
    sfSprite *s_duck10;
    sfTexture *red;
    sfTexture *white;
} little_ducks_t;

typedef struct music {
    sfSound *bg;
    sfSound *dog_laugh;
    sfSound *dog_up;
    sfSound *fall;
    sfSound *lose;
    sfSound *next;
    sfSound *shot;
    sfSound *start;
    sfSoundBuffer *bg_buf;
    sfSoundBuffer *dog_laugh_buf;
    sfSoundBuffer *dog_up_buf;
    sfSoundBuffer *fall_buf;
    sfSoundBuffer *lose_buf;
    sfSoundBuffer *next_buf;
    sfSoundBuffer *shot_buf;
    sfSoundBuffer *start_buf;
} music_t;

typedef struct player {
    int highscore;
    int in_game;
    int level;
    int nbr_duck;
    int score;
} player_t;

typedef struct rect {
    sfIntRect rect1;
    sfIntRect rect2;
    sfIntRect rect3;
} rect_t;

typedef struct sprite {
    sfSprite *bg;
    sfSprite *cursor;
    sfSprite *fg;
    sfSprite *fly_away;
    sfSprite *menu;
    sfSprite *overlay;
    sfSprite *round;
} s_t;

typedef struct texture {
    sfTexture *bg;
    sfTexture *cursor;
    sfTexture *fg;
    sfTexture *fly_away;
    sfTexture *menu2;
    sfTexture *menu;
    sfTexture *over;
    sfTexture *overlay;
    sfTexture *round;
} t_t;

typedef struct text {
    char *highscore_str;
    char *level_str;
    char *score_str;
    sfColor green;
    sfFont *font;
    sfText *highscore;
    sfText *level;
    sfText *round;
    sfText *score;
} text_t;

typedef struct structure {
    animation_t *anim;
    bullet_t *bullet;
    dog_t *dog;
    int in_pause;
    int random;
    int menu;
    little_ducks_t *l_ducks;
    music_t *music;
    player_t *player;
    rect_t *rect;
    s_t *sprite;
    sfRenderWindow *win;
    sfVector2i cursor;
    sfVector2u size;
    t_t *texture;
    text_t *text;
    unsigned long next;
} var_t;

char *my_strcat(char *dest, const char *src);
char *put_zero(char *string);
int check_in_win(var_t *var, sfVector2f position, int number);
int int_to_str(long nbr, int count, char *str);
int my_rand(var_t *var);
int my_rand2(var_t *var);
int my_strlen(char const *str);
sfVector2f handle_side(var_t *var);
unsigned int mix(unsigned long a, unsigned long b);
var_t *init_var(void);
void analyse_events(var_t *var, sfEvent event);
void animation(var_t *var);
void animation_dog(var_t *var);
void animation_dog_laugh(var_t *var);
void animation_dog_laugh_move(var_t *var);
void animation_falling(var_t *var);
void bullet(var_t *var);
void check_pressed(var_t *var, sfEvent event);
void closed(var_t *var);
void destroy(var_t *var);
void destroy_music(var_t *var);
void destroy_sprite(var_t *var);
void destroy_text(var_t *var);
void destroy_texture(var_t *var);
void die(var_t *var);
void display_game_over(var_t *var);
void display_new_round(var_t *var);
void enter_menu(var_t *var);
void falling_duck(var_t *var);
void init_ducks(var_t *var);
void init_int(var_t *var);
void init_music(var_t *var);
void init_sprite(var_t *var);
void init_text(var_t *var);
void joystick_button_pressed(var_t *var);
void little_ducks(var_t *var);
void lose(var_t *var);
void menu(var_t *var);
void mouse_button_pressed(var_t *var, sfEvent event);
void mouse_button_pressed_menu(var_t *var);
void my_hunter(var_t *var, sfEvent event);
void my_srand(var_t *var, unsigned long seed);
void read_highscore(var_t *var);
void save_highscore(var_t *var);
void touch(var_t *var);

#endif /* MY_HUNTER_H_ */
