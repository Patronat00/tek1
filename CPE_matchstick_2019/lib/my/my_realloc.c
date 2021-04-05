/*
** EPITECH PROJECT, 2020
** my_realloc.c
** File description:
** realloc fonctions
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

void *my_realloc(void *ptr, size_t size)
{
    void *eptr;

    if (ptr == NULL)
        return (malloc(size));
    eptr = malloc(size);
    if(eptr)
        my_memcpy(eptr, ptr, size);
    if(ptr)
        free(ptr);
    return eptr;
}

void *my_memcpy(void * dest, const void *src, size_t size)
{
    unsigned int count;
    const char *copy_src = src;
    char *copy_dest = dest;

    for (count = 0; count <= size; count++)
        copy_dest[count] = copy_src[count];
    return dest;
}

char *my_memcpy_toread(char *dest, const char *src, size_t size)
{
    unsigned count;
    for (count = 0; count <= size; count++)
        dest[count] = src[count];
    return dest;
}

char * my_realloc_toread(char *str, char c)
{
    char *eptr;
    int size = 0;

    while(str[size] != '\0')
        size++;
    eptr = malloc(size + 2);
    if(eptr)
        eptr = my_memcpy_toread(eptr, str, size);
    eptr = my_strcat_read(eptr, c);
    free(str);
    return eptr;
}
