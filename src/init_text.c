/*
** EPITECH PROJECT, 2022
** init_text.c
** File description:
** init_text
*/

#include "my_hunter.h"

void init_text_highscore(var_t *var)
{
    sfVector2f position = {var->size.x - 520, var->size.y - 150};

    var->text->highscore = sfText_create();
    var->text->highscore_str = malloc(sizeof(char) * 7);
    for (int i = 0; i <= 7; i++) {
        var->text->highscore_str[i] = '\0';
    }
    sfText_setFont(var->text->highscore, var->text->font);
    sfText_setCharacterSize(var->text->highscore, 40);
    sfText_setPosition(var->text->highscore, position);
    sfText_setColor(var->text->highscore, (sfColor){92, 228, 48, 255});
    sfText_setStyle(var->text->highscore, sfTextBold);
    int_to_str(var->player->highscore, 0, var->text->highscore_str);
    sfText_setString(var->text->highscore, put_zero(var->text->highscore_str));
}

void init_text_score(var_t *var)
{
    sfVector2f position = {var->size.x - 480, var->size.y - 87};

    var->text->score = sfText_create();
    var->text->score_str = malloc(sizeof(char) * 7);
    var->text->level_str = malloc(sizeof(char) * 7);
    for (int i = 0; i <= 7; i++) {
        var->text->score_str[i] = '\0';
        var->text->level_str[i] = '\0';
    }
    sfText_setFont(var->text->score, var->text->font);
    sfText_setCharacterSize(var->text->score, 25);
    sfText_setPosition(var->text->score, position);
    sfText_setString(var->text->score, "000000");
}

void init_text_lvl(var_t *var)
{
    var->text->green = sfColor_fromRGB(130, 201, 7);
    var->text->level = sfText_create();
    var->text->round = sfText_create();
    sfText_setFont(var->text->level, var->text->font);
    sfText_setCharacterSize(var->text->level, 25);
    sfText_setColor(var->text->level, var->text->green);
    sfText_setPosition(var->text->level, (sfVector2f){420, var->size.y - 125});
    sfText_setString(var->text->level, "1");
    sfText_setFont(var->text->round, var->text->font);
    sfText_setCharacterSize(var->text->round, 60);
    sfText_setPosition(var->text->round, (sfVector2f){632, 237});
    sfText_setString(var->text->round, "1");
}

void init_text(var_t *var)
{
    var->text->font = sfFont_createFromFile("assets/font.otf");
    init_text_score(var);
    init_text_lvl(var);
    init_text_highscore(var);
}
