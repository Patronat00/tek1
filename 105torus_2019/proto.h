/*
** EPITECH PROJECT, 2019
** 105torus
** File description:
** proto
*/

#ifndef PROTO_H
#define PROTO_H

int attribute_values(struct torus torus, char **av);
int bisection(struct torus torus, char **av);
int newton(struct torus torus, char **av);
void which_algo(struct torus torus, char **av);
void help(void);

#endif
