/*
** EPITECH PROJECT, 2020
** environement.h
** File description:
**  minishell
*/

#ifndef ENVIRONMENT_H_
# define ENVIRONMENT_H_

char **copy_env(char **env, char **overwrite);
char **get_paths(char **env);
#endif