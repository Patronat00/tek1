/*
** EPITECH PROJECT, 2020
** builtin.h
** File description:
**  minishell
*/

#ifndef BUILTIN_H_
# define BUILTIN_H_

# include "minishell.h"

void	cd_alt(t_shell *shell, char **args);
void	env_alt(t_shell *shell, char **args);
void	setenv_alt(t_shell *shell, char **args);
void	unsetenv_alt(t_shell *shell, char **args);
void	exit_alt(t_shell *shell, char **args);
#endif