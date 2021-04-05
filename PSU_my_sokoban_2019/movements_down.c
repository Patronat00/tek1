/*
** EPITECH PROJECT, 2019
** movements.c
** File description:
** move player
*/

int lenght_line(char *buffer);

void movements_to_down(char *buffer)
{
    int a = 0;
    int lenght;
    char keep_position;

    lenght = lenght_line(buffer);

    while (buffer[a] != 'P')
        a = a + 1;
    if (buffer[lenght + a + 1] == '#') {

    } else if (buffer[lenght + a + 1] == 'X' && buffer[lenght + lenght + a + 2] == '#') {

    } else if (buffer[lenght + a + 1] == 'X' && buffer[lenght + lenght + a + 2] == 'X') {

    } else if (buffer[lenght + a + 1] == 'X' && buffer[lenght + a + 2] == '#') {
        buffer[a] = ' ';
        buffer[lenght + a + 1] = 'P';
        buffer[lenght + lenght + a + 2] = 'X';
    } else if (buffer[lenght + a + 1] == 'O') {
        buffer[lenght + a + 1] = 'P';
        buffer[a] = ' ';
    } else if (buffer[lenght + a + 1] == 'X' && buffer[lenght + a + 2] == ' ') {
        buffer[lenght + lenght + a + 2] = 'X';
        buffer[lenght + a + 1] = 'P';
        buffer[a] = ' ';
    } else if (buffer[lenght + a + 1] == 'X' && buffer[lenght + a + 2] == 'X') {
        buffer[lenght + lenght + a + 2] = 'X';
        buffer[lenght + a + 1] = 'P';
        buffer[a] = ' ';
    } else if (buffer[lenght + a + 1] == 'X' && buffer[lenght + a + 2] == 'O') {
        buffer[lenght + a + 2] = buffer[lenght + a + 1];
        buffer[lenght + a + 1] = ' ';
    } else if (buffer[a - lenght + 1] != 'X' || buffer[a - lenght + 2] != '#') {
        keep_position = buffer[a];
        buffer[a] = buffer[lenght + a + 1];
        buffer[lenght + a + 1] = keep_position;
    }
}
