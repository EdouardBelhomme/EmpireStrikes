/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-empirestrikes-edouard.belhomme
** File description:
** romans
*/

#include "empire.h"

void *roman_loop(roman_t *roman)
{
    int i = 0;

    while (roman->nb_max_eat > 0) {
        roman_think(roman);
        roman_eat(roman);
        roman_sleep();
    }
    pthread_exit(&i);
}
