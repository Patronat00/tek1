/*
** EPITECH PROJECT, 2019
** manual.c
** File description:
** manual -h
*/

#include <stdio.h>

void manual(void)
{
    printf("USAGE\n    ./103cipher message key flag\n");
    printf("\nDESCRIPTION\n");
    printf("    message    a message, made of ASCII characters\n");
    printf("    key        the encryption key, made of ASCII characters\n");
    printf("    flag       0 for the message to be encrypted, 1 to be decrypted\n");
}
