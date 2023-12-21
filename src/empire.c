/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-empirestrikes-edouard.belhomme
** File description:
** empire
*/

#include "empire.h"

static void free_roman_and_fork(pthread_t *roman, pthread_mutex_t *fork)
{
    free(roman);
    free(fork);
}

int empire(int nb_romans, int nb_max_eat)
{
    pthread_t *roman = calloc(sizeof(pthread_t), nb_romans);
    pthread_mutex_t *fork = init_forks_mutexes(nb_romans);

    if (fork == NULL || roman == NULL)
        return 84;
    for (int i = 0; i < nb_romans - 1; i++) {
        if (pthread_create(roman + i, NULL, (void *(*)(void *))roman_loop, \
init_roman(nb_max_eat, i, &fork[i])) != 0)
            return 84;
    }
    if (pthread_create(roman + nb_romans - 1, NULL, \
(void *(*)(void *))roman_loop, init_roman(nb_max_eat, nb_romans - 1, fork)) \
!= 0)
        return 84;
    for (int i = 0; i < nb_romans; i++) {
        pthread_join(roman[i], NULL);
        pthread_mutex_destroy(&fork[i]);
    }
    free_roman_and_fork(roman, fork);
    return 0;
}
