/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** my_find_prime_sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    long i = nb;

    if (nb < 2)
        return 2;
    for (; i >= nb; i++) {
        if (i > __INT_MAX__)
            return 0;
        if (my_is_prime(i) == 1)
            return i;
    }
    return 0;
}
