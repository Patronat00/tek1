/*
** EPITECH PROJECT, 2019
** pushswap.c
** File description:
** pushswap
*/

#include<stdlib.h>
#include<stdio.h>
#include"../include/pushswap.h"

void show_lists(a_list **lists)
{
    a_list *abc;

    abc = *lists;
    while (abc != NULL) {
        my_put_nbr(abc->c);
        my_putchar(' ');
        abc = abc->next;
    }
    my_putchar('\n');
}

void swap_a_and_b(a_list **l_a, a_list **l_b)
{
    a_list *abc;
    int n;

    n = 1;
    while (n == 1) {
        n = 0;
        abc = *l_a;
        while ((*l_a)->next != NULL) {
            if ((*l_a)->c > (*l_a)->next->c)
            {
                sa(l_a);
                n = 1;
            }
            pb(l_a, l_b);
            abc = abc->next;
        }
        while (*l_b != NULL)
            pa(l_a, l_b);
    }
}

void check_the_lists(a_list **l_a, a_list **l_b, int ac)
{
    a_list	*abc;
    int		def;
    int		n;

    abc = *l_a;
    n = 0;
    def = ac - 2;
    while (abc->next != NULL && abc->c < abc->next->c)
    {
        n++;
        abc = abc->next;
    }
    if (n == def){

    }
    else
        swap_a_and_b(l_a, l_b);
}

a_list *my_put_in_list(a_list *lists, int nb)
{
    a_list *things;
    a_list *abc;

    things = malloc(sizeof(a_list));
    things->c = nb;
    things->next = NULL;
    if (lists == NULL)
        return (things);
    abc = lists;
    while (abc->next != NULL)
        abc = abc->next;
    abc->next = things;
    return (lists);
}

int	main(int ac, char **av)
{
    a_list *l_a;
    a_list *l_b;
    int n;
    int i;

    l_a = NULL;
    l_b = NULL;
    n = 0;
    if (ac < 3)
        return (0);
    while (av[++n] != NULL)
    {
        i = my_getnbr(av[n]);
        l_a = my_put_in_list(l_a, i);
    }
    check_the_lists(&l_a, &l_b, ac);
    my_putchar('\n');
    return (0);
}
