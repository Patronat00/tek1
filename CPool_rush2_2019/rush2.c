/*
** EPITECH PROJECT, 2019
** rush2
** File description:
**
*/

void frequencies(int sl, int count)
{
    float f;

    f = ((count / sl) * 100);
    my_putchar(' ');
    my_putchar('(');
    my_put_nbr(f);
    my_putchar('%');
    my_putchar(')');
}

void counting_occurence(char *st, char l)
{
    int counter = 0;
    int sl = my_strlen(st);

    for (int i = 0; st[i] != '\0'; i++) {

        if (st[i] == l || st[i] == l + 32 || st[i] == l - 32 && st[i] != 33) {
            counter++;
        }
    }
    my_putchar(l);
    my_putchar(':');
    my_put_nbr(counter);
    frequencies(sl, counter);
    my_putchar('\n');
}

int main(int argc, char **argv)
{
    char *sent = argv[1];

    if (argv[1][0] == '\0') {
        write(2, "Syntax Error", 13);
        my_putchar('\n');
        return (84);
    }

    for (int t = 2; t != argc; t++){

        char l = argv[t] [0];
        counting_occurence(sent, l);
    }

    return (0);
}
