/*
** EPITECH PROJECT, 2019
** pushswap.h
** File description:
** pushswap.h
*/

#ifndef PUSHSWAP_H_
# define PUSHSWAP_H_

typedef struct a_list
{
  int c;
  struct a_list *next;
} a_list;

#endif

int my_getnbr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_swap(int *a, int *b);
void sa(a_list **l_a);
void pa(a_list **, a_list **);
void pb(a_list **, a_list **);
