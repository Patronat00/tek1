/*
** EPITECH PROJECT, 2019
** decimal_to_binary.c
** File description:
** decimal to binary
*/

void my_putchar(char c);
int my_put_nbr(int nb);

int decimal_to_binary(int n)
{
    int binaryNum[32];
    int i = 0;
    int reverse = 0;

    while(n != 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    for(int j = i - 1; j >= 0; j--) {
        reverse << binaryNum[j];
        my_put_nbr(binaryNum[j]);
    }
    my_putchar('\n');
}
