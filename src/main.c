/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-empirestrikes-edouard.belhomme
** File description:
** main
*/

#include "empire.h"

int main (int ac, char **av)
{
    int nb_romans = 0;
    int nb_max_eat = 0;

    if ((ac == 2 && (strcmp(av[1], "-h") == 0)) || \
(ac == 2 && strcmp(av[1], "--help") == 0))
        return display_help();
    RCFStartup(ac, av);
    for (int i = 0; av[i] != NULL; i++) {
        if (strcmp(av[i], "-p") == 0) {
            nb_romans = atoi(av[i + 1]);
        }
        if (strcmp(av[i], "-e") == 0)
            nb_max_eat = atoi(av[i + 1]);
    }
    if (nb_romans <= 1 || nb_max_eat <= 0)
        return ERROR;
    nb_romans = empire(nb_romans, nb_max_eat);
    RCFCleanup();
    return nb_romans;
}
