/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-empirestrikes-edouard.belhomme
** File description:
** empire
*/

#ifndef EMPIRE_H_
    #define EMPIRE_H_

    #include "macros.h"
    #include "extern.h"
    #include <pthread.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdio.h>
    #include <time.h>

typedef enum roman_state_e {
    EATING,
    THINKING,
    RESTING
} roman_state_t;

typedef struct roman_s {
    int id;
    int nb_max_eat;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
} roman_t;

int display_help(void);
roman_t *init_roman(int nb_max_eat, int id, pthread_mutex_t *left_fork);
pthread_mutex_t *init_forks_mutexes(int nb_roman);
pthread_t *init_romans_threads(int nb_romans);
void roman_think(roman_t *roman);
void roman_eat(roman_t *roman);
void roman_sleep(void);
void *roman_loop(roman_t *roman);
int empire(int nb_romans, int nb_max_eat);

#endif /* !EMPIRE_H_ */
