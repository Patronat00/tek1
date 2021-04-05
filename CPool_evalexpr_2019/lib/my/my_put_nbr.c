/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** task07
*/

int my_put_nbr(int nb)
{
    int nbr = nb;
    int scal = 1;
    
    if (nb == 0) {
        my_putchar('0');
        my_putchar('\n');
        return (0);
    }
    nbrr(nb);
    nb = mot(nb);
    while (nbr != 0) {
        nbr /= 10;
        scal *= 10;
    }
    for (int a = scal / 10; a >= 1; a /= 10) {
        my_putchar('0' + (nb / a % 10));
    }
    my_putchar('\n');
    return (0);
}
