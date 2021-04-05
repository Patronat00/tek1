/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    if (nb == 2)
        return 1;
    if (nb % 2 == 0 || nb <= 1)
        return 0;
    for (int i = 2; i < nb; i++)
        if (nb % i == 0)
            return 0;
    return 1;
}
