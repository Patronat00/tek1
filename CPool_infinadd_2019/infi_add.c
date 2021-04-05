/*
** EPITECH PROJECT, 2019
** infin_add.c
** File description:
** infin-add
*/

#include <unistd.h>

int my_put_nbr(int nb);
void my_putchar(char c);


int main (int argc, char **argv)
{
    int result = 0;
    char *t = argv[1];
    
    if (t[0] != '-' && t[2] != '-'){
        for (int temporary = 1; argv[temporary] != '\0'; temporary++) {
            
            t[0] = t[0] - 48;
            t[2] = t[2] - 48;
            result = t[0] + t[2];
            my_put_nbr(result);
            my_putchar('\n');
            return (result);
        }
    }
    
    if (t[0] - 48 < 0 || t[2] - 48 < 0) {
        
        t[0] = t[0] - 48;
        t[2] = t[2] - 48;
        result = t[0] + t[2];
        my_putchar("-");
        my_put_nbr(result);
        my_putchar('\n');
        return (result);
    }
}
