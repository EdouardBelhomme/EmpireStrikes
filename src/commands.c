/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-empirestrikes-edouard.belhomme
** File description:
** commands
*/

#include "empire.h"

void roman_think(roman_t *roman)
{
    if (roman->id % 2 == 0) {
        lempire_take_fork(roman->left_fork);
        pthread_mutex_trylock(roman->left_fork);
    } else {
        lempire_take_fork(roman->right_fork);
        pthread_mutex_trylock(roman->right_fork);
    }
    lempire_think();
    usleep((rand() % 101 + 300) * 100);
}

void roman_eat(roman_t *roman)
{
    if (roman->nb_max_eat <= 0)
        return;
    if (roman->id % 2 == 0) {
        lempire_take_fork(roman->right_fork);
        pthread_mutex_trylock(roman->right_fork);
    } else {
        lempire_take_fork(roman->left_fork);
        pthread_mutex_trylock(roman->left_fork);
    }
    lempire_eat();
    usleep((rand() % 101 + 300) * 100);
    lempire_release_fork(roman->left_fork);
    lempire_release_fork(roman->right_fork);
    pthread_mutex_unlock(roman->left_fork);
    pthread_mutex_unlock(roman->right_fork);
    roman->nb_max_eat -= 1;
}

void roman_sleep(void)
{
    lempire_sleep();
}
