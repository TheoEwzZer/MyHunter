/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my_hunter.h"

int help(int argc, char **argv)
{
    if (argc == 2 && !my_strcmp(argv[1], "-h")) {
        my_putstr("USAGE\n");
        my_putstr("\t./my_hunter\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("\tWelcome to 'My Hunter'.\n");
        my_putstr("\tA game where you have to shoot ducks.\n");
        my_putstr("\tYou have 3 bullets, if you miss 3 times, you lose.\n");
        my_putstr("\tYou can shoot by pressing the mouse click.\n");
        my_putstr("\tYou can move the cursor by moving your mouse.\n");
        my_putstr("\tYou can quit the game by pressing the escape key.\n");
        return 0;
    }
    return 84;
}

int main(int argc, char **argv)
{
    if (argc > 1)
        return help(argc, argv);
    var_t *var = init_var();
    sfEvent event;
    var->rect->rect1.top = 0;
    var->rect->rect1.left = 0;
    var->rect->rect1.width = 110;
    var->rect->rect1.height = 110;
    var->rect->rect2.top = 0;
    var->rect->rect2.left = 0;
    var->rect->rect2.width = 110;
    var->rect->rect2.height = 110;
    var->rect->rect3.top = 0;
    var->rect->rect3.left = 0;
    var->rect->rect3.width = 64;
    var->rect->rect3.height = 106;
    my_hunter(var, event);
    destroy(var);
    return 0;
}
