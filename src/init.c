/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-empirestrikes-edouard.belhomme
** File description:
** init
*/

#include "empire.h"

roman_t *init_roman(int nb_max_eat, int id, pthread_mutex_t *left_fork)
{
    roman_t *roman = NULL;

    if (!(roman = calloc(sizeof(roman_t), 1)))
        return NULL;
    roman->id = id;
    roman->nb_max_eat = nb_max_eat;
    roman->left_fork = left_fork;
    roman->right_fork = left_fork + 1;
    return roman;
}

pthread_mutex_t *init_forks_mutexes(int nb_roman)
{
    pthread_mutex_t *fork = NULL;

    if (!(fork = calloc(sizeof(pthread_mutex_t), nb_roman)))
        return NULL;
    for (int i = 0; i < nb_roman; ++i) {
        if (pthread_mutex_init(fork, NULL) != 0)
            return NULL;
    }
    return fork;
}
