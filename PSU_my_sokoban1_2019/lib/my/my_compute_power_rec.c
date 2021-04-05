/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** my_compute_power_rec
*/

static int recursiv(int nb, int p, int base)
{
    if (p > 1) {
        if ((long)nb * base < 2147483647) {
            nb *= base;
            return recursiv(nb, p - 1, base);
        }
        else
            return 0;
    }
    return nb;
}

int my_compute_power_rec(int nb, int p)
{
    int base = nb;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    nb = recursiv(nb, p, base);
    return nb;
}
