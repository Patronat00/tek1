/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** 02/10/19 15:36
*/

int my_putchar(char c);

int my_put_nbr1_5(int nb)
{
    int n;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        n = nb % 10;
        nb = nb / 10;
        my_put_nbr1_5(nb);
        my_putchar(n + 48);
    }
    else
        my_putchar(nb + 48);
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb == -2147483647) {
        my_putchar('-');
        my_putchar('2');
        my_put_nbr(147483647);
    } else
        my_put_nbr1_5(nb);
    return (0);
}
