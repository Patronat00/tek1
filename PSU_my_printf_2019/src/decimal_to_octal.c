/*
** EPITECH PROJECT, 2019
** decimal_to_octal.c
** File description:
** deimal to octal
*/

int my_put_nbr(int nb);
void my_putchar(char c);

int decimal_to_octal(int n)
{
    int octalNum[1000];
    int i = 0;
    int reverse = 0;

    while (n != 0) {
        octalNum[i] = n % 8;
        n = n / 8;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        reverse << octalNum[j];
        my_put_nbr(octalNum[j]);
    }
    my_putchar('\n');
}
