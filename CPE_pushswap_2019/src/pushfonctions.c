/*
** EPITECH PROJECT, 2019
** pushfonctions.c
** File description:
** fonctions for pushswap
*/

#include<stdlib.h>
#include"../include/pushswap.h"

a_list *add_the_list(a_list *lists, int i)
{
    a_list *abc;

    abc = malloc(sizeof(a_list));
    abc->c = i;
    abc->next = lists;
    lists = abc;
    return (lists);
}

void pa(a_list **l_a, a_list **l_b)
{
    int i;

    if (*l_b == NULL)
        return;
    i = (*l_b)->c;
    *l_a = add_the_list(*l_a, i);
    *l_b = (*l_b)->next;
    my_putstr("pa ");
}

void pb(a_list **l_a, a_list **l_b)
{
    int i;

    if (*l_a == NULL)
        return;
    i = (*l_a)->c;
    *l_b = add_the_list(*l_b, i);
    *l_a = (*l_a)->next;
    my_putstr("pb ");
}

void sa(a_list **l_a)
{
    a_list *abc;

    abc = *l_a;
    abc = abc->next;
    (*l_a)->next = abc->next;
    abc->next = *l_a;
    *l_a = abc;
    my_putstr("sa ");
}
