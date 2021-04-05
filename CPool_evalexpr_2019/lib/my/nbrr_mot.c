/*
** EPITECH PROJECT, 2019
** my ptnb
** File description:
** my ptnb
*/

int nbrr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb  = nb * (-1);
    }
}

int mot(int n)
{
    int res = n;
    if (n < 0) {
        res = -n;
    }
    return (res);
}
