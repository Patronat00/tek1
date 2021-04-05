/*
** EPITECH PROJECT, 2019
** my_show_word_array.c
** File description:
** task03_Day09
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_show_word_array(char * const *tab)
{
    int i = 0;
    char oui [] = "bonjour la populasse";
    
    while (oui[i] != '\0')
    {
        if (oui[i] == " ") {
            my_putchar('\n');
        }
        my_putchar(oui[i]);
        i++;
    }
}

int main ()
{
    char *test_word_array [] = {"the", "greatest", 0};
    
    my_show_word_array(test_word_array);
}

