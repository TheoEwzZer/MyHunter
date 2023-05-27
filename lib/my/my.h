/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my
*/

#include <stdarg.h>

#ifndef MY_H_

    #define MY_H_

    int my_putchar(char c);
    int my_isneg(int nb);
    int my_put_nbr(long nb, int count);
    void my_swap(int *a, int *b);
    void my_swap_char(char **a, char **b);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    int my_strlen_double(char *const *str);
    int my_getnbr(char const *str);
    void my_sort_int_array(int *tab, int size);
    int my_compute_power_rec(int nb, int power);
    int my_compute_square_root(int nb);
    int my_is_prime(int nb);
    int my_find_prime_sup(int nb);
    char *my_strcpy(char *dest, char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_revstr(char *str);
    char *my_strstr(char *str, char const *to_find);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strupcase(char *str);
    char *my_strlowcase(char *str);
    char *my_strcapitalize(char *str);
    int my_str_isalpha(char const *str);
    int my_str_isnum(char const *str);
    int my_str_islower(char const *str);
    int my_str_isupper(char const *str);
    int my_str_isprintable(char const *str);
    int my_showstr(char *str);
    int my_showmem(char const *str, int size);
    char *my_strcat(char *dest, char const *src);
    char *my_strncat(char *dest, char const *src, int nb);

    int my_is_prime2(int nb);
    int int_at(int index, char *tab);
    long power10(int len);
    int str_to_int(char *tab, int len, int negative);
    int my_compute_square_root2(int nb);
    int my_putnbr_base(unsigned int nbr, char *base, int count);
    int middle(char *str);
    int my_swapstr(char *a, char *b);
    void hexa(int i, char *str);
    void check_separator_lower(int i, char *str);
    void check_separator_upper(int i, char *str);
    int check_isalpha(int i, char *str);
    char *my_strdup(char const *src);

    int bsq(char *filepath);
    char *increment_str1(int count, char *str_tmp);
    char *increment_str2(int count, char *str_tmp, int *j);
    int my_str_isalphanum(char c);
    char **my_str_to_word_array(char const *str);
    int getheight(char *buffer);
    int is_square_of_size2(char **map, int nb_rows, int i, int j);
    int complete_biggest_square(char **map, int max_row,
    int max_col, int max_size);
    void my_show_word_array(char *const *tab);
    char *load_file_in_memory(char const *filepath, int *height);
    int getwidth(char **map);
    int bsq_generation(char **map2d, int number);
    int generation(int number, char *pattern);
    int contain_o_or_point(char *str);
    int contain_n_occurence_of_backslah_n(char *str, int n);
    int bsq_end(char **map2d, int max_row, int max_col, int max_size);

#endif /* MY_H_ */
