/*
** EPITECH PROJECT, 2019
** rush1-1
** File description:
** rush1-1
*/

int linefillerlow(int x, int line)
{
    if(linefiller(line, x) == 1)
        my_putchar(65);
    else if (linefiller(line, x) == 2)
        my_putchar(66);
    else {
        my_putchar(67);
    }
}

int linefiller (int line, int x)
{
    if (line == 1)
        return (1);
    else if (line > 1 && line < x)
        return (2);
    else {
        return(3);
    }
}

int filler (int y, int line, int x, int column)
{
    if (column == 1) {
        if(linefiller(line, x) == 1)
            my_putchar(65);
        else if (linefiller(line, x) == 2)
            my_putchar(66);
        else {
            my_putchar(67);
        }
    }
    else if (column > 1 && column < y) {
        if(linefiller(line, x) == 1)
            my_putchar(66);
        else if (linefiller(line, x) == 2)
            my_putchar(32);
        else {
            my_putchar(66);
        }
    }
    else {
        linefillerlow(x, line);
    }
}

void rush(int x, int y)
{
    int line = 0;
    int column = 0;

    if(x <= 0 || y <=0) {
        write(2, "Invalid size \n", 13);
    }
    while(column < y) {
        column++;
        while(line < x)  {
            line++;
            if(x == 1 || y == 1) {
                my_putchar(66);
            }
            else {
                filler(y, line, x, column);
            }
        }
        line = 0;
        my_putchar('\n');
    }
}
