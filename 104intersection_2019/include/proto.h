/*
** EPITECH PROJECT, 2019
** 104intersection
** File description:
** proto
*/

#ifndef PROTO_H
#define PROTO_H

int calcul_sphere(struct intersection intersection, char **av);
int calcul_cylinder(struct intersection intersection, char **av);
int calcul_cone(struct intersection intersection , char **av);
void which_calc(struct intersection intersection, char **av);
void delta_positive(struct intersection intersection);
void delta_null(struct intersection intersection);
void delta_negative(struct intersection intersection);
void help(void);

#endif
