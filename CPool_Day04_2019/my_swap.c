/*
** EPITECH PROJECT, 2019
** my_swap.c
** File description:
** t01D04
*/

void my_swap(int *a, int *b)

{
    int *c;
    int *d;
    int aa;
    int bb;
    
    c = &aa;
    d = &bb;
    *c = *a;
    *d = *b;
    *a = *d;
    *b = *c;

}
