/*
** EPITECH PROJECT, 2022
** highscore.c
** File description:
** highscore
*/

#include "my_hunter.h"

void save_highscore(var_t *var)
{
    FILE *fp = fopen("high_score.txt", "w");
    size_t len = my_strlen(var->text->highscore_str);

    if (!fp)
        return;
    fwrite(var->text->highscore_str, len, sizeof(char), fp);
    fclose(fp);
}

void read_highscore(var_t *var)
{
    FILE *fp = fopen("high_score.txt", "r");
    char *line = NULL;
    size_t len = 0;

    if (!fp) {
        fp = fopen("high_score.txt", "w");
        var->player->highscore = 0;
    }
    while (getline(&line, &len, fp) != -1) {
        var->player->highscore = my_getnbr(line);
    }
    fclose(fp);
}
