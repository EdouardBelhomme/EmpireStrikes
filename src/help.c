/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-empirestrikes-edouard.belhomme
** File description:
** help
*/

#include "macros.h"
#include <stdio.h>

int display_help(void)
{
    printf("USAGE\n");
    printf("\t./empire -p nbr_p -e nbr_e\n");
    printf("DESCRIPTION\n");
    printf("\t-p nbr_p\tnumber of romans\n");
    printf("\t-e nbr_e\tmaximum number times a roman eats before\n");
    printf("\texiting the program\n");
    return SUCCESS;
}
