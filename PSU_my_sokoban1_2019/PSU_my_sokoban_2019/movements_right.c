/*
** EPITECH PROJECT, 2019
** movements_forward.c
** File description:
** move forward
*/

void movements_to_right(char *buffer) {
    int a = 0;
    char keep_position;

    while (buffer[a] != 'P')
        a = a + 1;
    if (buffer[a + 1] == '#') {

    }
    else if (buffer[a + 1] == 'X' && buffer[a + 2] == ' ') {
        keep_position = buffer[a + 2];
        buffer[a + 2] = buffer[a + 1];
        buffer[a + 1] = keep_position;
    }
    else if (buffer[a + 1] == 'X' && buffer[a + 2] == 'O') {
        buffer[a + 2] = buffer[a + 1];
        buffer[a + 1] = buffer[a - 1];
    }
    else if (buffer[a + 1] != 'X' || buffer[a + 2] != '#') {
        if (buffer[a] == 'P' && buffer[a + 1] == 'O') {
            buffer[a + 1] = ' ';
        }
        else {
            keep_position = buffer[a + 1];
            buffer[a + 1] = buffer[a];
            buffer[a] = keep_position;
        }
    }
}
